#pragma once

#include "Signals.h"
#include "FunctionType.h"

struct NoRealRoots {};
struct InfiniteNumberOfRoots {};

typedef boost::variant<NoRealRoots, InfiniteNumberOfRoots, double, std::pair<double, double>> EquationRoots;

class CEquationSolver
{
public:
	CEquationSolver();
	~CEquationSolver();

	typedef sig::signal<void()> SolutionChangeSignal;
	sig::connection DoOnSolutionChange(const SolutionChangeSignal::slot_type & handler);

	std::vector<std::pair<double, double>> GetChartPoints(const double horizontalLimit, const double detalization)const;

	double GetAmplitude()const;
	void SetAmplitude(double a);

	double GetFrequency()const;
	void SetFrequency(double b);

	double GetPhase()const;
	void SetPhase(double c);

	void SetFunctionType(FunctionType newType);
	FunctionType GetFunctionType();
private:
	double m_amplitude = 0;
	double m_frequency = 0;
	double m_phase = 0;
	FunctionType m_function = FunctionType::SIN;

	SolutionChangeSignal m_solutionChanged;
};

