#pragma once
#include "ShapeDrawingLib.h"
#include "ModernGraphicsLib.h"

// ������������ ���� ���������� (�������� ��� �����������)
namespace app
{
	void PaintPicture(shape_drawing_lib::CCanvasPainter & painter);
	void PaintPictureOnCanvas(std::ostream& outputStream);
	void PaintPictureOnModernGraphicsRenderer(std::ostream& outputStream);
}