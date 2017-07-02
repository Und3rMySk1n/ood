#pragma once
#include <functional>
#include "ICanvas.h"
#include "IShape.h"

typedef std::function<void(ICanvas & canvas, const IShape & shape)> DrawingStrategy;

class CSimpleShape : public IShape
{
public:
	CSimpleShape(const DrawingStrategy & drawingStrategy)
	{
		(void)&drawingStrategy;
	}
};