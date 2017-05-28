#pragma once

#include "PictureDraft.h"
#include "ICanvas.h"

struct IPainter
{
	virtual void DrawPicture(CPictureDraft &draft, ICanvas &canvas) = 0;
	virtual ~IPainter() = default;
};