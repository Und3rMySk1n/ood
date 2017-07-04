#include "Slide.h"

double CSlide::GetWidth()const
{
	RectD frame = m_shapes.GetFrame();
	return frame.width;
}

double CSlide::GetHeight() const
{
	RectD frame = m_shapes.GetFrame();
	return frame.height;
}

IShapes & CSlide::GetShapes()
{
	return m_shapes;
}

void CSlide::Draw(ICanvas & canvas)
{
	m_shapes.Draw(canvas);
}