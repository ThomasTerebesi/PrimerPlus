#include <iostream>

void Simon(int n);

int main()
{
	Simon(3);
	std::cout << "Pick an integer: ";
	int count;
	std::cin >> count;
	Simon(count);
	std::cout << "Done!" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}

void Simon(int n)
{
	std::cout << "Simon says: Touch your toes " << n << " times." << std::endl;
	return;
}