#pragma once
#include "ISlide.h"
#include "GroupShape.h"

class CSlide : public ISlide
{
public:
	virtual double GetWidth()const override;
	virtual double GetHeight()const override;

	virtual size_t GetShapesCount()const override;
	virtual void InsertShape(const std::shared_ptr<IShape> & shape) override;
	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) override;
	virtual void RemoveShapeAtIndex(size_t index) override;

	virtual void Draw(ICanvas & canvas) override;
private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
};