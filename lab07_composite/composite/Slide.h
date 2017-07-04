#pragma once
#include "ISlide.h"
#include "GroupShape.h"

class CSlide : public ISlide
{
public:
	virtual double GetWidth()const override;
	virtual double GetHeight()const override;

	virtual IShapes & GetShapes() override;

	virtual void Draw(ICanvas & canvas) override;
private:
	CGroupShape m_shapes;
};