#pragma once
#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL }; // RECT for rectangular mode, POL for polar mode

	private:
		double x;	// horizontal value
		double y;	// vertical value
		Mode mode;	// RECT or POL

		double CalculateMag(double x, double y) const;
		double CalculateAng(double x, double y) const;
		double CalculateX(double mag, double ang) const;
		double CalculateY(double mag, double ang) const;


	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void Reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double XVal() const { return x; }				// report x value
		double YVal() const { return y; }				// report y value
		double MagVal() const { return CalculateMag(x, y); }	// report magnitude
		double AngVal() const { return CalculateAng(x, y); }	// report angle
		void PolarMode();
		void RectMode();
		
		// operator overloading
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		// friend methods
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream & operator<<(std::ostream & os, const Vector & v);
	};
}