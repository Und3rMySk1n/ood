#include "SVGCanvas.h"

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
		CSVGCanvas::OpenPath();
	}

	m_output << "M " << x << "," << y << " ";
}

void CSVGCanvas::LineTo(double x, double y)
{
	if (!m_pathOpened)
	{
		CSVGCanvas::OpenPath();
	}

	m_output << "L " << x << "," << y << " ";
}

void CSVGCanvas::DrawEllipse(double left, double top, double width, double height)
{

}

void CSVGCanvas::OpenPath()
{
	m_pathOpened = true;
	m_output << "<path stroke=\"black\" stroke-width=\"" << m_lineWidth << "\" d=\"";
}

void CSVGCanvas::ClosePath()
{
	m_output << "\" />" << endl;
	m_pathOpened = false;
}