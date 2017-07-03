#include <iostream>
#include <fstream>
#include "CommonTypes.h"
#include "SVGCanvas.h"

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
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
