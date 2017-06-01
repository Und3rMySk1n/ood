#include "stdafx.h"
#include "../libpainter/ShapeFactory.h"
#include "../libpainter/Canvas.h"

using namespace std;

struct Shape_factory_
{
	stringstream outputStream;
	CCanvas canvas{ outputStream };
	CShapeFactory factory;
};

BOOST_FIXTURE_TEST_SUITE(Shape_factory, Shape_factory_)
	BOOST_AUTO_TEST_SUITE(can_create)
		BOOST_AUTO_TEST_CASE(triangles)
		{
			auto triangle = factory.CreateShape("triangle 0 0 1 1 2 2");
			triangle->Draw(canvas);
			auto expectedCanvasContent =
				R"(Line: [0, 0], [1, 1]
Line: [1, 1], [2, 2]
Line: [2, 2], [0, 0]
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}

		BOOST_AUTO_TEST_CASE(rectangles)
		{
			auto rectangle = factory.CreateShape("rectangle 1 1 15 15");
			rectangle->Draw(canvas);
			auto expectedCanvasContent =
				R"(Line: [1, 1], [15, 1]
Line: [15, 1], [15, 15]
Line: [15, 15], [1, 15]
Line: [1, 15], [1, 1]
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}

		BOOST_AUTO_TEST_CASE(ellipses)
		{
			auto ellipse = factory.CreateShape("ellipse 1 1 15.13 20.27");
			ellipse->Draw(canvas);
			auto expectedCanvasContent =
				R"(Ellipse: [1, 1], Width: 15.13, Height: 20.27
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(throws_exception)
		BOOST_AUTO_TEST_CASE(if_shape_does_not_exist)
		{
			BOOST_CHECK_THROW(auto shape = factory.CreateShape("some different shape"), invalid_argument);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()