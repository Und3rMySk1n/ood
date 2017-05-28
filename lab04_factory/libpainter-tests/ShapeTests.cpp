#include "stdafx.h"
#include "../libpainter/Shape.h"
#include "../libpainter/Triangle.h"
#include "../libpainter/Rectangle.h"
#include "../libpainter/Canvas.h"
#include "../libpainter/Canvas.h"
#include <iostream>
#include <sstream>
#include <boost/test/floating_point_comparison.hpp>


using namespace std;

struct Triangle_
{
	stringstream outputStream;
	CCanvas canvas{ outputStream };
	CTriangle triangle{ { 0, 0 }, { 1, 1 }, { 2, 2 } };
};

BOOST_FIXTURE_TEST_SUITE(Triangle, Triangle_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(has_black_color)
		{
			BOOST_CHECK_EQUAL(triangle.GetColor(), Color::black);
		}
		BOOST_AUTO_TEST_CASE(can_change_color)
		{
			triangle.SetColor(Color::red);
			BOOST_CHECK_EQUAL(triangle.GetColor(), Color::red);
		}
		BOOST_AUTO_TEST_CASE(returns_its_vertices)
		{
			Vertex one = triangle.GetVertex1();
			Vertex two = triangle.GetVertex2();
			Vertex three = triangle.GetVertex3();

			BOOST_CHECK_EQUAL(one.x, 0);
			BOOST_CHECK_EQUAL(one.y, 0);
			BOOST_CHECK_EQUAL(two.x, 1);
			BOOST_CHECK_EQUAL(two.y, 1);
			BOOST_CHECK_EQUAL(three.x, 2);
			BOOST_CHECK_EQUAL(three.y, 2);
		}
		BOOST_AUTO_TEST_CASE(can_draw_itself_on_canvas)
		{
			triangle.Draw(canvas);
			auto expectedCanvasContent = 
R"(Line: [0, 0], [1, 1]
Line: [1, 1], [2, 2]
Line: [2, 2], [0, 0]
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()


struct Rectangle_
{
	stringstream outputStream;
	CCanvas canvas{ outputStream };
	CRectangle rectangle{ { (float)0.1, (float)0.2 }, { (float)2.3, (float)2.4 } };
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, Rectangle_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(has_black_color)
		{
			BOOST_CHECK_EQUAL(rectangle.GetColor(), Color::black);
		}
		BOOST_AUTO_TEST_CASE(can_change_color)
		{
			rectangle.SetColor(Color::green);
			BOOST_CHECK_EQUAL(rectangle.GetColor(), Color::green);
		}
		BOOST_AUTO_TEST_CASE(returns_its_vertices)
		{
			Vertex leftTop = rectangle.GetLeftTop();
			Vertex rigthBottom = rectangle.GetRightBottom();

			BOOST_CHECK_CLOSE(leftTop.x, 0.1, 0.0001);
			BOOST_CHECK_CLOSE(leftTop.y, 0.2, 0.0001);
			BOOST_CHECK_CLOSE(rigthBottom.x, 2.3, 0.0001);
			BOOST_CHECK_CLOSE(rigthBottom.y, 2.4, 0.0001);
		}
		BOOST_AUTO_TEST_CASE(can_draw_itself_on_canvas)
		{
			rectangle.Draw(canvas);
			auto expectedCanvasContent =
				R"(Line: [0.1, 0.2], [2.3, 0.2]
Line: [2.3, 0.2], [2.3, 2.4]
Line: [2.3, 2.4], [0.1, 2.4]
Line: [0.1, 2.4], [0.1, 0.2]
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()