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
			auto triangle = factory.CreateShape("triangle green 0 0 1 1 2 2");
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
			auto rectangle = factory.CreateShape("rectangle red 1 1 15 15");
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
			auto ellipse = factory.CreateShape("ellipse blue 1 1 15.13 20.27");
			ellipse->Draw(canvas);
			auto expectedCanvasContent =
				R"(Ellipse: [1, 1], Width: 15.13, Height: 20.27
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}

		BOOST_AUTO_TEST_CASE(ellipses_with_custom_color)
		{
			auto ellipse = factory.CreateShape("ellipse blue 1 1 15.13 20.27");
			BOOST_CHECK_EQUAL(ellipse->GetColor(), Color::blue);
		}

		BOOST_AUTO_TEST_CASE(polygons)
		{
			auto ellipse = factory.CreateShape("polygon yellow 5 5 10 5");
			ellipse->Draw(canvas);
			auto expectedCanvasContent =
				R"(Line: [15, 5], [8.09017, 14.5106]
Line: [8.09017, 14.5106], [-3.09017, 10.8779]
Line: [-3.09017, 10.8779], [-3.09017, -0.877853]
Line: [-3.09017, -0.877853], [8.09017, -4.51056]
Line: [8.09017, -4.51056], [15, 5]
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