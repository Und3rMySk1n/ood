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

size_t CSlide::GetShapesCount()const
{
	return m_shapes.size();
}

void CSlide::InsertShape(const std::shared_ptr<IShape> & shape)
{
	m_shapes.push_back(shape);
}

std::shared_ptr<IShape> CSlide::GetShapeAtIndex(size_t index)
{
	return m_shapes.at(index);
}

void CSlide::RemoveShapeAtIndex(size_t index)
{
	if (index >= m_shapes.size())
	{
		throw std::out_of_range("There is no shape with this index.");
	}

	m_shapes.erase(m_shapes.begin() + index);
}

void CSlide::Draw(ICanvas & canvas)
{
	for (auto shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}