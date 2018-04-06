#include <iostream>

const int ARRAY_SIZE = 16;

int main()
{
	long long factorials[ARRAY_SIZE];

	factorials[1] = factorials[0] = 1LL;
	
	for (int i = 2; i < ARRAY_SIZE; i++)
		factorials[i] = i * factorials[i - 1];

	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << i << "!\t = " << factorials[i] << std::endl;

	std::cin.get();
	return 0;
}