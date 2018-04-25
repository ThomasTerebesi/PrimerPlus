#include <iostream>

// function template prototype
template <typename T>
void Swap(T &a, T &b);

int main()
{
	int i = 10;
	int j = 20;

	std::cout << "i, j = " << i << ", " << j << "." << std::endl;
	std::cout << "Using compiler-generated int swapper:" << std::endl;
	Swap(i, j); // generates void Swap(int &, int &)
	std::cout << "After the swap, i, j = " << i << ", " << j << "." << std::endl;


	double x = 24.5;
	double y = 81.7;

	std::cout << "x, y = " << x << ", " << y << "." << std::endl;
	std::cout << "Using compiler-generated double swapper:" << std::endl;
	Swap(x, y); // generates void Swap(double &, double &)
	std::cout << "After the swap, x, y = " << x << ", " << y << "." << std::endl;

	std::cin.get();

	return 0;
}

// function template definition
template<typename T>
void Swap(T & a, T & b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}
