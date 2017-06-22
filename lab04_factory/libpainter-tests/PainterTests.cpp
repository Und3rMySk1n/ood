#include "stdafx.h"

#include <sstream>

#include "../libpainter/ShapeFactory.h"
#include "../libpainter/Painter.h"
#include "../libpainter/Designer.h"
#include "../libpainter/Canvas.h"
#include "../libpainter/PictureDraft.h"

using namespace std;

struct Painter_
{	
	stringstream outputStream;
	CCanvas canvas{ outputStream };
	CPainter painter;
	CShapeFactory factory;
	CPictureDraft draft;
	CDesigner designer{ factory };
};

BOOST_FIXTURE_TEST_SUITE(Painter, Painter_)
	BOOST_AUTO_TEST_SUITE(can_paint)
		BOOST_AUTO_TEST_CASE(draft_with_one_shape)
		{
			stringstream input;
			input << "triangle red 0 0 1 1 2 2\n";
			draft = designer.CreateDraft(input);
			painter.DrawPicture(draft, canvas);
			auto expectedCanvasContent =
				R"(Line: [0, 0], [1, 1]
Line: [1, 1], [2, 2]
Line: [2, 2], [0, 0]
)";
			BOOST_CHECK_EQUAL(outputStream.str(), expectedCanvasContent);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()