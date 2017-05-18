#pragma once
#include "ICanvas.h"
#include <string>

class CCanvas :
	public ICanvas
{
public:
	CCanvas();

	void SetColor(Color color) override;
	void DrawLine(const Vertex from, const Vertex to) override;
	void DrawEllipse(const Vertex center, float width, float height) override;

	std::string GetCanvasContent() const;

	~CCanvas();
private:
	Color m_color = Color::black;
	std::string m_canvasContent;
};