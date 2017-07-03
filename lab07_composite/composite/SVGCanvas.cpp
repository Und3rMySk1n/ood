#include "SVGCanvas.h"
#include <iomanip>

using namespace std;

CSVGCanvas::CSVGCanvas(std::ostream & ostream)
	: m_output(ostream)
{
	m_output << "<svg version = \"1.1\" xmlns = \"http://www.w3.org/2000/svg\">" << endl;
}

CSVGCanvas::~CSVGCanvas()
{
	if (m_pathOpened)
	{
		CSVGCanvas::ClosePath();
	}

	m_output << "</svg>";
}


void CSVGCanvas::SetLineColor(RGBAColor color)
{
	m_lineColor = color;
	ClosePath();
}

void CSVGCanvas::BeginFill(RGBAColor color)
{

}

void CSVGCanvas::EndFill()
{

}

void CSVGCanvas::MoveTo(double x, double y)
{
	if (!m_pathOpened)
	{
		OpenPath();
	}

	m_output << "M " << x << "," << y << " ";
}

void CSVGCanvas::LineTo(double x, double y)
{
	if (!m_pathOpened)
	{
		MoveTo(0, 0);
	}

	m_output << "L " << x << "," << y << " ";
}

void CSVGCanvas::DrawEllipse(double left, double top, double width, double height)
{
	if (m_pathOpened)
	{
		ClosePath();
	}

	m_output << " <ellipse ";
	PrintLineStyle();
	m_output << " cx=\"" << left << "\" cy=\"" << top << "\" rx=\"" << width << "\" ry=\"" << height << "\" />" << endl;
}

void CSVGCanvas::OpenPath()
{
	m_pathOpened = true;
	m_output << "<path ";
	PrintLineStyle();
	m_output << "d=\"";
}

void CSVGCanvas::ClosePath()
{
	if (m_pathOpened)
	{
		m_output << "\" />" << endl;
		m_pathOpened = false;
	}
}

void CSVGCanvas::PrintLineStyle()
{
	m_output << "stroke=\"#" << std::setfill('0') << std::setw(6) << std::hex << m_lineColor << "\" stroke-width=\"" << m_lineWidth << "\" ";
}