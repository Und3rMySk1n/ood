#pragma once
#include "ISlide.h"
#include "Shapes.h"

class CSlide : public ISlide, public CShapes
{
public:
	virtual double GetWidth()const override;
	virtual double GetHeight()const override;

	virtual void Draw(ICanvas & canvas) override;
};