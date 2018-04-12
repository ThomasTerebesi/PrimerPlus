#include <iostream>
#include <array>

const int ARRAY_SIZE = 101;

int main()
{
	std::array<long double, ARRAY_SIZE> factorials;

	factorials[1] = factorials[0] = 1.0;
	std::cout << "0!\t = " << factorials[0] << std::endl;
	std::cout << "1!\t = " << factorials[1] << std::endl;

	for (int i = 2; i < ARRAY_SIZE; i++)
	{
		factorials[i] = i * factorials[i - 1];
		std::cout << i << "!\t = " << factorials[i] << std::endl;
	}

	std::cin.get();
	return 0;
}