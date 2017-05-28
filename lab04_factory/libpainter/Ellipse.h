#pragma once
#include "Shape.h"
class CEllipse :
	public CShape
{
public:
	CEllipse(Vertex center, float horizontalRadius, float verticalRadius);

	Vertex GetCenter() const;
	float GetHorizontalRadius() const;
	float GetVerticalRadius() const;

	void Draw(ICanvas &canvas) const override;

	~CEllipse();
private:
	Vertex m_center = { 0, 0 };
	float m_horizontalRadius = 0;
	float m_verticalRadius = 0;
};

