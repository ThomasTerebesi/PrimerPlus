#include <iostream>

void cheers(int);
double cube(double x);

int main()
{

	cheers(5);

	std::cout << "Give me a number: ";
	double side;
	std::cin >> side;
	
	double volume = cube(side);

	std::cout << "A " << side << "-foot cube has a volume of ";
	std::cout << volume << " cubic feet.\n";

	cheers(cube(2));

	std::cin.get();
	std::cin.get();
	return 0;
}

void cheers(int n)
{
	for (int i = 0; i < n; i++)
		std::cout << "Cheers! ";
	std::cout << std::endl;
}

double cube(double x)
{
	return x * x * x;
}