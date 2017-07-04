#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(Color color, Vertex vertex1, Vertex vertex2, Vertex vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
	SetColor(color);
}


CTriangle::~CTriangle()
{
}

void CTriangle::Draw(ICanvas &canvas) const
{
	canvas.BeginDraw();
	canvas.SetColor(GetColor());
	canvas.DrawLine(m_vertex1, m_vertex2);
	canvas.DrawLine(m_vertex2, m_vertex3);
	canvas.DrawLine(m_vertex3, m_vertex1);
	canvas.EndDraw();
}

Vertex CTriangle::GetVertex1() const
{
	return m_vertex1;
}

Vertex CTriangle::GetVertex2() const
{
	return m_vertex2;
}

Vertex CTriangle::GetVertex3() const
{
	return m_vertex3;
}