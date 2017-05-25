#pragma once
#include "ICanvas.h"
#include <string>
#include <sstream>
#include <memory>

class CCanvas :
	public ICanvas
{
public:
	CCanvas(std::shared_ptr<std::stringstream> outputStream)
		: m_output(outputStream)
	{
	};

	void SetColor(Color color) override;
	void DrawLine(const Vertex from, const Vertex to) override;
	void DrawEllipse(const Vertex center, float width, float height) override;

	std::string GetCanvasContent() const;

	~CCanvas();
private:
	Color m_color = Color::black;
	std::string m_canvasContent;
	std::shared_ptr<std::stringstream> m_output;
};