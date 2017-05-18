#pragma once
#include "Color.h"
#include "Vertex.h"
#include "Canvas.h"

class CShape
{
public:
	CShape();

	void SetColor(Color color);
	Color GetColor() const;

	virtual void Draw(CCanvas &canvas) const = 0;

	virtual ~CShape();
private:
	Color m_color = Color::black;
};

