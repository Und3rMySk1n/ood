#pragma once
#include "SimpleShape.h"
#include "Vertex.h"

class CEllipse : public CSimpleShape
{
public:
	CEllipse(Vertex center, double radiusX, double radiusY);

	void Draw(ICanvas & canvas) final;

	virtual RectD GetFrame()const final;
	virtual void SetFrame(const RectD & rect) final;

	~CEllipse();
private:
	Vertex m_center = { 0, 0 };
	double m_radiusX = 0;
	double m_radiusY = 0;
	RectD m_frame = { 0, 0, 0, 0 };

	void CalculateFrame();
};