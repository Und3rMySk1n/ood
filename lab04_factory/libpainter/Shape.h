#pragma once
#include "Color.h"
#include "Vertex.h"
#include "ICanvas.h"
#include "IShape.h"

class CShape : public IShape
{
public:
	CShape();

	void SetColor(Color color);
	Color GetColor() const;

	virtual void Draw(ICanvas &canvas) const = 0;

	virtual ~CShape();
private:
	Color m_color = Color::black;
};

