#include "stdafx.h"
#include "Painter.h"

void CPainter::DrawPicture(CPictureDraft &draft, ICanvas &canvas)
{
	for (auto &it : draft)
	{
		it.Draw(canvas);
	}
}


CPainter::CPainter()
{
}


CPainter::~CPainter()
{
}
