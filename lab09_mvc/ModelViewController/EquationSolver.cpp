#include "stdafx.h"
#include "EquationSolver.h"
#include "FunctionType.h"
#include <cmath>

using namespace std;

CEquationSolver::CEquationSolver()
{
}


CEquationSolver::~CEquationSolver()
{
}

sig::connection CEquationSolver::DoOnSolutionChange(const SolutionChangeSignal::slot_type & handler)
{
	return m_solutionChanged.connect(handler);
}

vector<std::pair<double, double>> CEquationSolver::GetChartPoints(const double horizontalLimit, const double detalization)const
{
	vector<std::pair<double, double>> result;

	double step = (double)(horizontalLimit / detalization);
	double x = 0;

	for (int i = 0; i <= detalization; i++)
	{
		std::pair<double, double> point;
		point.first = (double)x;
		point.second = (m_function == FunctionType::SIN) ? m_amplitude * sin(m_frequency * x + m_phase) : m_amplitude * cos(m_frequency * x + m_phase);

		result.push_back(point);
		x += step;
	}
	

	return result;
}

double CEquationSolver::GetAmplitude() const
{
	return m_amplitude;
}

void CEquationSolver::SetAmplitude(double a)
{
	if (m_amplitude != a)
	{
		m_amplitude = a;
		m_solutionChanged();
	}
}

double CEquationSolver::GetFrequency() const
{
	return m_frequency;
}

void CEquationSolver::SetFrequency(double b)
{
	if (m_frequency != b)
	{
		m_frequency = b;
		m_solutionChanged();
	}
}

double CEquationSolver::GetPhase() const
{
	return m_phase;
}

void CEquationSolver::SetPhase(double c)
{
	if (m_phase != c)
	{
		m_phase = c;
		m_solutionChanged();
	}
}

void CEquationSolver::SetFunctionType(FunctionType newType)
{
	m_function = newType;
	m_solutionChanged();
}

FunctionType CEquationSolver::GetFunctionType()
{
	return m_function;
}