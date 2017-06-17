#include "stdafx.h"
#include "../lwtask/ShapeDrawingLib.h"

using namespace std;

struct Triangle_
{
	stringstream outputStream;
	graphics_lib::CCanvas canvas{ outputStream };
	shape_drawing_lib::CTriangle triangle{ {0, 0}, {1, 1}, {2, 2} };
};

BOOST_FIXTURE_TEST_SUITE(Triangle, Triangle_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(can_be_drawn)
		{
			triangle.Draw(canvas);
			auto expectedCanvasContent =
				R"(MoveTo (0, 0)
LineTo (1, 1)
LineTo (2, 2)
LineTo (0, 0)
)";

			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()



struct Rectangle_
{
	stringstream outputStream;
	graphics_lib::CCanvas canvas{ outputStream };
	shape_drawing_lib::CRectangle rectangle{ { 0, 0 }, 5, 10 };
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, Rectangle_)
	BOOST_AUTO_TEST_SUITE(when_created)
	BOOST_AUTO_TEST_CASE(can_be_drawn)
	{
		rectangle.Draw(canvas);
		auto expectedCanvasContent =
			R"(MoveTo (0, 0)
LineTo (5, 0)
LineTo (5, 10)
LineTo (0, 10)
LineTo (0, 0)
)";

		BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
	}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()