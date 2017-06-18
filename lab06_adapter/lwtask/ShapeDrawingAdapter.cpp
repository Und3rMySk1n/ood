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

	void CCanvasAdapter::MoveTo(int x, int y)
	{
		m_currentPoint.x = x;
		m_currentPoint.y = y;
	}

	void CCanvasAdapter::LineTo(int x, int y)
	{
		modern_graphics_lib::CPoint newPoint = {x, y};
		m_renderer->DrawLine(m_currentPoint, newPoint);
		MoveTo(x, y);
	}
}