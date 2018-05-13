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
		double mag;	// length of vector
		double ang;	// direction of vector in degrees
		Mode mode;	// RECT or POL
		
		// private methods for setting values
		void SetMag();
		void SetAng();
		void SetX();
		void SetY();

	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void Reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double XVal() const { return x; }		// report x value
		double YVal() const { return y; }		// report y value
		double MagVal() const { return mag; }	// report magnitude
		double AngVal() const { return ang; }	// report angle
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