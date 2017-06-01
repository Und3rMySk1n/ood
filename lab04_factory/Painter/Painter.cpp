// Painter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../libpainter/Canvas.h"
#include "../libpainter/Painter.h"
#include "../libpainter/Designer.h"
#include "../libpainter/ShapeFactory.h"
#include "../libpainter/PictureDraft.h"
#include <sstream>

using namespace std;

int main()
{
	CCanvas canvas{ cout };
	CPainter painter;
	CPictureDraft draft;
	CShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);

	try
	{
		draft = designer.CreateDraft(cin);
		painter.DrawPicture(draft, canvas);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}	

	return 0;
}

