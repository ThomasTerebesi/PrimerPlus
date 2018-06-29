#include <iostream>
#include <ctime>

int main()
{
	std::cout << "Enter numbers: ";
	
	int sum = 0;
	int input;

	while (std::cin >> input)
		sum += input;

	std::cout << "Last value entered = " << input << std::endl;
	std::cout << "Sum = " << sum << std::endl;

	if (std::cin.fail())
		std::cin.clear();

	float seconds = 5.0;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	clock_t start = clock();
	while (clock() - start < delay);

	return 0;
}