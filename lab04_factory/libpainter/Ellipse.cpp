#include "stdafx.h"
#include "Ellipse.h"

void CEllipse::Draw(ICanvas &canvas) const
{
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

CEllipse::CEllipse(Vertex center, float horizontalRadius, float verticalRadius)
	: m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
}


CEllipse::~CEllipse()
{
}
