#include <iostream>

void Countdown(int n);

int main()
{
	Countdown(4);

	std::cin.get();

	return 0;
}

void Countdown(int n)
{
	std::cout << "Counting down ... " << n <<  "\t(n at " << &n << ")" << std::endl;
	
	if (n > 0)
		Countdown(n - 1);

	std::cout << n << ": Kaboom!" << "\t\t(n at " << &n << ")" << std::endl;
}
