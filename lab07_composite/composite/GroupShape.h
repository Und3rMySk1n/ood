#pragma once
#include <memory>
#include "IGroupShape.h"
#include "Shapes.h"
#include "CompositeFillStyle.h"
#include "CompositeOutlineStyle.h"

class CGroupShape : public IGroupShape
{
public:
	CGroupShape();

	virtual void Draw(ICanvas & canvas) override;

	virtual std::shared_ptr<IStyle> GetOutlineStyle() const override;
	virtual std::shared_ptr<IStyle> GetFillStyle() const override;

	void SetOutlineStyle(const std::shared_ptr<IStyle> &style) override;
	void SetFillStyle(const std::shared_ptr<IStyle> &style) override;

	virtual std::shared_ptr<IGroupShape> GetGroup() override;
	virtual std::shared_ptr<const IGroupShape> GetGroup() const override;

	virtual RectD GetFrame()const override;
	virtual void SetFrame(const RectD & rect) override;

	virtual size_t GetShapesCount()const override;
	virtual void InsertShape(const std::shared_ptr<IShape> & shape) override;
	virtual void RemoveShapeAtIndex(size_t index) override;
	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index)const override;

private:
	std::shared_ptr<CShapes> m_shapes;
	std::shared_ptr<CCompositeFillStyle> m_fillStyle;
	std::shared_ptr<CCompositeOutlineStyle> m_outlineStyle;
};