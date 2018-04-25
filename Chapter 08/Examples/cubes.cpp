#include <iostream>

double Cube(double a);
double RefCube(double & ra);

int main()
{
	double x = 3.0;

	std::cout << Cube(x);
	std::cout << " = cube of " << x << std::endl;

	std::cout << RefCube(x);
	std::cout << " = cube of " << x << std::endl;

	std::cin.get();

	return 0;
}

double Cube(double a)
{
	a *= a * a;
	return a;
}

// x is changed; could be avoided by using a const reference
double RefCube(double & ra) 
{
	ra *= ra * ra;
	return ra;
}
