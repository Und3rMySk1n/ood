#pragma once
#include "ShapeDrawingLib.h"

namespace shape_drawing_lib
{
	CTriangle::CTriangle(const Point & p1, const Point & p2, const Point & p3)
		: m_pOne(p1)
		, m_pTwo(p2)
		, m_pThree(p3)
	{
	}

	void CTriangle::Draw(graphics_lib::ICanvas & canvas)const
	{
		canvas.MoveTo(m_pOne.x, m_pOne.y);
		canvas.LineTo(m_pTwo.x, m_pTwo.y);
		canvas.LineTo(m_pThree.x, m_pThree.y);
		canvas.LineTo(m_pOne.x, m_pOne.y);
	}

	CRectangle::CRectangle(const Point & leftTop, int width, int height)
	{
		m_leftTop = leftTop;
		m_rightBottom = { leftTop.x + width, leftTop.y + height };
	}

	void CRectangle::Draw(graphics_lib::ICanvas & canvas)const
	{
		canvas.MoveTo(m_leftTop.x, m_leftTop.y);
		canvas.LineTo(m_rightBottom.x, m_leftTop.y);
		canvas.LineTo(m_rightBottom.x, m_rightBottom.y);
		canvas.LineTo(m_leftTop.x, m_rightBottom.y);
		canvas.LineTo(m_leftTop.x, m_leftTop.y);
	}

	CCanvasPainter::CCanvasPainter(graphics_lib::ICanvas & canvas)
		: m_canvas(&canvas)
	{
	}

	void CCanvasPainter::Draw(const ICanvasDrawable & drawable)
	{
		drawable.Draw(*m_canvas);
	}
}