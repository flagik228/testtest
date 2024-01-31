#pragma once

namespace MathLibrary
{
	class Arithmetic
	{
	public:
		//a + b
		static double Add(double a, double b);
		//a - b
		static double Subtract(double a, double b);
		//a * b
		static double Multiply(double a, double b);
		//a / b
		static double Divide(double a, double b);
		//a в степень  b
		static double Stepen(double a, double b);
		//a корень b
		static double Koren(double a, double b);
	};

}