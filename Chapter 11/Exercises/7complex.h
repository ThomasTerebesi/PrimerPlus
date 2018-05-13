#pragma once

#include <iostream>

class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex();
	Complex(double a, double b);
	~Complex();
	friend Complex operator+(const Complex & c1, const Complex & c2);
	friend Complex operator-(const Complex & c1, const Complex & c2);
	friend Complex operator*(const Complex & c1, const Complex & c2);
	friend Complex operator*(double d, const Complex & c);
	friend Complex operator*(const Complex & c, double d);
	friend Complex operator~(const Complex c);
	friend std::istream & operator>>(std::istream & is, Complex & c);
	friend std::ostream & operator<<(std::ostream & os, const Complex & c);
};