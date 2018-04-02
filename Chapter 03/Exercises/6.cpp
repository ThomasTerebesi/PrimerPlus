#include <iostream>

int main()
{
	std::cout << "How many kilometers have you driven? ";
	float kilometersDriven;
	std::cin >> kilometersDriven;

	std::cout << "How many liters have you used? ";
	float litersUsed;
	std::cin >> litersUsed;

	float resultLiters = litersUsed / (kilometersDriven / 100);

	std::cout << "You have used " << resultLiters << " liters per 100 kilometers." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}