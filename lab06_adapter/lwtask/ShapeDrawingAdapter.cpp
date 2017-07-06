#pragma once
#include <iostream>
#include "ShapeDrawingAdapter.h"

using namespace std;

namespace shape_drawing_adapter
{
	CCanvasAdapter::CCanvasAdapter(modern_graphics_lib::CModernGraphicsRenderer & renderer)
		: m_renderer(&renderer)
	{
	}

	void CCanvasAdapter::SetColor(uint32_t rgbColor)
	{
		m_color.r = (float)((rgbColor >> 16) & 0xff) / 255;
		m_color.g = (float)((rgbColor >> 8) & 0xff) / 255;
		m_color.b = (float)((rgbColor) & 0xff) / 255;
		m_color.a = 1.0;
	}

	void CCanvasAdapter::MoveTo(int x, int y)
	{
		m_currentPoint.x = x;
		m_currentPoint.y = y;
	}

	void CCanvasAdapter::LineTo(int x, int y)
	{
		modern_graphics_lib::CPoint newPoint = {x, y};
		m_renderer->DrawLine(m_currentPoint, newPoint, m_color);
		MoveTo(x, y);
	}
}