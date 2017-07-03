#include <iostream>
#include <fstream>
#include <memory>
#include "CommonTypes.h"
#include "SVGCanvas.h"
#include "Rectangle.h"
#include "Style.h"

using namespace std;

int main()
{
	cout << "Composite program starts" << endl;
	string canvasFileName = "../canvas/canvas.svg";

	try
	{
		ofstream canvasFile(canvasFileName.c_str());
		if (!canvasFile.is_open())
		{
			throw runtime_error("Error while opening file for canvas.");
		}

		CSVGCanvas canvas(canvasFile);
		canvas.MoveTo(100, 100);
		canvas.LineTo(200, 150);
		canvas.SetLineColor(379);
		canvas.BeginFill(3470);
		canvas.DrawEllipse(200, 200, 100, 150);
		canvas.EndFill();
		canvas.DrawEllipse(400, 400, 50, 150);

		CRectangle rectangle{ {350, 250}, {500, 600} };
		shared_ptr<IStyle> redFillStyle = make_shared<CStyle>(true, 14296871);
		rectangle.SetFillStyle(redFillStyle);
		rectangle.Draw(canvas);

		CRectangle rectangleTwo{ { 300, 300 },{ 600, 400 } };
		shared_ptr<IStyle> greenFillStyle = make_shared<CStyle>(true, 10930456);
		rectangleTwo.SetOutlineStyle(greenFillStyle);
		rectangleTwo.Draw(canvas);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
