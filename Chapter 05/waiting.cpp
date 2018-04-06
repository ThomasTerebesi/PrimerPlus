#include <iostream>
#include <ctime>

int main()
{
	std::cout << "Enter the delay time in seconds: ";
	float seconds;
	std::cin >> seconds;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);

	std::cout << "Starting...\a\n";
	clock_t start = clock();
	
	while (clock() - start < delay)
		;
	
	std::cout << "Done.\a\n";

	std::cin.get();
	std::cin.get();
	return 0;
}