#pragma once
#include "ShapeDrawingLib.h"

namespace shape_drawing_lib
{
	void CTriangle::Draw(graphics_lib::ICanvas & canvas)const
	{
		canvas.MoveTo(m_pOne.x, m_pOne.y);
		canvas.LineTo(m_pTwo.x, m_pTwo.y);
		canvas.LineTo(m_pThree.x, m_pThree.y);
		canvas.LineTo(m_pOne.x, m_pOne.y);
	}
}