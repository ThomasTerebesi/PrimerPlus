#include <iostream>

const int ARRAY_SIZE = 8;

int sumArr(const int* begin, const int* end);

int main()
{
	int cookies[ARRAY_SIZE] = { 1, 2, 4, 8, 16, 32, 64, 128 };

	int sum = sumArr(cookies, cookies + ARRAY_SIZE);
	std::cout << "Total cookies eaten: " << sum << std::endl;
	
	sum = sumArr(cookies, cookies + 3);
	std::cout << "First three eaters ate " << sum << " cookies." << std::endl;

	sum = sumArr(cookies + 4, cookies + 8);
	std::cout << "Last four eaters ate " << sum << " cookies." << std::endl;

	std::cin.get();
	return 0;
}

int sumArr(const int* begin, const int* end)
{
	const int* pt;
	int total = 0;

	for (pt = begin; pt != end; pt++)
		total = total + *pt;

	return total;
}