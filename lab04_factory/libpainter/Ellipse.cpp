#include "stdafx.h"
#include "Ellipse.h"

using namespace std;

void CEllipse::Draw(ICanvas &canvas) const
{
	canvas.SetColor(GetColor());
	canvas.DrawEllipse(m_center, m_horizontalRadius, m_verticalRadius);
}

Vertex CEllipse::GetCenter() const
{
	return m_center;
}

float CEllipse::GetHorizontalRadius() const
{
	return m_horizontalRadius;
}

float CEllipse::GetVerticalRadius() const
{
	return m_verticalRadius;
}

CEllipse::CEllipse(Color color, Vertex center, float horizontalRadius, float verticalRadius)
	: m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
	SetColor(color);
}


CEllipse::~CEllipse()
{
}