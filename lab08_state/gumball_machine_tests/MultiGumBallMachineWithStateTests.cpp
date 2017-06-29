#include "stdafx.h"
#include <boost/format.hpp>
#include "../gumball_machine/MultiGumBallMachineWithState.h"

using namespace std;

struct Multi_gumball_machine_with_state_
{
	stringstream outputStream;
	multi_with_state::CMultiGumballMachine machine{ 3 };
};

BOOST_FIXTURE_TEST_SUITE(Multi_gumball_machine_with_state, Multi_gumball_machine_with_state_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(has_right_number_of_gumballs_and_quarters_and_state)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Multi Gumball Model #2016 (with state)
Inventory: 3 gumballs
Quarters: 0
Machine is waiting for quarter
)";
			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(increases_number_of_quarters_ang_change_state_if_we_insert_coin)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Multi Gumball Model #2016 (with state)
Inventory: 3 gumballs
Quarters: 1
Machine is waiting for turn of crank
)";
			machine.InsertQuarter();
			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(can_not_carry_more_than_5_coins)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Multi Gumball Model #2016 (with state)
Inventory: 3 gumballs
Quarters: 5
Machine is waiting for turn of crank
)";
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.InsertQuarter();

			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(returns_all_quarters)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Multi Gumball Model #2016 (with state)
Inventory: 3 gumballs
Quarters: 0
Machine is waiting for quarter
)";
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.EjectQuarter();

			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(returns_all_quarters_even_if_machine_is_in_sold_out_state)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Multi Gumball Model #2016 (with state)
Inventory: 0 gumballs
Quarters: 0
Machine is sold out
)";
			machine.InsertQuarter();
			machine.TurnCrank();
			machine.InsertQuarter();
			machine.TurnCrank();
			machine.InsertQuarter();
			machine.TurnCrank();
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.EjectQuarter();

			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()