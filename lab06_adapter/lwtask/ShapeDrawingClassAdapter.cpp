#include "ShapeDrawingClassAdapter.h"



CShapeDrawingClassAdapter::CShapeDrawingClassAdapter(std::ostream& outputStream)
	: CModernGraphicsRenderer(outputStream)
{
}


CShapeDrawingClassAdapter::~CShapeDrawingClassAdapter()
{
}

void CShapeDrawingClassAdapter::MoveTo(int x, int y)
{
	m_currentPoint = { x, y };
}

void CShapeDrawingClassAdapter::LineTo(int x, int y)
{
	DrawLine(m_currentPoint, { x, y }, m_color);
	MoveTo(x, y);
}

void CShapeDrawingClassAdapter::SetColor(uint32_t rgbColor)
{
	m_color.r = (float)((rgbColor >> 16) & 0xff) / 255;
	m_color.g = (float)((rgbColor >> 8) & 0xff) / 255;
	m_color.b = (float)((rgbColor) & 0xff) / 255;
	m_color.a = 1.0;
}

void CShapeDrawingClassAdapter::BeginDraw()
{
	CModernGraphicsRenderer::BeginDraw();
}

void CShapeDrawingClassAdapter::EndDraw()
{
	CModernGraphicsRenderer::EndDraw();
}
