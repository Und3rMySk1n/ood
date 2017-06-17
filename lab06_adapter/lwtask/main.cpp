#include <iostream>
#include <stdexcept>
#include <string>
#include <boost/format.hpp>
#include <cstdint>
#include "GraphicsLib.h"
#include "ShapeDrawingLib.h"
#include "ModernGraphicsLib.h"
#include "Application.h"

using namespace std;

int main()
{
	/*cout << "Should we use new API (y)?";
	string userInput;
	if (getline(cin, userInput) && (userInput == "y" || userInput == "Y"))
	{
		app::PaintPictureOnModernGraphicsRenderer();
	}
	else
	{
		app::PaintPictureOnCanvas();
	}*/

	graphics_lib::CCanvas canvas(std::cout);
	shape_drawing_lib::CTriangle triangle{ { 0, 0 },{ 1, 1 },{ 2, 2 } };
	triangle.Draw(canvas);

	return 0;
}
