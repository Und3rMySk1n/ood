#pragma once
#include "GraphicsLib.h"
#include "ShapeDrawingLib.h"
#include "ModernGraphicsLib.h"

namespace shape_drawing_adapter
{
	class CCanvasAdapter : public graphics_lib::ICanvas
	{
	public:
		CCanvasAdapter(modern_graphics_lib::CModernGraphicsRenderer & renderer);
		void SetColor(uint32_t rgbColor) override;
		void MoveTo(int x, int y) override;
		void LineTo(int x, int y) override;
	private:
		modern_graphics_lib::CModernGraphicsRenderer *m_renderer;
		modern_graphics_lib::CPoint m_currentPoint = { 0, 0 };
		modern_graphics_lib::CRGBAColor m_color = modern_graphics_lib::CRGBAColor(0, 0, 0, 1);
	};
}