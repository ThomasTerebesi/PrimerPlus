#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

inline void Show(double v);

const int LIMIT = 6;

int main()
{
	double arr1[LIMIT] = { 28, 29, 30, 35, 38, 59 };
	double arr2[LIMIT] = { 63, 65, 69, 75, 80, 99 };

	std::vector<double> gr8(arr1, arr1 + LIMIT);
	std::vector<double> m8(arr2, arr2 + LIMIT);

	std::cout.setf(std::ios_base::fixed);
	std::cout.precision(1);

	std::cout << "gr8:\t";
	for (auto item : gr8)
	{
		std::cout.width(6);
		std::cout << item << ' ';
	}
	std::cout << std::endl;

	std::cout << "\nm8:\t";
	for_each(m8.begin(), m8.end(), Show);
	std::cout << std::endl;

	std::vector<double> sum(LIMIT);
	transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), std::plus<double>());
	std::cout << "\nsum:\t";
	for_each(sum.begin(), sum.end(), Show);
	std::cout << std::endl;

	std::vector<double> prod(LIMIT);
	transform(gr8.begin(), gr8.end(), prod.begin(), std::bind1st(std::multiplies<double>(), 2.5));
	std::cout << "\nprod:\t";
	for_each(prod.begin(), prod.end(), Show);
	std::cout << std::endl;

	std::cin.get();

	return 0;
}

void Show(double v)
{
	std::cout.width(6);
	std::cout << v << ' ';
}
