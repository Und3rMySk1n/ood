#pragma once
#include "Shape.h"

class CTriangle :
	public CShape
{
public:
	CTriangle(Color color, Vertex vertex1, Vertex vertex2, Vertex vertex3);

	Vertex GetVertex1() const;
	Vertex GetVertex2() const;
	Vertex GetVertex3() const;

	void Draw(ICanvas &canvas) const override;

	~CTriangle();
private:
	Vertex m_vertex1 = { 0, 0 };
	Vertex m_vertex2 = { 0, 0 };
	Vertex m_vertex3 = { 0, 0 };
};

