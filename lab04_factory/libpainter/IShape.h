#pragma once
#include <memory>

class CShape;

class IShape
{
public:
	virtual void SetColor(Color color) = 0;
	virtual Color GetColor() const = 0;

	virtual void Draw(ICanvas &canvas) const = 0;

	virtual ~IShape() = default;
};