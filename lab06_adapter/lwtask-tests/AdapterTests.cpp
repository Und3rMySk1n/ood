#include "stdafx.h"

using namespace std;

struct Adapter_
{
	
};

BOOST_FIXTURE_TEST_SUITE(Adapter, Adapter_)
	BOOST_AUTO_TEST_SUITE(has_tests)
		BOOST_AUTO_TEST_CASE(and_they_works)
		{
			BOOST_CHECK(true);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()