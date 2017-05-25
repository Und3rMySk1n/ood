#include "stdafx.h"
#include "../libpainter/ShapeFactory.h"

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
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()