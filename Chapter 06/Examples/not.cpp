#include <iostream>
#include <climits>

bool isInt(double);

int main()
{
	double num;
	
	std::cout << "Yo, dude! Enter an integer value: ";
	std::cin >> num;

	while (!isInt(num))
	{
		std::cout << "Out of range -- please try again, dude: ";
		std::cin >> num;
	}

	int val = int(num);
	std::cout << "You've entered the integer " << val << ".\nBye, dude!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}

bool isInt(double x)
{
	if (x <= INT_MAX && x >= INT_MIN)
		return true;
	else
		return false;
}