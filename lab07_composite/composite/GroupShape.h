#pragma once
#include <memory>
#include <vector>
#include "IGroupShape.h"

class CGroupShape : public IGroupShape
{
public:
	virtual void Draw(ICanvas & canvas) override;

	virtual std::shared_ptr<IStyle> GetOutlineStyle() override;
	virtual const std::shared_ptr<IStyle> GetOutlineStyle()const override;

	virtual std::shared_ptr<IStyle> GetFillStyle() override;
	virtual const std::shared_ptr<IStyle> GetFillStyle()const override;

	virtual std::shared_ptr<IGroupShape> GetGroup() override;
	virtual std::shared_ptr<const IGroupShape> GetGroup() const override;

	virtual void InsertShape(const std::shared_ptr<IShape> & shape) override;
	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) override;
	virtual void RemoveShapeAtIndex(size_t index) override;
	virtual size_t GetShapesCount()const override;

	virtual RectD GetFrame()const override;
	virtual void SetFrame(const RectD & rect) override;
private:
	RectD m_frame = { 0, 0, 0, 0 };
	std::vector<std::shared_ptr<IShape>> m_shapes;

	void CalculateFrame();
};