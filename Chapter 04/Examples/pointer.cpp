#include <iostream>

int main()
{
	int updates = 6;
	int* p_updates;
	p_updates = &updates;

	std::cout << "Values: updates = " << updates << ", *p_updates = " << *p_updates << std::endl;

	std::cout << "Addresses: &updates = " << &updates << ", p_updates = " << p_updates << std::endl;

	*p_updates = *p_updates + 1;
	std::cout << "Now updates = " << updates << std::endl;

	std::cin.get();
	return 0;
}