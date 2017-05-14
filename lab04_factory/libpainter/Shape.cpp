#include "stdafx.h"
#include "Shape.h"


CShape::CShape()
{
}

void CShape::SetColor(Color color)
{
	m_color = color;
}

Color CShape::GetColor() const
{
	return m_color;
}

CShape::~CShape()
{
}
