#include "stdafx.h"
#include "Canvas.h"
#include <sstream>

using namespace std;

CCanvas::CCanvas()
{
}

void CCanvas::SetColor(Color color)
{
	m_color = color;
}

void CCanvas::DrawLine(const Vertex from, const Vertex to)
{
	stringstream newLine;
	string newLineAsString;

	newLine << "Line: [" << from.x << ", " << from.y << "], [" << to.x << ", " << to.y << "]\n";
	newLineAsString = newLine.str();

	m_canvasContent += newLineAsString;
}

void CCanvas::DrawEllipse(const Vertex center, float width, float height)
{
	stringstream newLine;
	string newLineAsString;

	newLine << "Ellipse: [" << center.x << ", " << center.y << "], Width: " << width << ", Height: " << height << "\n";
	newLineAsString = newLine.str();

	m_canvasContent += newLineAsString;
}

string CCanvas::GetCanvasContent() const
{
	return m_canvasContent;
}

CCanvas::~CCanvas()
{
}
