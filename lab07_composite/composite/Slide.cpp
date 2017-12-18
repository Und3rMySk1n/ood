#include "Slide.h"
#include <algorithm>

double CSlide::GetWidth()const
{
	if (m_shapes.empty())
	{
		return 0.0;
	}

	RectD firstFrame = m_shapes.at(0)->GetFrame();
	double xMin = firstFrame.left;
	double xMax = firstFrame.left + firstFrame.width;

	for (auto shape : m_shapes)
	{
		RectD frame = shape->GetFrame();
		xMin = std::min(xMin, frame.left);
		xMax = std::max(xMax, frame.left + frame.width);
	}

	return xMax - xMin;
}

double CSlide::GetHeight() const
{
	if (m_shapes.empty())
	{
		return 0.0;
	}

	RectD firstFrame = m_shapes.at(0)->GetFrame();
	double yMin = firstFrame.top;
	double yMax = firstFrame.top + firstFrame.height;

	for (auto shape : m_shapes)
	{
		RectD frame = shape->GetFrame();
		yMin = std::min(yMin, frame.top);
		yMax = std::max(yMax, frame.top + frame.height);
	}

	return yMax - yMin;
}

void CSlide::Draw(ICanvas & canvas)
{
	for (auto shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}