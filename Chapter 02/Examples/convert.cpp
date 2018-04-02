#include <iostream>

int StoneToLb(int sts);

int main()
{
	std::cout << "Enter the weight in stone: ";
	int stone;
	std::cin >> stone;
	int pounds = StoneToLb(stone);
	std::cout << stone << " stone = " << pounds << " pounds." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}

int StoneToLb(int sts)
{
	return 14 * sts;
}