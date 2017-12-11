#pragma once
#include <memory>
#include "IDrawable.h"
#include "IStyle.h"

class IGroupShape;

class IShape : public IDrawable
{
public:
	virtual RectD GetFrame()const = 0;
	virtual void SetFrame(const RectD & rect) = 0;

	virtual std::shared_ptr<IStyle> GetOutlineStyle() = 0;
	virtual std::shared_ptr<const IStyle> GetOutlineStyle()const = 0;

	virtual std::shared_ptr<IStyle> GetFillStyle() = 0;
	virtual std::shared_ptr<const IStyle> GetFillStyle()const = 0;

	virtual std::shared_ptr<IGroupShape> GetGroup() = 0;
	virtual std::shared_ptr<const IGroupShape> GetGroup() const = 0;

	virtual void SetOutlineStyle(const std::shared_ptr<IStyle> &style) = 0;
	virtual void SetFillStyle(const std::shared_ptr<IStyle> &style) = 0;
	
	virtual ~IShape() = default;
};