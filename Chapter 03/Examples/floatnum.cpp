#include <iostream>

int main()
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	float tub = 10.0f / 3.0f;
	double mint = 10.0f / 3.0f;
	const float MILLION = 1.0e6;

	std::cout << "tub = " << tub;
	std::cout << ", a million tubs = " << MILLION * tub;
	std::cout << ",\nand ten million tubs = ";
	std::cout << 10 * MILLION * tub << std::endl;

	std::cout << "mint = " << mint << " and a million mints = ";
	std::cout << MILLION * mint << std::endl;

	std::cin.get();
	return 0;
}