#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	std::vector<int> dice(10);

	// copy from array to vector
	copy(casts, casts + 10, dice.begin());
	
	std::cout << "Let the dice be cast!" << std::endl;

	// create an ostream iterator
	std::ostream_iterator<int, char> out_iter(std::cout, " ");

	// copy from vector to output
	copy(dice.begin(), dice.end(), out_iter);
	std::cout << std::endl;

	std::cout << "\nImplicit use of reverse iterator." << std::endl;
	copy(dice.rbegin(), dice.rend(), out_iter);
	std::cout << std::endl;

	std::cout << "\nExplicit use of reverse iterator." << std::endl;
	std::vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		std::cout << *ri << ' ';
	std::cout << std::endl;

	std::cin.get();

	return 0;
}