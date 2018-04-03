#include <iostream>

struct Inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	Inflatable bouquet = {
		"sunflowers",
		0.20f,
		12.49
	};

	Inflatable choice = {};

	std::cout << "bouquet: " << bouquet.name << " for $" << bouquet.price << std::endl;

	choice = bouquet;

	std::cout << "choice: " << choice.name << " for $" << choice.price << std::endl;

	std::cin.get();
	return 0;
}