#include "stdafx.h"
#include <boost/format.hpp>
#include "../gumball_machine/GumBallMachineWithState.h"

using namespace std;

struct Gumball_machine_with_state_
{
	with_state::CGumballMachine machine{ 5 };
};

BOOST_FIXTURE_TEST_SUITE(Gumball_machine_with_state, Gumball_machine_with_state_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(has_working_tests)
		{
			BOOST_CHECK(true);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()