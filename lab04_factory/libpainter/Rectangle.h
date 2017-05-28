#pragma once
#include "Shape.h"
class CRectangle :
	public CShape
{
public:
	CRectangle(Vertex leftTop, Vertex rightBottom);

	Vertex GetLeftTop() const;
	Vertex GetRightBottom() const;

	void Draw(ICanvas &canvas) const override;

	~CRectangle();
private:
	Vertex m_leftTop = { (float)0.1, (float)0.2 };
	Vertex m_rightBottom = { 0, 0 };
};

