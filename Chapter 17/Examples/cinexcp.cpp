#include <iostream>
#include <exception>
#include <ctime>

int main()
{
	// have failbit cause an exception to be thrown
	std::cin.exceptions(std::ios_base::failbit);

	std::cout << "Enter numbers: ";

	int sum = 0;
	int input;

	try
	{
		while (std::cin >> input)
			sum += input;
	}
	
	catch (std::ios_base::failure & bf)
	{
		std::cout << '\n' << bf.what() << std::endl;
		std::cout << "Oh! The horror!" << std::endl;
	}

	std::cout << "\nLast value entered = " << input << std::endl;
	std::cout << "Sum = " << sum << std::endl;

	if (std::cin.fail())
		std::cin.clear();

	float seconds = 5.0;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	clock_t start = clock();
	while (clock() - start < delay);

	return 0;
}