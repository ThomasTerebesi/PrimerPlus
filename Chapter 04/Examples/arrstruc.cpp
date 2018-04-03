#include <iostream>

struct Inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	Inflatable guests[2] = {
		{"Bambi", 0.5f, 21.99},
		{"Godzilla", 2000, 565.99}
	};

	std::cout << "The guests " << guests[0].name << " and "
		<< guests[1].name << "\nhave a combined volume of "
		<< guests[0].volume + guests[1].volume << " cubic feet.\n";

	std::cin.get();
	return 0;
}