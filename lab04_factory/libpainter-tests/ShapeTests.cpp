#include "stdafx.h"
#include "../libpainter/Shape.h"
#include "../libpainter/Triangle.h"

using namespace std;

struct Triangle_
{
	CTriangle triangle = CTriangle({ 0, 0 }, { 1, 1 }, { 2, 2 });
};

BOOST_FIXTURE_TEST_SUITE(Triangle, Triangle_)

	BOOST_AUTO_TEST_SUITE(when_created)
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
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()