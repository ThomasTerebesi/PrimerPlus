#include <iostream>

void Oil(int x);

int main()
{
	int texas = 31;
	int year = 2011;

	std::cout << "In main(), texas = " << texas << ", &texas = " << &texas << std::endl;
	std::cout << "In main(), year = " << year << ", &year = " << &year << std::endl;

	Oil(texas);

	std::cout << "In main(), texas = " << texas << ", &texas = " << &texas << std::endl;
	std::cout << "In main(), year = " << year << ", &year = " << &year << std::endl;

	std::cin.get();

	return 0;
}

void Oil(int x)
{
	int texas = 5;

	std::cout << "In Oil(), texas = " << texas << ", &texas = " << &texas << std::endl;
	std::cout << "In Oil(), x = " << x << ", &x = " << &x << std::endl;

	{
		int texas = 113;
		std::cout << "In block, texas = " << texas << ", &texas = " << &texas << std::endl;
		std::cout << "In block, x = " << x << ", &x = " << &x << std::endl;
	}

	std::cout << "Post-block texas = " << texas << ", &texas = " << &texas << std::endl;
}
