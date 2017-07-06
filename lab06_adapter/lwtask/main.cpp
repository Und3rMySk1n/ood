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
	cout << "Should we use new API (y)?";
	string userInput;
	if (getline(cin, userInput) && (userInput == "y" || userInput == "Y"))
	{
		cout << "Should we use class adapter (y)?";
		if (getline(cin, userInput) && (userInput == "y" || userInput == "Y"))
		{
			app::PaintPictureOnModernGraphicsRendererWithClassAdapter(cout);
		}
		else
		{
			app::PaintPictureOnModernGraphicsRenderer(cout);
		}
	}
	else
	{
		app::PaintPictureOnCanvas(cout);
	}

	return 0;
}
