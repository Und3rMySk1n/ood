#pragma once

#include "IBeverage.h"

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string & description)
		:m_description(description)
	{}

	std::string GetDescription()const override final
	{
		return m_description;
	}
private:
	std::string m_description;
};

// Размер порции кофе
enum class CoffeeSize
{
	Standard,
	Double
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee", CoffeeSize size = CoffeeSize::Standard)
		:CBeverage(description) 
		, m_size(size)
	{}

	double GetCost() const override 
	{
		return 60; 
	}
protected:
	CoffeeSize m_size;
};

// Капуччино
class CCapuccino : public CCoffee
{
public:
	CCapuccino(CoffeeSize size = CoffeeSize::Standard)
		: CCoffee("Capuccino", size)
	{}

	double GetCost() const override 
	{
		return (m_size == CoffeeSize::Double) ? 120 : 80;
	}
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte(CoffeeSize size = CoffeeSize::Standard)
		:CCoffee("Latte", size)
	{}

	double GetCost() const override 
	{
		return (m_size == CoffeeSize::Double) ? 130 : 90;
	}
};

// Сорта чая
enum class TeaType
{
	Black,
	Green,
	Carcade,
	Mate
};

// Чай
class CTea : public CBeverage
{
public:
	CTea(TeaType type = TeaType::Black)
		: CBeverage("Tea")
		, m_type(type)
	{}

	double GetCost() const override 
	{
		return 30; 
	}
private:
	TeaType m_type;
};

// Размер порции молочного коктейля
enum class MilkShakeSize
{
	Small,
	Medium,
	Large
};

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(MilkShakeSize size = MilkShakeSize::Small)
		: CBeverage("Milkshake")
		, m_size(size)
	{}

	double GetCost() const override 
	{ 
		if (m_size == MilkShakeSize::Medium)
		{
			return 60;
		}
		else if (m_size == MilkShakeSize::Large)
		{
			return 80;
		}
		return 50;
	}
private:
	MilkShakeSize m_size;
};
