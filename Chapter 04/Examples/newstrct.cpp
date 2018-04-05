#include <iostream>

struct Inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	Inflatable *ps = new Inflatable;
	std::cout << "Enter name of inflatable item: ";
	std::cin.get(ps->name, 20);

	std::cout << "Enter volume in cubic feet: ";
	std::cin >> (*ps).volume;

	std::cout << "Enter a price: $";
	std::cin >> ps->price;

	std::cout << "Name: " << (*ps).name << std::endl;
	std::cout << "Volume: " << ps->volume << std::endl;
	std::cout << "Price: $" << ps->price << std::endl;

	delete ps;

	std::cin.get();
	std::cin.get();
	return 0;
}