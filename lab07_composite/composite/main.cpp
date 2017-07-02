#include <cstdint>
#include "CommonTypes.h"
#include "Canvas.h"
#include "version1.h"

#include <boost/optional.hpp>
#include <memory>
#include <limits>
#include <functional>
#include <vector>

using boost::optional;

class IDrawable
{
public:
	virtual void Draw(const ICanvas & canvas) = 0;

	virtual ~IDrawable() = default;
};

class IStyle
{
public:
	virtual optional<bool> IsEnabled()const = 0;
	virtual void Enable(bool enable) = 0;

	virtual optional<RGBAColor> GetColor()const = 0;
	virtual void SetColor(RGBAColor color) = 0;

	virtual ~IStyle() = default;
};

class CStyle : public IStyle
{
public:
	virtual optional<bool> IsEnabled()const override
	{
		return m_isEnabled;
	}

	virtual void Enable(bool enable) override
	{
		m_isEnabled = enable;
	}

	virtual optional<RGBAColor> GetColor()const override
	{
		return m_color;
	}

	virtual void SetColor(RGBAColor color) override
	{
		m_color = color;
	}
private:
	bool m_isEnabled = false;
	RGBAColor m_color = NULL;
};

class IGroupShape;

class IShape : public IDrawable
{
public:
	virtual RectD GetFrame() = 0;
	virtual void SetFrame(const RectD & rect) = 0;

	virtual std::shared_ptr<IStyle> GetOutlineStyle() = 0;
	virtual const std::shared_ptr<IStyle> GetOutlineStyle()const = 0;
	
	virtual std::shared_ptr<IStyle> GetFillStyle() = 0;
	virtual const std::shared_ptr<IStyle> GetFillStyle()const = 0;

	virtual std::shared_ptr<IGroupShape> GetGroup() = 0;
	virtual std::shared_ptr<const IGroupShape> GetGroup() const = 0;

	virtual ~IShape() = default;
};

class IShapes
{
public:
	virtual size_t GetShapesCount()const = 0;
	virtual void InsertShape(const std::shared_ptr<IShape> & shape, size_t position = std::numeric_limits<size_t>::max()) = 0;
	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) = 0;
	virtual void RemoveShapeAtIndex(size_t index) = 0;

	virtual ~IShapes() = default;
};

class IGroupShape : public IShape, public IShapes
{
public:
	virtual ~IGroupShape() = default;
};

typedef std::function<void(ICanvas & canvas, const IShape & shape)> DrawingStrategy;

class CSimpleShape : public IShape
{
public:
	CSimpleShape(const DrawingStrategy & drawingStrategy)
	{
		(void)&drawingStrategy;
	}
};



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



class ISlide : public IDrawable
{
public:
	virtual double GetWidth()const = 0;
	virtual double GetHeight()const = 0;

	virtual IShapes & GetShapes()const = 0;

	virtual ~ISlide() = default;
};

class CSlide : public ISlide
{
public:

};


int main()
{
}
