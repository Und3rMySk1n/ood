#pragma once
#include <memory>
#include "IGroupShape.h"
#include "Shapes.h"

class CGroupShape : public IGroupShape
{
public:
	virtual void Draw(ICanvas & canvas) override;

	virtual std::shared_ptr<IStyle> GetOutlineStyle() override;
	virtual std::shared_ptr<const IStyle> GetOutlineStyle() const override;

	virtual std::shared_ptr<IStyle> GetFillStyle() override;
	virtual std::shared_ptr<const IStyle> GetFillStyle() const override;

	void SetOutlineStyle(const std::shared_ptr<IStyle> &style);
	void SetFillStyle(const std::shared_ptr<IStyle> &style);

	virtual std::shared_ptr<IGroupShape> GetGroup() override;
	virtual std::shared_ptr<const IGroupShape> GetGroup() const override;

	virtual RectD GetFrame()const override;
	virtual void SetFrame(const RectD & rect) override;

	virtual size_t GetShapesCount()const override;
	virtual void InsertShape(const std::shared_ptr<IShape> & shape) override;
	virtual void RemoveShapeAtIndex(size_t index) override;

	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) override;
	virtual const std::shared_ptr<IShape> GetShapeAtIndex(size_t index)const override;

private:
	std::shared_ptr<IStyle> CalculateOutlineStyle()const;
	std::shared_ptr<IStyle> CalculateFillStyle()const;
	CShapes m_shapes;
};