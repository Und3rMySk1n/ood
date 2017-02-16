#include <iostream>
#include <memory>
#include <cassert>
#include <vector>
#include <functional>

using namespace std;

void DanceWaltz()
{
	cout << "I dance waltz!" << endl;
}

void DanceMenuet()
{ 
	cout << "I dance menuet!" << endl; 
}

void FlyWithWings()
{ 
	cout << "I'm flying with wings!" << endl; 
}

void QuackQuack() 
{ 
	cout << "Quack Quack!" << endl; 
}

void QuackSqueek() 
{ 
	cout << "Squeek!" << endl; 
}

void NoBehavior()
{
}

class Duck
{
public:
	Duck(function<void()> flyBehavior, function<void()> quackBehavior, function<void()> danceBehavior)
		: m_flyBehavior(flyBehavior)
		, m_quackBehavior(quackBehavior)
		, m_danceBehavior(danceBehavior)
	{		
	}
	void Swim()
	{
		cout << "I'm swimming" << endl;
	}
	void Quack() const
	{
		m_quackBehavior();
	}
	void Fly()
	{
		m_flyBehavior();
	}
	void Dance()
	{
		m_danceBehavior();
	}
	virtual void Display() const = 0;
	virtual ~Duck() {};
private:
	function<void()> m_flyBehavior;
	function<void()> m_quackBehavior;
	function<void()> m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(FlyWithWings, QuackQuack, DanceWaltz)
	{
		
	}

	void Display() const override
	{
		cout << "I'm mallard duck" << endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(NoBehavior, QuackQuack, DanceMenuet)
	{
	}
	void Display() const override
	{
		cout << "I'm redhead duck" << endl;
	}
};
class DeckoyDuck : public Duck
{
public:
	DeckoyDuck()
		: Duck(NoBehavior, QuackSqueek, NoBehavior)
	{
	}
	void Display() const override
	{
		cout << "I'm deckoy duck" << endl;
	}
};
class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(NoBehavior, NoBehavior, NoBehavior)
	{
	}
	void Display() const override
	{
		cout << "I'm rubber duck" << endl;
	}
};

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(NoBehavior, NoBehavior, NoBehavior)
	{
	}
	void Display() const override
	{
		cout << "I'm model duck" << endl;
	}
};

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck & duck)
{
	duck.Quack();
	duck.Dance();
	duck.Fly();
	DrawDuck(duck);
}


void main()
{
	MallardDuck mallarDuck;
	PlayWithDuck(mallarDuck);
	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);
	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);
	DeckoyDuck deckoyDuck;
	PlayWithDuck(deckoyDuck);
	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	PlayWithDuck(modelDuck);
}