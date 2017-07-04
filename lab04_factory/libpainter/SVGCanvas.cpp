#include "stdafx.h"
#include "SVGCanvas.h"
#include "Utils.h"

using namespace std;

CSVGCanvas::CSVGCanvas(ostream & ostream)
	: m_output(ostream)
{
	m_output << "<svg version = \"1.1\" xmlns = \"http://www.w3.org/2000/svg\">" << endl;
}


CSVGCanvas::~CSVGCanvas()
{
	if (m_pathOpened)
	{
		CSVGCanvas::EndDraw();
	}

	m_output << "</svg>";
}

void CSVGCanvas::SetColor(Color color)
{
	m_color = color;
}

void CSVGCanvas::DrawEllipse(const Vertex center, float width, float height)
{
	if (m_pathOpened)
	{
		EndDraw();
	}

	m_output << " <ellipse";
	PrintStyle();
	m_output << " cx=\"" << center.x << "\" cy=\"" << center.y << "\" rx=\"" << width << "\" ry=\"" << height << "\" />" << endl;
}

void CSVGCanvas::DrawLine(const Vertex from, const Vertex to)
{
	if (m_lastVertex.x != from.x || m_lastVertex.y != from.y)
	{
		m_output << "M " << from.x << "," << from.y << " ";
	}
	m_output << "L " << to.x << "," << to.y << " ";

	m_lastVertex = to;
}

void CSVGCanvas::BeginDraw()
{
	m_pathOpened = true;
	m_output << "<path";
	PrintStyle();
	m_output << " d=\"";
}

void CSVGCanvas::EndDraw()
{
	if (m_pathOpened)
	{
		m_output << "\" />" << endl;
		m_pathOpened = false;
	}
}

void CSVGCanvas::PrintStyle()
{
	m_output << " stroke=\"" << ColorAsString(m_color) << "\" stroke-width=\"" << m_lineWidth << "\"";
	m_output << " fill=\"" << ColorAsString(m_color) << "\"";
}