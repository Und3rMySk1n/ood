#pragma once
#include "Shape.h"
#include <vector>

class CRegularPolygon :
	public CShape
{
public:
	CRegularPolygon(Color color, Vertex center, float radius, int vertexCount);

	Vertex GetCenter() const;
	float GetRadius() const;
	int GetVertexCount() const;

	void Draw(ICanvas &canvas) const override;

	std::unique_ptr<CShape> Clone() const final;

	~CRegularPolygon();
private:
	std::vector<Vertex> GetVerticies() const;

	Vertex m_center;
	float m_radius;
	int m_vertexCount;
};

