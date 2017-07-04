#include <iostream>
#include <fstream>
#include <memory>
#include "CommonTypes.h"
#include "SVGCanvas.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "Style.h"
#include "GroupShape.h"

using namespace std;

const int RED_COLOR = 14296871;
const int GREEN_COLOR = 10930456;
const int YELLOW_COLOR = 15657729;

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

		shared_ptr<IStyle> greenFillStyle = make_shared<CStyle>(true, GREEN_COLOR);
		shared_ptr<IStyle> redFillStyle = make_shared<CStyle>(true, RED_COLOR);
		shared_ptr<IStyle> yellowFillStyle = make_shared<CStyle>(true, YELLOW_COLOR);

		auto sail = make_shared<CTriangle>(Vertex{ 200, 50 }, Vertex{ 280, 200 }, Vertex{ 190, 220 });
		sail->SetFillStyle(greenFillStyle);
		sail->SetOutlineStyle(greenFillStyle);

		auto boatPartOne = make_shared<CRectangle>(Vertex{ 170, 220 }, Vertex{ 290, 270 });
		boatPartOne->SetFillStyle(redFillStyle);
		boatPartOne->SetOutlineStyle(redFillStyle);

		auto boatPartTwo = make_shared<CTriangle>(Vertex{ 170, 220 }, Vertex{ 170, 270 }, Vertex{ 160, 220 });
		boatPartTwo->SetFillStyle(redFillStyle);
		boatPartTwo->SetOutlineStyle(redFillStyle);

		auto boatPartThree = make_shared<CTriangle>(Vertex{ 170, 220 }, Vertex{ 330, 205 }, Vertex{ 290, 270 });
		boatPartThree->SetFillStyle(redFillStyle);
		boatPartThree->SetOutlineStyle(redFillStyle);

		auto sun = make_shared<CEllipse>(Vertex{ 300, 70 }, 30, 30);
		sun->SetFillStyle(yellowFillStyle);
		sun->SetOutlineStyle(yellowFillStyle);
		sun->Draw(canvas);

		auto ship = make_shared<CGroupShape>();
		ship->InsertShape(sail);
		ship->InsertShape(boatPartOne);
		ship->InsertShape(boatPartTwo);
		ship->InsertShape(boatPartThree);

		ship->Draw(canvas);

		RectD frame = ship->GetFrame();
		cout << frame.left << endl << frame.top << endl << frame.width << endl << frame.height << endl;
		RectD newFrame = { 500, 50, 340, 220 };		

		ship->SetFrame(newFrame);
		ship->Draw(canvas);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
