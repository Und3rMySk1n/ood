#include "stdafx.h"
#include "../libpainter/Shape.h"
#include "../libpainter/Triangle.h"
#include "../libpainter/Rectangle.h"
#include "../libpainter/RegularPolygon.h"
#include "../libpainter/Ellipse.h"
#include "../libpainter/Canvas.h"
#include <iostream>
#include <sstream>
#include <boost/test/floating_point_comparison.hpp>


using namespace std;

struct Triangle_
{
	stringstream outputStream;
	CCanvas canvas{ outputStream };
	CTriangle triangle{ Color::black, { 0, 0 }, { 1, 1 }, { 2, 2 } };
};

BOOST_FIXTURE_TEST_SUITE(Triangle, Triangle_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(has_custom_color)
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
	CRectangle rectangle{ Color::green, { (float)0.1, (float)0.2 }, { (float)2.3, (float)2.4 } };
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, Rectangle_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(has_custom_color)
		{
			BOOST_CHECK_EQUAL(rectangle.GetColor(), Color::green);
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


struct Ellipse_
{
	stringstream outputStream;
	CCanvas canvas{ outputStream };
	CEllipse ellipse{ Color::green, {0, 1}, (float)5, (float)10 };
};

BOOST_FIXTURE_TEST_SUITE(Ellipse, Ellipse_)
	BOOST_AUTO_TEST_SUITE(when_created_with_green_color)
		BOOST_AUTO_TEST_CASE(has_custom_color)
		{
			BOOST_CHECK_EQUAL(ellipse.GetColor(), Color::green);
		}
		BOOST_AUTO_TEST_CASE(can_change_color)
		{
			ellipse.SetColor(Color::pink);
			BOOST_CHECK_EQUAL(ellipse.GetColor(), Color::pink);
		}
		BOOST_AUTO_TEST_CASE(returns_its_vertices)
		{
			Vertex center = ellipse.GetCenter();
			float width = ellipse.GetHorizontalRadius();
			float height = ellipse.GetVerticalRadius();

			BOOST_CHECK_EQUAL(center.x, 0);
			BOOST_CHECK_EQUAL(center.y, 1);
			BOOST_CHECK_EQUAL(width, 5);
			BOOST_CHECK_EQUAL(height, 10);
		}
		BOOST_AUTO_TEST_CASE(can_draw_itself_on_canvas)
		{
			ellipse.Draw(canvas);
			auto expectedCanvasContent = 
				R"(Ellipse: [0, 1], Width: 5, Height: 10
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()



struct RegularPolygon_
{
	stringstream outputStream;
	CCanvas canvas{ outputStream };
	CRegularPolygon polygon{ Color::pink, {5, 5}, 10, 5 };
};

	BOOST_FIXTURE_TEST_SUITE(Regular_polygon, RegularPolygon_)
		BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(has_custom_color)
		{
			BOOST_CHECK_EQUAL(polygon.GetColor(), Color::pink);
		}
		BOOST_AUTO_TEST_CASE(can_change_color)
		{
			polygon.SetColor(Color::red);
			BOOST_CHECK_EQUAL(polygon.GetColor(), Color::red);
		}
		BOOST_AUTO_TEST_CASE(returns_its_vertices)
		{
			Vertex center = polygon.GetCenter();
			float radius = polygon.GetRadius();
			int vertexCount = polygon.GetVertexCount();

			BOOST_CHECK_EQUAL(center.x, 5);
			BOOST_CHECK_EQUAL(center.y, 5);
			BOOST_CHECK_CLOSE(radius, 10.0, 0.0001);
			BOOST_CHECK_EQUAL(vertexCount, 5);
		}
		BOOST_AUTO_TEST_CASE(can_draw_itself_on_canvas)
		{
			BOOST_CHECK(true);
			polygon.Draw(canvas);
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
BOOST_AUTO_TEST_SUITE_END()