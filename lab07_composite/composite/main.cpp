#include <iostream>
#include <fstream>
#include <memory>
#include "CommonTypes.h"
#include "SVGCanvas.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "Style.h"

using namespace std;

const int RED_COLOR = 14296871;
const int YELLOW_COLOR = 10930456;

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

		CRectangle rectangle{ {350, 250}, {500, 600} };
		shared_ptr<IStyle> redFillStyle = make_shared<CStyle>(true, RED_COLOR);
		rectangle.SetFillStyle(redFillStyle);
		rectangle.Draw(canvas);

		CRectangle rectangleTwo{ { 300, 300 },{ 600, 400 } };
		shared_ptr<IStyle> greenFillStyle = make_shared<CStyle>(true, YELLOW_COLOR);
		rectangleTwo.SetOutlineStyle(greenFillStyle);
		RectD frame = { 250, 350, 300, 200 };
		rectangleTwo.SetFrame(frame);
		rectangleTwo.Draw(canvas);

		CTriangle triangle{ {400, 400}, {500, 300}, {600, 400} };
		RectD triangleFrame = { 450, 300, 200, 150 };
		triangle.SetFillStyle(greenFillStyle);
		triangle.SetFrame(triangleFrame);
		triangle.Draw(canvas);

		CEllipse ellipse{ {900, 300}, 100, 150 };
		RectD ellipseFrame = { 800, 150, 200, 200 };
		ellipse.SetFrame(ellipseFrame);
		ellipse.SetFillStyle(redFillStyle);
		ellipse.Draw(canvas);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
