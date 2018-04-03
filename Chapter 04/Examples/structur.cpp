#include <iostream>

struct Inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	Inflatable guest = {
		"Glorious Gloria",
		1.88f,
		29.99
	};

	Inflatable pal = {
		"Audacious Arthur",
		3.12f,
		32.99
	};

	std::cout << "Expand your guest list with " << guest.name << " and " << pal.name << "!\n";

	std::cout << "You can have both for $" << guest.price + pal.price << "!\n";

	std::cin.get();
	return 0;
}