#include "stdafx.h"
#include <boost/format.hpp>
#include "../gumball_machine/GumBallMachineWithState.h"

using namespace std;

struct Gumball_machine_with_state_
{
	stringstream outputStream;
	with_state::CGumballMachine machine{ 3 };
};

BOOST_FIXTURE_TEST_SUITE(Gumball_machine_with_state, Gumball_machine_with_state_)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(has_right_number_of_gumballs_and_state)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 3 gumballs
Machine is waiting for quarter
)";
			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(does_not_change_state_if_we_turn_crank)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 3 gumballs
Machine is waiting for quarter
)";
			machine.TurnCrank();
			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(change_state_to_has_quarter_if_we_insert_quarter)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 3 gumballs
Machine is waiting for turn of crank
)";
			machine.InsertQuarter();
			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(reduces_balls_count_and_change_state_to_no_quarter_if_we_turn_crank_after_inserting_quarter)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 2 gumballs
Machine is waiting for quarter
)";
			machine.InsertQuarter();
			machine.TurnCrank();
			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(does_not_change_change_state_and_balls_count_if_we_insert_and_eject_quarter)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 3 gumballs
Machine is waiting for quarter
)";
			machine.InsertQuarter();
			machine.EjectQuarter();
			machine.TurnCrank();

			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(change_state_once_even_if_we_insert_quarter_many_times)
		{
			string expectedOutput = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 3 gumballs
Machine is waiting for turn of crank
)";
			machine.InsertQuarter();
			machine.InsertQuarter();
			machine.InsertQuarter();

			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutput, outputStream.str());
		}

		BOOST_AUTO_TEST_CASE(change_state_to_sold_out_if_we_sell_all_gumballs)
		{
			string expectedOutputOne = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 2 gumballs
Machine is waiting for quarter
)";

			string expectedOutputTwo = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 1 gumball
Machine is waiting for quarter
)";

			string expectedOutputLast = R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: 0 gumballs
Machine is sold out
)";

			machine.InsertQuarter();
			machine.TurnCrank();
			outputStream << machine.ToString();

			BOOST_CHECK_EQUAL(expectedOutputOne, outputStream.str());
			outputStream.str("");

			machine.InsertQuarter();
			machine.TurnCrank();
			outputStream << machine.ToString();

			BOOST_CHECK_EQUAL(expectedOutputTwo, outputStream.str());
			outputStream.str("");

			machine.InsertQuarter();
			machine.TurnCrank();
			machine.InsertQuarter();
			machine.TurnCrank();			

			outputStream << machine.ToString();
			BOOST_CHECK_EQUAL(expectedOutputLast, outputStream.str());
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()