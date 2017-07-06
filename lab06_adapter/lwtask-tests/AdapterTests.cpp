#include "stdafx.h"
#include "../lwtask/ShapeDrawingLib.h"
#include "../lwtask/ShapeDrawingAdapter.h"
#include "../lwtask/ShapeDrawingClassAdapter.h"

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
				R"(SetColor #000000
MoveTo (0, 0)
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
			R"(SetColor #000000
MoveTo (0, 0)
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
	shape_drawing_lib::CRectangle greenRectangle{ { 0, 0 }, 5, 10, 65280 }; // #00ff00
	shape_drawing_lib::CTriangle orangeTriangle{ { 0, 0 },{ 1, 1 },{ 2, 2 }, 16748544 }; // #ff9000


	shape_drawing_lib::CCanvasPainter painter{ canvas };
};

BOOST_FIXTURE_TEST_SUITE(Painter, Painter_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(can_draw_rectangles)
		{
			painter.Draw(rectangle);
			auto expectedCanvasContent =
			R"(SetColor #000000
MoveTo (0, 0)
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
				R"(SetColor #000000
MoveTo (0, 0)
LineTo (1, 1)
LineTo (2, 2)
LineTo (0, 0)
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}

		BOOST_AUTO_TEST_CASE(can_draw_colored_rectangles)
		{
			painter.Draw(greenRectangle);
			auto expectedCanvasContent =
				R"(SetColor #00ff00
MoveTo (0, 0)
LineTo (5, 0)
LineTo (5, 10)
LineTo (0, 10)
LineTo (0, 0)
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}

		BOOST_AUTO_TEST_CASE(can_draw_colored_triangles)
		{
			painter.Draw(orangeTriangle);
			auto expectedCanvasContent =
				R"(SetColor #ff9000
MoveTo (0, 0)
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
	shape_drawing_lib::CRectangle greenRectangle{ { 0, 0 }, 5, 10, 65280 }; // #00ff00
	shape_drawing_lib::CTriangle orangeTriangle{ { 0, 0 },{ 1, 1 },{ 2, 2 }, 16748544 }; // #ff9000


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
  <line fromX="0" fromY="0" toX="5" toY="0">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
  <line fromX="5" fromY="0" toX="5" toY="10">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
  <line fromX="5" fromY="10" toX="0" toY="10">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
  <line fromX="0" fromY="10" toX="0" toY="0">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
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
  <line fromX="0" fromY="0" toX="1" toY="1">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
  <line fromX="1" fromY="1" toX="2" toY="2">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
  <line fromX="2" fromY="2" toX="0" toY="0">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
</draw>
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}

		BOOST_AUTO_TEST_CASE(can_draw_colored_rectangles_on_renderer)
		{
			renderer.BeginDraw();
			painter.Draw(greenRectangle);
			renderer.EndDraw();

			auto expectedCanvasContent =
				R"(<draw>
  <line fromX="0" fromY="0" toX="5" toY="0">
    <color r="0.0" g="1.0" b="0.0" a="1.0" />
  </line>
  <line fromX="5" fromY="0" toX="5" toY="10">
    <color r="0.0" g="1.0" b="0.0" a="1.0" />
  </line>
  <line fromX="5" fromY="10" toX="0" toY="10">
    <color r="0.0" g="1.0" b="0.0" a="1.0" />
  </line>
  <line fromX="0" fromY="10" toX="0" toY="0">
    <color r="0.0" g="1.0" b="0.0" a="1.0" />
  </line>
</draw>
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}

		BOOST_AUTO_TEST_CASE(can_draw_colored_triangles_on_renderer)
		{
			renderer.BeginDraw();
			painter.Draw(orangeTriangle);
			renderer.EndDraw();

			auto expectedCanvasContent =
				R"(<draw>
  <line fromX="0" fromY="0" toX="1" toY="1">
    <color r="1.0" g="0.6" b="0.0" a="1.0" />
  </line>
  <line fromX="1" fromY="1" toX="2" toY="2">
    <color r="1.0" g="0.6" b="0.0" a="1.0" />
  </line>
  <line fromX="2" fromY="2" toX="0" toY="0">
    <color r="1.0" g="0.6" b="0.0" a="1.0" />
  </line>
</draw>
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()





struct CanvasClassAdapter_
{
	stringstream outputStream;
	CShapeDrawingClassAdapter canvas{ outputStream };

	shape_drawing_lib::CRectangle rectangle{ { 0, 0 }, 5, 10 };
	shape_drawing_lib::CTriangle triangle{ { 0, 0 },{ 1, 1 },{ 2, 2 } };
	shape_drawing_lib::CRectangle greenRectangle{ { 0, 0 }, 5, 10, 65280 }; // #00ff00
	shape_drawing_lib::CTriangle orangeTriangle{ { 0, 0 },{ 1, 1 },{ 2, 2 }, 16748544 }; // #ff9000


	shape_drawing_lib::CCanvasPainter painter{ canvas };
};

BOOST_FIXTURE_TEST_SUITE(CanvasClassAdapter, CanvasClassAdapter_)
	BOOST_AUTO_TEST_SUITE(when_created)
	BOOST_AUTO_TEST_CASE(can_draw_rectangles_on_renderer)
	{
		canvas.BeginDraw();
		painter.Draw(rectangle);
		canvas.EndDraw();

		auto expectedCanvasContent =
			R"(<draw>
  <line fromX="0" fromY="0" toX="5" toY="0">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
  <line fromX="5" fromY="0" toX="5" toY="10">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
  <line fromX="5" fromY="10" toX="0" toY="10">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
  <line fromX="0" fromY="10" toX="0" toY="0">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
</draw>
)";
		BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
	}

	BOOST_AUTO_TEST_CASE(can_draw_triangles_on_renderer)
	{
		canvas.BeginDraw();
		painter.Draw(triangle);
		canvas.EndDraw();

		auto expectedCanvasContent =
			R"(<draw>
  <line fromX="0" fromY="0" toX="1" toY="1">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
  <line fromX="1" fromY="1" toX="2" toY="2">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
  <line fromX="2" fromY="2" toX="0" toY="0">
    <color r="0.0" g="0.0" b="0.0" a="1.0" />
  </line>
</draw>
)";
		BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
	}

	BOOST_AUTO_TEST_CASE(can_draw_colored_rectangles_on_renderer)
	{
		canvas.BeginDraw();
		painter.Draw(greenRectangle);
		canvas.EndDraw();

		auto expectedCanvasContent =
			R"(<draw>
  <line fromX="0" fromY="0" toX="5" toY="0">
    <color r="0.0" g="1.0" b="0.0" a="1.0" />
  </line>
  <line fromX="5" fromY="0" toX="5" toY="10">
    <color r="0.0" g="1.0" b="0.0" a="1.0" />
  </line>
  <line fromX="5" fromY="10" toX="0" toY="10">
    <color r="0.0" g="1.0" b="0.0" a="1.0" />
  </line>
  <line fromX="0" fromY="10" toX="0" toY="0">
    <color r="0.0" g="1.0" b="0.0" a="1.0" />
  </line>
</draw>
)";
		BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
	}

	BOOST_AUTO_TEST_CASE(can_draw_colored_triangles_on_renderer)
	{
		canvas.BeginDraw();
		painter.Draw(orangeTriangle);
		canvas.EndDraw();

		auto expectedCanvasContent =
			R"(<draw>
  <line fromX="0" fromY="0" toX="1" toY="1">
    <color r="1.0" g="0.6" b="0.0" a="1.0" />
  </line>
  <line fromX="1" fromY="1" toX="2" toY="2">
    <color r="1.0" g="0.6" b="0.0" a="1.0" />
  </line>
  <line fromX="2" fromY="2" toX="0" toY="0">
    <color r="1.0" g="0.6" b="0.0" a="1.0" />
  </line>
</draw>
)";
		BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
	}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()