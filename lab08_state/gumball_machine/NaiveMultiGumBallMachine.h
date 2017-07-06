#pragma once

#include <iostream>
#include <boost/format.hpp>

namespace naive
{
	class CMultiGumballMachine
	{
	public:
		enum class State
		{
			SoldOut,		// Жвачка закончилась
			NoQuarter,		// Нет монетки
			HasQuarters,		// Есть монеты
			Sold,			// Монетка выдана
		};

		CMultiGumballMachine(unsigned count)
			: m_count(count)
			, m_state(count > 0 ? State::NoQuarter : State::SoldOut)
		{
		}

		void InsertQuarter()
		{
			using namespace std;
			switch (m_state)
			{
			case State::SoldOut:
				cout << "You can't insert a quarter, the machine is sold out\n";
				break;
			case State::NoQuarter:
				cout << "You inserted a quarter\n";
				m_quarters = 1;
				m_state = State::HasQuarters;
				break;
			case State::HasQuarters:
				if (m_quarters < 5)
				{
					++m_quarters;
					cout << "You inserted a quarter\n";
				}
				else
				{
					cout << "You can't insert more quarters\n";
				}
				break;
			case State::Sold:
				cout << "Please wait, we're already giving you a gumball\n";
				break;
			}
		}

		void EjectQuarter()
		{
			using namespace std;
			switch (m_state)
			{
			case State::HasQuarters:
				cout << "Quarters returned\n";
				m_quarters = 0;
				m_state = State::NoQuarter;
				break;
			case State::NoQuarter:
				cout << "You haven't inserted a quarter\n";
				break;
			case State::Sold:
				cout << "Sorry you already turned the crank\n";
				break;
			case State::SoldOut:
				if ((m_quarters) != 0)
				{
					m_quarters = 0;
					cout << "Quarters returned\n";
				}
				else
				{
					cout << "You can't eject, you haven't inserted quarters yet\n";
				}
				break;
			}
		}

		void TurnCrank()
		{
			using namespace std;
			switch (m_state)
			{
			case State::SoldOut:
				cout << "You turned but there's no gumballs\n";
				break;
			case State::NoQuarter:
				cout << "You turned but there's no quarter\n";
				break;
			case State::HasQuarters:
				cout << "You turned...\n";
				m_state = State::Sold;
				Dispense();
				break;
			case State::Sold:
				cout << "Turning twice doesn't get you another gumball\n";
				break;
			}
		}

		void Refill(unsigned numBalls)
		{
			m_count = numBalls;
			m_state = numBalls > 0 ? State::NoQuarter : State::SoldOut;
		}

		std::string ToString()const
		{
			std::string state =
				(m_state == State::SoldOut) ? "sold out" :
				(m_state == State::NoQuarter) ? "waiting for quarter" :
				(m_state == State::HasQuarters) ? "waiting for turn of crank"
				: "delivering a gumball";
			auto fmt = boost::format(R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016
Inventory: %1% gumball%2%
Quarters: %3%
Machine is %4%
)");
			return (fmt % m_count % (m_count != 1 ? "s" : "") % m_quarters % state).str();
		}

	private:
		void Dispense()
		{
			using namespace std;
			switch (m_state)
			{
			case State::Sold:
				cout << "A gumball comes rolling out the slot\n";
				--m_quarters;
				--m_count;
				if (m_count == 0)
				{
					cout << "Oops, out of gumballs\n";
					m_state = State::SoldOut;
				}
				else
				{
					if (m_quarters == 0)
					{
						m_state = State::HasQuarters;
					}
					else
					{
						m_state = State::NoQuarter;
					}
				}
				break;
			case State::NoQuarter:
				cout << "You need to pay first\n";
				break;
			case State::SoldOut:
			case State::HasQuarters:
				cout << "No gumball dispensed\n";
				break;
			}
		}

		unsigned m_count;	 // Количество шариков
		int m_quarters = 0;  // Количество монет
		State m_state = State::SoldOut;
	};
}