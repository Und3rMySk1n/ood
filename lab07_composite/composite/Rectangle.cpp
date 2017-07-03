#include "Rectangle.h"


CRectangle::CRectangle(Vertex leftTop, Vertex rightBottom)
	: m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}


CRectangle::~CRectangle()
{
}

void CRectangle::Draw(ICanvas & canvas)
{
	SetCanvasStyles(canvas);
	canvas.MoveTo(m_leftTop.x, m_leftTop.y);
	canvas.LineTo(m_rightBottom.x, m_leftTop.y);
	canvas.LineTo(m_rightBottom.x, m_rightBottom.y);
	canvas.LineTo(m_leftTop.x, m_rightBottom.y);
	canvas.LineTo(m_leftTop.x, m_leftTop.y);
}

RectD CRectangle::GetFrame()
{
	return m_frame;
}

void CRectangle::SetFrame(const RectD & rect)
{
	m_frame = rect;
}