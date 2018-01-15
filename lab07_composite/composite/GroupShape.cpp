#include "GroupShape.h"
#include "Style.h"

using namespace std;

void CGroupShape::Draw(ICanvas & canvas)
{
	for (int i = 0; i < m_shapes.GetShapesCount(); i++)
	{
		auto shape = m_shapes.GetShapeAtIndex(i);
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
	
	if (m_shapes.GetShapesCount() != 0)
	{
		RectD const &firstFrame = m_shapes.GetShapeAtIndex(0)->GetFrame();

		double minX = firstFrame.left;
		double minY = firstFrame.top;
		double maxX = minX + firstFrame.width;
		double maxY = minY + firstFrame.height;

		if (m_shapes.GetShapesCount() > 0)
		{
			for (int i = 1; i < m_shapes.GetShapesCount(); i++)
			{
				auto shape = m_shapes.GetShapeAtIndex(i);

				RectD const &frame = shape->GetFrame();
				minX = min(minX, frame.left);
				minY = min(minY, frame.top);
				maxX = max(maxX, frame.left + frame.width);
				maxY = max(maxY, frame.top + frame.height);
			}
		}		

		frame = { minX, minY, maxX - minX, maxY - minY };
	}

	return frame;
}

void CGroupShape::SetFrame(const RectD & rect)
{
	RectD oldFrame = GetFrame();

	for (int i = 0; i < m_shapes.GetShapesCount(); i++)
	{
		auto shape = m_shapes.GetShapeAtIndex(i);

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
	if (m_shapes.GetShapesCount() == 0)
	{
		return nullptr;
	}

	std::shared_ptr<IStyle> commonStyle = m_shapes.GetShapeAtIndex(0)->GetOutlineStyle();
	if (m_shapes.GetShapesCount() > 0)
	{
		for (int i = 1; i < m_shapes.GetShapesCount(); i++)
		{
			auto shape = m_shapes.GetShapeAtIndex(i);

			if (commonStyle != shape->GetOutlineStyle())
			{
				commonStyle = nullptr;
				break;
			}
		}
	}

	return commonStyle;
}

shared_ptr<IStyle> CGroupShape::CalculateFillStyle()const
{
	if (m_shapes.GetShapesCount() == 0)
	{
		return nullptr;
	}

	std::shared_ptr<IStyle> commonStyle = m_shapes.GetShapeAtIndex(0)->GetFillStyle();
	if (m_shapes.GetShapesCount() > 0)
	{
		for (int i = 1; i < m_shapes.GetShapesCount(); i++)
		{
			auto shape = m_shapes.GetShapeAtIndex(i);

			if (commonStyle != shape->GetFillStyle())
			{
				commonStyle = nullptr;
				break;
			}
		}
	}

	return commonStyle;
}

void CGroupShape::SetOutlineStyle(const std::shared_ptr<IStyle> &style)
{
	if (m_shapes.GetShapesCount() != 0)
	{
		for (int i = 0; i < m_shapes.GetShapesCount(); i++)
		{
			auto shape = m_shapes.GetShapeAtIndex(i);
			shape->SetOutlineStyle(style);
		}
	}
}

void CGroupShape::SetFillStyle(const std::shared_ptr<IStyle> &style)
{
	if (m_shapes.GetShapesCount() != 0)
	{
		for (int i = 0; i < m_shapes.GetShapesCount(); i++)
		{
			auto shape = m_shapes.GetShapeAtIndex(i);
			shape->SetFillStyle(style);
		}
	}
}

size_t CGroupShape::GetShapesCount()const
{
	return m_shapes.GetShapesCount();
}

void CGroupShape::InsertShape(const std::shared_ptr<IShape> & shape)
{
	m_shapes.InsertShape(shape);
}

std::shared_ptr<IShape> CGroupShape::GetShapeAtIndex(size_t index)
{
	return m_shapes.GetShapeAtIndex(index);
}

const std::shared_ptr<IShape> CGroupShape::GetShapeAtIndex(size_t index)const
{
	return m_shapes.GetShapeAtIndex(index);
}

void CGroupShape::RemoveShapeAtIndex(size_t index)
{
	m_shapes.RemoveShapeAtIndex(index);
}