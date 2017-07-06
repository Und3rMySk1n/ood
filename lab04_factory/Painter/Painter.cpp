// Painter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../libpainter/SVGCanvas.h"
#include "../libpainter/Painter.h"
#include "../libpainter/Designer.h"
#include "../libpainter/ShapeFactory.h"
#include "../libpainter/PictureDraft.h"
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	string canvasFileName = "../canvas/canvas.svg";
	ofstream canvasFile(canvasFileName.c_str());
	if (!canvasFile.is_open())
	{
		throw runtime_error("Error while opening file for canvas.");
	}
	CSVGCanvas canvas(canvasFile);

	CPainter painter;
	CPictureDraft draft;
	CShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);

	try
	{
		draft = designer.CreateDraft(cin);
		unique_ptr<CShape> newPolygon = shapeFactory.CreateShape("polygon green 100 100 70 5");
		auto polygonClone = newPolygon->Clone();

		draft.AddShape(move(polygonClone));

		painter.DrawPicture(draft, canvas);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}	

	return 0;
}

