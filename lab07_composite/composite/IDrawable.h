#pragma once
#include "Canvas.h"

class IDrawable
{
public:
	virtual void Draw(const ICanvas & canvas) = 0;

	virtual ~IDrawable() = default;
};