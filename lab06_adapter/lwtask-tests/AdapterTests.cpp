#include "stdafx.h"
#include "../lwtask/ShapeDrawingLib.h"
#include "../lwtask/ShapeDrawingAdapter.h"

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


struct Painter_
{
	stringstream outputStream;
	graphics_lib::CCanvas canvas{ outputStream };
	shape_drawing_lib::CRectangle rectangle{ { 0, 0 }, 5, 10 };
	shape_drawing_lib::CTriangle triangle{ { 0, 0 },{ 1, 1 },{ 2, 2 } };
	shape_drawing_lib::CCanvasPainter painter{ canvas };
};

BOOST_FIXTURE_TEST_SUITE(Painter, Painter_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(can_draw_rectangles)
		{
			painter.Draw(rectangle);
			auto expectedCanvasContent =
			R"(MoveTo (0, 0)
LineTo (5, 0)
LineTo (5, 10)
LineTo (0, 10)
LineTo (0, 0)
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}

		BOOST_AUTO_TEST_CASE(can_draw_triangles)
		{
			painter.Draw(triangle);
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


struct CanvasAdapter_
{
	stringstream outputStream;
	modern_graphics_lib::CModernGraphicsRenderer renderer{ outputStream };
	shape_drawing_adapter::CCanvasAdapter canvasAdapter{ renderer };

	shape_drawing_lib::CRectangle rectangle{ { 0, 0 }, 5, 10 };
	shape_drawing_lib::CTriangle triangle{ { 0, 0 },{ 1, 1 },{ 2, 2 } };
	shape_drawing_lib::CCanvasPainter painter{ canvasAdapter };
};

BOOST_FIXTURE_TEST_SUITE(CanvasAdapter, CanvasAdapter_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(can_draw_rectangles_on_renderer)
		{
			renderer.BeginDraw();
			painter.Draw(rectangle);
			renderer.EndDraw();

			auto expectedCanvasContent =
				R"(<draw>
  <line fromX="0" fromY="0" toX="5" toY="0"/>
  <line fromX="5" fromY="0" toX="5" toY="10"/>
  <line fromX="5" fromY="10" toX="0" toY="10"/>
  <line fromX="0" fromY="10" toX="0" toY="0"/>
</draw>
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}		

		BOOST_AUTO_TEST_CASE(can_draw_triangles_on_renderer)
		{
			renderer.BeginDraw();
			painter.Draw(triangle);
			renderer.EndDraw();

			auto expectedCanvasContent =
		R"(<draw>
  <line fromX="0" fromY="0" toX="1" toY="1"/>
  <line fromX="1" fromY="1" toX="2" toY="2"/>
  <line fromX="2" fromY="2" toX="0" toY="0"/>
</draw>
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()