#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<double> data;
	double temp;

	std::cout << "Enter numbers (<= 0 to quit):" << std::endl;
	
	while (std::cin >> temp && temp > 0)
		data.push_back(temp);

	sort(data.begin(), data.end());
	
	int size = data.size();

	std::valarray<double> numbers(size);
	
	int i;
	for (i = 0; i < size; i++)
		numbers[i] = data[i];

	std::valarray<double> sq_rts(size);
	sq_rts = sqrt(numbers);

	std::valarray<double> results(size);
	results = numbers + 2.0 * sq_rts;

	std::cout.setf(std::ios_base::fixed);
	std::cout.precision(4);

	std::cout << std::endl;

	for (i = 0; i < size; i++)
	{
		std::cout.width(8);
		std::cout << numbers[i] << ": ";
		std::cout.width(8);
		std::cout << results[i] << std::endl;
	}

	std::cout << "\nDone." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}