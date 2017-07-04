#pragma once
#include "SimpleShape.h"
#include "Vertex.h"

class CRectangle : public CSimpleShape
{
public:
	CRectangle(Vertex leftTop, Vertex rightBottom);

	void Draw(ICanvas & canvas) final;

	virtual RectD GetFrame()const final;
	virtual void SetFrame(const RectD & rect) final;

	~CRectangle();
private:
	Vertex m_leftTop;
	Vertex m_rightBottom;
	RectD m_frame = { 0, 0, 0, 0 };

	void CalculateFrame();
};