#include "GroupShape.h"

using namespace std;

void CGroupShape::Draw(ICanvas & canvas)
{
	for (auto shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}

shared_ptr<IStyle> CGroupShape::GetOutlineStyle()
{
	return CalculateOutlineStyle();
}

const shared_ptr<IStyle> CGroupShape::GetOutlineStyle()const
{
	return CalculateOutlineStyle();
}

shared_ptr<IStyle> CGroupShape::GetFillStyle()
{
	return CalculateFillStyle();
}

const shared_ptr<IStyle> CGroupShape::GetFillStyle()const
{
	return CalculateFillStyle();
}

shared_ptr<IGroupShape> CGroupShape::GetGroup()
{
	return make_shared<CGroupShape>(*this);
}

shared_ptr<const IGroupShape> CGroupShape::GetGroup() const
{
	return make_shared<CGroupShape>(*this);
}

void CGroupShape::InsertShape(const std::shared_ptr<IShape> & shape)
{
	m_shapes.push_back(shape);
	CalculateFrame();
}

shared_ptr<IShape> CGroupShape::GetShapeAtIndex(size_t index)
{
	return m_shapes.at(index);
}

void CGroupShape::RemoveShapeAtIndex(size_t index)
{
	if (index >= m_shapes.size())
	{
		throw out_of_range("There is no shape with this index.");
	}

	m_shapes.erase(m_shapes.begin() + index);
	CalculateFrame();
}

size_t CGroupShape::GetShapesCount()const
{
	return m_shapes.size();
}

RectD CGroupShape::GetFrame()const
{
	return m_frame;
}

void CGroupShape::SetFrame(const RectD & rect)
{
	RectD oldFrame = GetFrame();
	for (auto &shape : m_shapes)
	{
		RectD shapeFrame = shape->GetFrame();
		shapeFrame.left = rect.left + (shapeFrame.left - oldFrame.left) / (oldFrame.width / rect.width);
		shapeFrame.top = rect.top + (shapeFrame.top - oldFrame.top) / (oldFrame.height / rect.height);
		shapeFrame.width = shapeFrame.width * (rect.width / oldFrame.width);
		shapeFrame.height = shapeFrame.height * (rect.height / oldFrame.height);
		shape->SetFrame(shapeFrame);
	}

	CalculateFrame();
}

void CGroupShape::CalculateFrame()
{
	if (GetShapesCount() == 0)
	{
		m_frame = { 0, 0, 0, 0 };
	}
	else
	{
		RectD const &firstFrame = GetShapeAtIndex(0)->GetFrame();

		double minX = firstFrame.left;
		double minY = firstFrame.top;
		double maxX = minX + firstFrame.width;
		double maxY = minY + firstFrame.height;

		for (auto const &shape : m_shapes)
		{
			RectD const &frame = shape->GetFrame();
			minX = min(minX, frame.left);
			minY = min(minY, frame.top);
			maxX = max(maxX, frame.left + frame.width);
			maxY = max(maxY, frame.top + frame.height);
		}

		m_frame = { minX, minY, maxX - minX, maxY - minY };
	}
}

shared_ptr<IStyle> CGroupShape::CalculateOutlineStyle()const
{
	if (m_shapes.empty())
	{
		return nullptr;
	}

	bool sameStyle = true;
	auto &style = m_shapes.at(0)->GetOutlineStyle();

	for (auto & shape : m_shapes)
	{
		auto shapeStyle = shape->GetOutlineStyle();
		if (shapeStyle->GetColor() != style->GetColor() || shapeStyle->IsEnabled() != style->IsEnabled())
		{
			sameStyle = false;
			break;
		}
	}

	return (sameStyle) ? style : nullptr;
}

shared_ptr<IStyle> CGroupShape::CalculateFillStyle()const
{
	if (m_shapes.empty())
	{
		return nullptr;
	}

	bool sameStyle = true;
	auto &style = m_shapes.at(0)->GetFillStyle();

	for (auto & shape : m_shapes)
	{
		auto shapeStyle = shape->GetFillStyle();
		if (shapeStyle->GetColor() != style->GetColor() || shapeStyle->IsEnabled() != style->IsEnabled())
		{
			sameStyle = false;
			break;
		}
	}

	return (sameStyle) ? style : nullptr;
}

void CGroupShape::SetOutlineStyle(const std::shared_ptr<IStyle> &style)
{
	if (!m_shapes.empty())
	{
		for (shared_ptr<IShape> &shape : m_shapes)
		{
			shape->SetOutlineStyle(style);
		}
	}
}

void CGroupShape::SetFillStyle(const std::shared_ptr<IStyle> &style)
{
	if (!m_shapes.empty())
	{
		for (shared_ptr<IShape> &shape : m_shapes)
		{
			shape->SetFillStyle(style);
		}
	}
}