// compile with stacktp.h

#include <iostream>
#include "stacktp.h"

template <template <typename T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {};
	// assumes the thing class has Push() and Pop() members
	bool Push(int a, double x) { return s1.Push(a) && s2.Push(x); }
	bool Pop(int & a, double & x) { return s1.Pop(a) && s2.Pop(x); }
};

int main()
{
	Crab<Stack> nebula;		// Stack must match template <typename T> class Thing

	int ni;
	double nb;

	std::cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):" << std::endl;
	while (std::cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.Push(ni, nb))
			break;
	}

	std::cout << std::endl;

	while (nebula.Pop(ni, nb))
		std::cout << ni << ", " << nb << std::endl;

	std::cout << "\nDone." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}