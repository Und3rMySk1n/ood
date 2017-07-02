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
		canvas.MoveTo(0, 0);
		canvas.LineTo(10, 100);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
