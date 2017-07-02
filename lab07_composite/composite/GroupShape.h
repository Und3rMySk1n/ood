#pragma once
#include <memory>
#include <vector>
#include "IGroupShape.h"

class CGroupShape : public IGroupShape
{
	CGroupShape()
	{
	}

	virtual void Draw(const ICanvas & canvas) override
	{
		for (auto shape : m_shapes)
		{
			shape->Draw(canvas);
		}
	}

	virtual std::shared_ptr<IStyle> GetOutlineStyle() override
	{
		return nullptr;
	}

	virtual const std::shared_ptr<IStyle> GetOutlineStyle()const override
	{
		return nullptr;
	}

	virtual std::shared_ptr<IStyle> GetFillStyle() override
	{
		return nullptr;
	}

	virtual const std::shared_ptr<IStyle> GetFillStyle()const override
	{
		return nullptr;
	}

	virtual std::shared_ptr<IGroupShape> GetGroup() override
	{
		return std::make_shared<IGroupShape>(this);
	}

	virtual std::shared_ptr<const IGroupShape> GetGroup() const override
	{
		return std::make_shared<IGroupShape>(this);
	}

	virtual void InsertShape(const std::shared_ptr<IShape> & shape, size_t position = std::numeric_limits<size_t>::max()) override
	{
		m_shapes.push_back(shape);
	}

	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) override
	{
		return m_shapes.at(index);
	}

	virtual void RemoveShapeAtIndex(size_t index) override
	{
		m_shapes.erase(m_shapes.begin() + index);
	}

	virtual size_t GetShapesCount()const override
	{
		return m_shapes.size();
	}

	virtual RectD GetFrame() override
	{
		return m_frame;
	}

	virtual void SetFrame(const RectD & rect) override
	{
		m_frame = rect;
	}
private:
	RectD m_frame;
	std::vector<std::shared_ptr<IShape>> m_shapes;
};