#pragma once
#include "Application.h"
#include "ShapeDrawingAdapter.h"
#include "ShapeDrawingClassAdapter.h"

// Пространство имен приложения (доступно для модификации)
namespace app
{
	void PaintPicture(shape_drawing_lib::CCanvasPainter & painter)
	{
		using namespace shape_drawing_lib;

		CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
		CRectangle rectangle({ 30, 40 }, 18, 24);

		painter.Draw(triangle);
		painter.Draw(rectangle);
	}

	void PaintPictureOnCanvas(std::ostream& outputStream)
	{
		graphics_lib::CCanvas simpleCanvas(outputStream);
		shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
		PaintPicture(painter);
	}

	void PaintPictureOnModernGraphicsRenderer(std::ostream& outputStream)
	{
		modern_graphics_lib::CModernGraphicsRenderer renderer(outputStream);
		shape_drawing_adapter::CCanvasAdapter canvasAdapter(renderer);
		shape_drawing_lib::CCanvasPainter painter(canvasAdapter);

		renderer.BeginDraw();
		PaintPicture(painter);
		renderer.EndDraw();
	}

	void PaintPictureOnModernGraphicsRendererWithClassAdapter(std::ostream& outputStream)
	{
		CShapeDrawingClassAdapter canvas(outputStream);
		shape_drawing_lib::CCanvasPainter painter(canvas);

		canvas.BeginDraw();
		PaintPicture(painter);
		canvas.EndDraw();
	}
}