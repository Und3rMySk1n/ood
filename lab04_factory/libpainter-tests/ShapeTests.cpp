#include "stdafx.h"
#include "../libpainter/Shape.h"
#include "../libpainter/Triangle.h"
#include <iostream>
#include <sstream>

using namespace std;

struct Triangle_
{
	shared_ptr<stringstream> outputStream = make_shared<stringstream>();
	CCanvas canvas = CCanvas(outputStream);
	CTriangle triangle = CTriangle({ 0, 0 }, { 1, 1 }, { 2, 2 });
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
			stringstream expectedCanvasContent;
			expectedCanvasContent << "Line: [0, 0], [1, 1]" << endl
				<< "Line: [1, 1], [2, 2]" << endl 
				<< "Line: [2, 2], [0, 0]" << endl;
			string expectedCanvasContentString = expectedCanvasContent.str();
			string canvasContent = canvas.GetCanvasContent();
			BOOST_CHECK_EQUAL(canvasContent, expectedCanvasContentString);			
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()