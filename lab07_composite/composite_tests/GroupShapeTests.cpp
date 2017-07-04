#include "stdafx.h"
#include "../composite/GroupShape.h"

using namespace std;

struct Group_shape_
{	
};

BOOST_FIXTURE_TEST_SUITE(Group_shape, Group_shape_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(has_working_tests)
		{
			BOOST_CHECK(true);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()