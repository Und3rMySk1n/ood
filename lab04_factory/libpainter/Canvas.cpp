#include "stdafx.h"
#include "Canvas.h"
#include <sstream>

using namespace std;

void CCanvas::SetColor(Color color)
{
	m_color = color;
}

void CCanvas::DrawLine(const Vertex from, const Vertex to)
{
	stringstream newLine;
	string newLineAsString;

	m_output << "Line: [" << from.x << ", " << from.y << "], [" << to.x << ", " << to.y << "]\n";
}

void CCanvas::DrawEllipse(const Vertex center, float width, float height)
{
	stringstream newLine;
	string newLineAsString;

	m_output << "Ellipse: [" << center.x << ", " << center.y << "], Width: " << width << ", Height: " << height << "\n";
}

void CCanvas::BeginDraw()
{
}

void CCanvas::EndDraw()
{
}
