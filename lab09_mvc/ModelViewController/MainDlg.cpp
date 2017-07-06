
// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MVCApp.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "EquationSolver.h"
#include "IMainDlgController.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMainDlg::CMainDlg(CEquationSolver & solver, IMainDlgController & controller, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MODELVIEWCONTROLLER_DIALOG, pParent)
	, m_controller(controller)
	, m_solver(solver)
	, m_coeffA(solver.GetQuadraticCoeff())
	, m_coeffB(solver.GetLinearCoeff())
	, m_coeffC(solver.GetConstantCoeff())
	, m_drawArea()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

BOOL CMainDlg::PreTranslateMessage(MSG * msg)
{
	if (msg->message == WM_KEYDOWN && msg->wParam == VK_RETURN)
	{
		auto focus = GetFocus();
		if (focus == GetDlgItem(IDC_COEFF_A))
		{
			OnChangeCoeffA();
			return TRUE;
		}
		else if (focus == GetDlgItem(IDC_COEFF_B))
		{
			OnChangeCoeffB();
			return TRUE;
		}
		else if (focus == GetDlgItem(IDC_COEFF_C))
		{
			OnChangeCoeffC();
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(msg);
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COEFF_A, m_coeffA);
	DDX_Text(pDX, IDC_COEFF_B, m_coeffB);
	DDX_Text(pDX, IDC_COEFF_C, m_coeffC);
	DDX_Control(pDX, IDC_GRAPH, m_drawArea);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_EN_KILLFOCUS(IDC_COEFF_A, &CMainDlg::OnKillfocusCoeffA)
	ON_EN_KILLFOCUS(IDC_COEFF_B, &CMainDlg::OnKillfocusCoeffB)
	ON_EN_KILLFOCUS(IDC_COEFF_C, &CMainDlg::OnKillfocusCoeffC)
	ON_BN_CLICKED(IDC_RADIO1, &CMainDlg::OnRadio1Clicked)
	ON_BN_CLICKED(IDC_RADIO2, &CMainDlg::OnRadio2Clicked)
END_MESSAGE_MAP()


BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_solutionChangeConnection = m_solver.DoOnSolutionChange([=] {
		UpdateEquation();
	});

	UpdateEquation();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMainDlg::SetSolutionText(const std::wstring & text)
{
	SetDlgItemText(IDC_SOLUTION, text.c_str());
}

void CMainDlg::SetEquationText(const std::wstring & text)
{
	SetDlgItemText(IDC_EQUATION, text.c_str());
}

void CMainDlg::SetRadioChangeText(const std::wstring & text)
{
	SetDlgItemText(IDC_TEST_STATIC, text.c_str());
}

void CMainDlg::DrawChart()
{
	//—оздаем контекст, в котором будем рисовать
	CClientDC dc(&m_drawArea);

	//”знаем размеры пр€моугольника
	CRect rc;
	m_drawArea.GetClientRect(&rc);
	int w = rc.Width();
	int h = rc.Height();

	int x_start = 10;
	int y_start = h - 10;

	//–исуем Е
	CPen pnPenBlack(PS_SOLID, 1, RGB(0, 0, 0));
	CPen * pOldPen = dc.SelectObject(&pnPenBlack);
	dc.FillSolidRect(rc, RGB(255, 255, 255));
	dc.MoveTo(x_start - 5, y_start);
	dc.LineTo(x_start + w - 15, y_start);
	dc.MoveTo(x_start, y_start + 5);
	dc.LineTo(x_start, y_start - h + 15);
	CPen pnPenRed(PS_SOLID, 1, RGB(255, 0, 0));
	dc.SelectObject(&pnPenRed);
	dc.MoveTo(x_start, y_start);
	for (int i = 3; i < w - x_start - 2; i += 3)
	{
		dc.LineTo(x_start + i, y_start - int(h / 3 * (1 - sin((float)i))));
	}
	dc.SelectObject(pOldPen);

	SetRadioChangeText((boost::wformat(L"Width: %1% Height: %2%") % w % h).str());
}

void CMainDlg::UpdateEquation()
{
	auto solution = m_solver.GetEquationRoots();
	struct SolutionPrinter : boost::static_visitor<void>
	{
		CMainDlg & self;
		SolutionPrinter(CMainDlg &self)
			:self(self)
		{
		}
		void operator()(NoRealRoots)
		{
			self.SetSolutionText(L"No real roots");
		}
		void operator()(InfiniteNumberOfRoots)
		{
			self.SetSolutionText(L"Infinite number of roots");
		}
		void operator()(double root)
		{
			self.SetSolutionText((boost::wformat(L"One root: %1%") % root).str());
		}
		void operator()(const std::pair<double, double> & roots)
		{
			self.SetSolutionText((boost::wformat(L"Two roots: %1% and %2%") % roots.first % roots.second).str());
		}
	};

	SolutionPrinter printer(*this);
	solution.apply_visitor(printer);

	auto ToSignedString = [](double value) {
		std::wostringstream strm;
		strm << std::abs(value);

		return ((value < 0) ? L"- " : L"+ ") + strm.str();
	};

	SetEquationText((boost::wformat(L"%1%x\u00b2 %2%x %3% = 0") % m_solver.GetQuadraticCoeff() % ToSignedString(m_solver.GetLinearCoeff()) % ToSignedString(m_solver.GetConstantCoeff())).str());
	DrawChart();
}

void CMainDlg::OnChangeCoeffA()
{
	if (UpdateData())
	{
		m_controller.SetCoeffA(m_coeffA);
	}
}

void CMainDlg::OnChangeCoeffB()
{
	if (UpdateData())
	{
		m_controller.SetCoeffB(m_coeffB);
	}
}

void CMainDlg::OnChangeCoeffC()
{
	if (UpdateData())
	{
		m_controller.SetCoeffC(m_coeffC);
	}
}

void CMainDlg::OnOK()
{
}

void CMainDlg::OnKillfocusCoeffA()
{
	OnChangeCoeffA();
}

void CMainDlg::OnKillfocusCoeffB()
{
	OnChangeCoeffB();
}

void CMainDlg::OnKillfocusCoeffC()
{
	OnChangeCoeffC();
}


void CMainDlg::OnRadio1Clicked()
{
	SetRadioChangeText(L"Option radio one!");
	UpdateEquation();
}


void CMainDlg::OnRadio2Clicked()
{
	SetRadioChangeText(L"Option radio two!");
	UpdateEquation();
}
