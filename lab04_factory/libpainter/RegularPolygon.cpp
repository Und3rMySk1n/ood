#include "stdafx.h"
#include "RegularPolygon.h"

using namespace std;

Vertex CRegularPolygon::GetCenter() const
{
	return m_center;
}


float CRegularPolygon::GetRadius() const
{
	return m_radius;
}


int CRegularPolygon::GetVertexCount() const
{
	return m_vertexCount;
}


void CRegularPolygon::Draw(ICanvas &canvas) const
{
	vector<Vertex> verticies = GetVerticies();
	for (int i = 0; i < (verticies.size() - 1); ++i)
	{
		canvas.DrawLine(verticies.at(i), verticies.at(i+1));
	}

	canvas.SetColor(GetColor());
	canvas.DrawLine(verticies.at(verticies.size() - 1), verticies.at(0));
}


CRegularPolygon::CRegularPolygon(Color color, Vertex center, float radius, int vertexCount)
	: m_center(center)
	, m_radius(radius)
	, m_vertexCount(vertexCount)
{
	SetColor(color);
}


CRegularPolygon::~CRegularPolygon()
{
}

vector<Vertex> CRegularPolygon::GetVerticies() const
{
	vector<Vertex> verticies;

	const float step = float(2 * M_PI / m_vertexCount);
	for (float angle = 0; angle < float(2 * M_PI); angle += step)
	{
		Vertex vertex;
		const float dx = m_radius * cosf(angle);
		const float dy = m_radius * sinf(angle);

		vertex.x = dx + m_center.x;
		vertex.y = dy + m_center.y;

		verticies.push_back(vertex);
	}

	return verticies;
}