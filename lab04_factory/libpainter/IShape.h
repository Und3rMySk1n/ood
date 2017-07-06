#pragma once
#include <memory>

class CShape;

class IShape
{
public:
	virtual std::unique_ptr<CShape> Clone()const = 0;

	virtual ~IShape() = default;
};