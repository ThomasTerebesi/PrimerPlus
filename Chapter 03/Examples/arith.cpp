#include <iostream>

int main()
{
	float hats, heads;

	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout << "Enter a number: ";
	std::cin >> hats;
	std::cout << "Enter another number: ";
	std::cin >> heads;

	std::cout << "hats = " << hats << "; heads = " << heads << std::endl;
	std::cout << "hats + heads = " << hats + heads << std::endl;
	std::cout << "hats - heads = " << hats - heads << std::endl;
	std::cout << "hats * heads = " << hats * heads << std::endl;
	std::cout << "hats / heads = " << hats / heads << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}