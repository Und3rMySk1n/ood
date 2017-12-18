#pragma once
#include "IDrawable.h"

class ISlide : public IDrawable
{
public:
	virtual double GetWidth()const = 0;
	virtual double GetHeight()const = 0;

	virtual ~ISlide() = default;
};