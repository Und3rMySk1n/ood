
// MainDlg.h : header file
//
#pragma once

#include "Signals.h"

class CEquationSolver;
class IMainDlgController;

class CMainDlg : public CDialogEx
{
public:
	CMainDlg(CEquationSolver & solver, IMainDlgController & controller, CWnd* pParent = NULL);	// standard constructor

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODELVIEWCONTROLLER_DIALOG };
#endif

protected:
	BOOL PreTranslateMessage(MSG *msg) override;
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
private:
	void SetEquationText(const std::wstring & text);
	void SetRadioChangeText(const std::wstring & text);
	void UpdateEquation();
	void OnChangeCoeffA();
	void OnChangeCoeffB();
	void OnChangeCoeffC();
	void DrawChart();

	void OnOK()final;

	afx_msg void OnKillfocusCoeffA();
	afx_msg void OnKillfocusCoeffB();
	afx_msg void OnKillfocusCoeffC();
	afx_msg void OnRadio1Clicked();
	afx_msg void OnRadio2Clicked();

	sig::scoped_connection m_solutionChangeConnection;
	IMainDlgController & m_controller;
	CEquationSolver & m_solver;
	CStatic m_drawArea;

	double m_coeffA = 0;
	double m_coeffB = 0;
	double m_coeffC = 0;
	double m_horizontalLimit = 5;
	double m_detalization = 100;
	
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
