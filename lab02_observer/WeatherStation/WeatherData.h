#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Observer.h"
#include <string>

using namespace std;

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

struct SStats
{
	string name;
	double minValue = std::numeric_limits<double>::infinity();
	double maxValue = -std::numeric_limits<double>::infinity();
	double accumulatedValue = 0;

	SStats(string structName) :
		name(structName)
	{
	}
};

class CDisplay: public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/	

	void GetStats(SStats &innerValue, double receivedValue)
	{
		if (innerValue.minValue > receivedValue)
		{
			innerValue.minValue = receivedValue;
		}
		if (innerValue.maxValue < receivedValue)
		{
			innerValue.maxValue = receivedValue;
		}
		innerValue.accumulatedValue += receivedValue;
	}

	void PrintStats(SStats const &innerValue)
	{
		std::cout << "Max " << innerValue.name  << " " << innerValue.maxValue << std::endl;
		std::cout << "Min " << innerValue.name << " " << innerValue.minValue << std::endl;
		std::cout << "Average " << innerValue.name << " " << (innerValue.accumulatedValue / m_countAcc) << std::endl;
		std::cout << "----------------" << std::endl;
	}

	void Update(SWeatherInfo const& data) override
	{
		++m_countAcc;

		GetStats(m_temperature, data.temperature);
		PrintStats(m_temperature);

		GetStats(m_humidity, data.humidity);
		PrintStats(m_humidity);

		GetStats(m_pressure, data.pressure);
		PrintStats(m_pressure);
	}

	SStats m_temperature = { "temperature"};
	SStats m_humidity = { "humidity" };
	SStats m_pressure = { "pressure" };
	unsigned m_countAcc = 0;
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	double GetTemperature()const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity()const
	{
		return m_humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;	
};
