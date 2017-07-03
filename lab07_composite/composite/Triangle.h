#pragma once
#include "SimpleShape.h"
#include "Vertex.h"

class CTriangle : public CSimpleShape
{
public:
	CTriangle(Vertex one, Vertex two, Vertex three);

	void Draw(ICanvas & canvas) final;

	virtual RectD GetFrame() final;
	virtual void SetFrame(const RectD & rect) final;

	~CTriangle();
private:
	Vertex m_one = { 0, 0 };
	Vertex m_two = { 0, 0 };
	Vertex m_three = { 0, 0 };
	RectD m_frame = { 0, 0, 0, 0 };

	void CalculateFrame();
	void CalculateNewVertexPosition(Vertex &vertex, RectD oldFrame, RectD newFrame);
};