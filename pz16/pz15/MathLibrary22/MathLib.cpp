#include "pch.h"
#include "framework.h"
#include "MathLib.h"
#include <cmath>
#include <math.h>

namespace MathLibrary
{
	double Arithmetic::Add(double a, double b)
	{
		return a + b;
	}
	double Arithmetic::Subtract(double a, double b)
	{
		return a - b;
	}
	double Arithmetic::Multiply(double a, double b)
	{
		return a * b;
	}
	double Arithmetic::Divide(double a, double b)
	{
		return a / b;
	}
	double Arithmetic::Stepen(double a, double b)
	{
		return pow(a, b);
	}
	double Arithmetic::Koren(double a, double b)
	{
		return sqrt(a);
		return sqrt(b);
	}
}