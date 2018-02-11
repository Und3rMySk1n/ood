#include "GroupShape.h"
#include "Style.h"
#include "CompositeFillStyle.h"
#include "CompositeOutlineStyle.h"

using namespace std;

CGroupShape::CGroupShape()
{
	m_shapes = make_shared<CShapes>();
	m_fillStyle = make_shared<CCompositeFillStyle>(m_shapes);
	m_outlineStyle = make_shared<CCompositeOutlineStyle>(m_shapes);
}

void CGroupShape::Draw(ICanvas & canvas)
{
	for (int i = 0; i < m_shapes->GetShapesCount(); i++)
	{
		auto shape = m_shapes->GetShapeAtIndex(i);
		shape->Draw(canvas);
	}
}

shared_ptr<const IStyle> CGroupShape::GetOutlineStyle()const
{
	return m_outlineStyle;
}

shared_ptr<const IStyle> CGroupShape::GetFillStyle()const
{
	return m_fillStyle;
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
	
	if (m_shapes->GetShapesCount() != 0)
	{
		RectD const &firstFrame = m_shapes->GetShapeAtIndex(0)->GetFrame();

		double minX = firstFrame.left;
		double minY = firstFrame.top;
		double maxX = minX + firstFrame.width;
		double maxY = minY + firstFrame.height;

		if (m_shapes->GetShapesCount() > 0)
		{
			for (int i = 1; i < m_shapes->GetShapesCount(); i++)
			{
				auto shape = m_shapes->GetShapeAtIndex(i);

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

	for (int i = 0; i < m_shapes->GetShapesCount(); i++)
	{
		auto shape = m_shapes->GetShapeAtIndex(i);

		RectD shapeFrame = shape->GetFrame();
		shapeFrame.left = rect.left + (shapeFrame.left - oldFrame.left) / (oldFrame.width / rect.width);
		shapeFrame.top = rect.top + (shapeFrame.top - oldFrame.top) / (oldFrame.height / rect.height);
		shapeFrame.width = shapeFrame.width * (rect.width / oldFrame.width);
		shapeFrame.height = shapeFrame.height * (rect.height / oldFrame.height);
		shape->SetFrame(shapeFrame);
	}
}

void CGroupShape::SetOutlineStyle(const std::shared_ptr<IStyle> &style)
{
	if (m_shapes->GetShapesCount() != 0)
	{
		for (int i = 0; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			shape->SetOutlineStyle(style);
		}
	}
}

void CGroupShape::SetFillStyle(const std::shared_ptr<IStyle> &style)
{
	if (m_shapes->GetShapesCount() != 0)
	{
		for (int i = 0; i < m_shapes->GetShapesCount(); i++)
		{
			auto shape = m_shapes->GetShapeAtIndex(i);
			shape->SetFillStyle(style);
		}
	}
}

size_t CGroupShape::GetShapesCount()const
{
	return m_shapes->GetShapesCount();
}

void CGroupShape::InsertShape(const std::shared_ptr<IShape> & shape)
{
	m_shapes->InsertShape(shape);
}

std::shared_ptr<IShape> CGroupShape::GetShapeAtIndex(size_t index)const
{
	return m_shapes->GetShapeAtIndex(index);
}

void CGroupShape::RemoveShapeAtIndex(size_t index)
{
	m_shapes->RemoveShapeAtIndex(index);
}