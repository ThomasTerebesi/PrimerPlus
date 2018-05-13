#include "7complex.h"

Complex::Complex()
{
	real = 0.0;
	imaginary = 0.0;
}

Complex::Complex(double a, double b)
{
	real = a;
	imaginary = b;
}

Complex::~Complex()
{
}

Complex operator+(const Complex & c1, const Complex & c2)
{
	return Complex((c1.real + c2.real), (c1.imaginary + c2.imaginary));
}

Complex operator-(const Complex & c1, const Complex & c2)
{
	return Complex((c1.real - c2.real), (c1.imaginary - c2.imaginary));
}

Complex operator*(const Complex & c1, const Complex & c2)
{
	double r = c1.real * c2.real - c1.imaginary * c2.imaginary;
	double i = c1.real * c2.imaginary + c1.imaginary * c2.real;
	return Complex(r, i);
}

Complex operator*(double d, const Complex & c)
{
	return Complex(d * c.real, d * c.imaginary);
}

Complex operator*(const Complex & c, double d)
{
	return d * c;
}

Complex operator~(const Complex c)
{
	return Complex(c.real, -c.imaginary);
}

std::istream & operator>>(std::istream & is, Complex & c)
{
	std::cout << "real: ";
	is >> c.real;
	std::cout << "imaginary: ";
	is >> c.imaginary;
	return is;
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
	os << "(" << c.real << ", " << c.imaginary << "i)";
	return os;
}


