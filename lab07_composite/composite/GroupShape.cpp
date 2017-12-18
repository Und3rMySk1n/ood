#include "GroupShape.h"
#include "Style.h"

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

shared_ptr<const IStyle> CGroupShape::GetOutlineStyle()const
{
	return CalculateOutlineStyle();
}

shared_ptr<IStyle> CGroupShape::GetFillStyle()
{
	return CalculateFillStyle();
}

shared_ptr<const IStyle> CGroupShape::GetFillStyle()const
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

RectD CGroupShape::GetFrame()const
{
	RectD frame = { 0, 0, 0, 0 };

	if (!m_shapes.empty())
	{
		RectD const &firstFrame = m_shapes.at(0)->GetFrame();

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

		frame = { minX, minY, maxX - minX, maxY - minY };
	}

	return frame;
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
}

shared_ptr<IStyle> CGroupShape::CalculateOutlineStyle()const
{
	if (m_shapes.empty())
	{
		return nullptr;
	}

	std::shared_ptr<IStyle> commonStyle = m_shapes.at(0)->GetOutlineStyle();
	for (auto & shape : m_shapes)
	{
		if (commonStyle != shape->GetOutlineStyle())
		{
			commonStyle = nullptr;
			break;
		}
	}

	return commonStyle;
}

shared_ptr<IStyle> CGroupShape::CalculateFillStyle()const
{
	if (m_shapes.empty())
	{
		return nullptr;
	}

	std::shared_ptr<IStyle> commonStyle = m_shapes.at(0)->GetFillStyle();
	for (auto & shape : m_shapes)
	{
		if (commonStyle != shape->GetFillStyle())
		{
			commonStyle = nullptr;
			break;
		}
	}

	return commonStyle;
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