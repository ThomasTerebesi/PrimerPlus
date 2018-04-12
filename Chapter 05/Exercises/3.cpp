#include <iostream>

int main()
{
	std::cout << "Enter integers and I will add them together ('0' to stop execution): ";
	int input, sum = 0;

	std::cin >> input;
	while (input != 0)
	{
		std::cout << "Sum of all integers you entered so far: " << (sum += input) << std::endl;
		std::cout << "\nEnter another integer: ";
		std::cin >> input;
	}
	
	std::cout << "Execution stopped. Your final sum is " << sum << "." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}