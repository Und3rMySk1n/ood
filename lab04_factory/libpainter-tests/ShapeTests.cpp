#include "stdafx.h"
#include "../libpainter/Shape.h"
#include "../libpainter/Triangle.h"
#include "../libpainter/Canvas.h"
#include "../libpainter/Canvas.h"
#include <iostream>
#include <sstream>

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