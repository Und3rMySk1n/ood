#pragma once
#include "Shape.h"
#include <vector>

class CRegularPolygon :
	public CShape
{
public:
	CRegularPolygon(Vertex center, float radius, int vertexCount);

	Vertex GetCenter() const;
	float GetRadius() const;
	int GetVertexCount() const;

	void Draw(ICanvas &canvas) const override;

	~CRegularPolygon();
private:
	std::vector<Vertex> GetVerticies() const;

	Vertex m_center;
	float m_radius;
	int m_vertexCount;
};

