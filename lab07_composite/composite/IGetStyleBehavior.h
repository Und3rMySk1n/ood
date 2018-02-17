#pragma once
#include <memory>
#include "IStyle.h"
#include "IShape.h"

class IGetStyleBehavior
{
public:
	virtual std::shared_ptr<IStyle> GetStyle(std::shared_ptr<IShape> shape) = 0;
};

