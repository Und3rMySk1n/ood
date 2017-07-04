#pragma once
#include "ICanvas.h"
class CSVGCanvas : public ICanvas
{
public:
	CSVGCanvas(std::ostream & ostream);

	virtual void SetColor(Color color) override;
	virtual void DrawLine(const Vertex from, const Vertex to) override;
	virtual void DrawEllipse(const Vertex center, float width, float height) override;

	void BeginDraw() override;
	void EndDraw() override;

	~CSVGCanvas();
private:
	void PrintStyle();
	void ColorToString();

	int m_lineWidth = 1;
	Color m_color = Color::black;
	std::ostream &m_output;
	bool m_pathOpened = false;
	Vertex m_lastVertex;
};

