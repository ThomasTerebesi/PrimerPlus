#include <iostream>
#include <string>

struct PizzaData
{
	std::string mCompanyName;
	float mDiameter;
	float mWeight;
};

int main()
{
	PizzaData userPizza;

	std::cout << "Enter the pizza company's name: ";
	getline(std::cin, userPizza.mCompanyName);

	std::cout << "Enter the pizza's diameter: ";
	std::cin >> userPizza.mDiameter;

	std::cout << "Enter the pizza's weight: ";
	std::cin >> userPizza.mWeight;

	std::cout << "The pizza made by " << userPizza.mCompanyName;
	std::cout << " has a diameter of " << userPizza.mDiameter;
	std::cout << " and a weight of " << userPizza.mWeight << ".\n";

	std::cin.get();
	std::cin.get();
	return 0;
}