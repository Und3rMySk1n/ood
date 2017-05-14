#pragma once
#include "Color.h"

class CShape
{
public:
	CShape();

	void SetColor(Color color);
	Color GetColor() const;

	virtual ~CShape();
private:
	Color m_color = Color::black;
};

