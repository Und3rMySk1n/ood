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
#include "Slide.h"

using namespace std;

const int RED_COLOR = 14296871;
const int GREEN_COLOR = 10930456;
const int YELLOW_COLOR = 15657729;
const int BLUE_COLOR = 1402838;

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

		auto sail = make_shared<CTriangle>(Vertex{ 200, 50 }, Vertex{ 280, 200 }, Vertex{ 190, 220 });
		auto sailFillStyle = sail->GetFillStyle();
		auto sailOutlineStyle = sail->GetOutlineStyle();

		sailFillStyle->SetColor(GREEN_COLOR);
		sailFillStyle->Enable(true);
		sailOutlineStyle->SetColor(GREEN_COLOR);
		sailOutlineStyle->Enable(true);


		auto boatPartOne = make_shared<CRectangle>(Vertex{ 170, 220 }, Vertex{ 290, 270 });
		auto boatPartOneFillStyle = boatPartOne->GetFillStyle();
		auto boatPartOneOutlineStyle = boatPartOne->GetOutlineStyle();

		boatPartOneFillStyle->SetColor(RED_COLOR);
		boatPartOneFillStyle->Enable(true);
		boatPartOneOutlineStyle->SetColor(RED_COLOR);
		boatPartOneOutlineStyle->Enable(true);


		auto boatPartTwo = make_shared<CTriangle>(Vertex{ 170, 220 }, Vertex{ 170, 270 }, Vertex{ 160, 220 });
		auto boatPartTwoFillStyle = boatPartTwo->GetFillStyle();
		auto boatPartTwoOutlineStyle = boatPartTwo->GetOutlineStyle();

		boatPartTwoFillStyle->SetColor(RED_COLOR);
		boatPartTwoFillStyle->Enable(true);
		boatPartTwoOutlineStyle->SetColor(RED_COLOR);
		boatPartTwoOutlineStyle->Enable(true);


		auto boatPartThree = make_shared<CTriangle>(Vertex{ 170, 220 }, Vertex{ 330, 205 }, Vertex{ 290, 270 });
		auto boatPartThreeFillStyle = boatPartThree->GetFillStyle();
		auto boatPartThreeOutlineStyle = boatPartThree->GetOutlineStyle();

		boatPartThreeFillStyle->SetColor(RED_COLOR);
		boatPartThreeFillStyle->Enable(true);
		boatPartThreeOutlineStyle->SetColor(RED_COLOR);
		boatPartThreeOutlineStyle->Enable(true);


		auto sun = make_shared<CEllipse>(Vertex{ 300, 70 }, 30, 30);
		auto sunFillStyle = sun->GetFillStyle();
		auto sunOutlineStyle = sun->GetOutlineStyle();

		sunFillStyle->SetColor(YELLOW_COLOR);
		sunFillStyle->Enable(true);
		sunOutlineStyle->SetColor(YELLOW_COLOR);
		sunOutlineStyle->Enable(true);

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

		newFrame = { 900, 50, 170, 220 };
		ship->SetFrame(newFrame);
		auto shipFillStyle = ship->GetFillStyle();
		auto shipOutlineStyle = ship->GetOutlineStyle();

		shipFillStyle->SetColor(BLUE_COLOR);
		shipFillStyle->Enable(true);
		shipOutlineStyle->SetColor(BLUE_COLOR);
		shipOutlineStyle->Enable(true);


		CSlide slide;
		slide.InsertShape(ship);
		slide.Draw(canvas);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
