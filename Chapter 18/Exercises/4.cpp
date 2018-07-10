// The author meant listing 16.15 (not 16.5), as it's the only listing that fits the description
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

auto OutInt = [](int n) { std::cout << n << " "; };

int main()
{
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };

	std::list<int> yadayada(vals, vals + 10);	// range constructor
	std::list<int> etcetera(vals, vals + 10);
	// C++11 initialization list possible: "std::list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};"

	std::cout << "Original lists:" << std::endl;
	for_each(yadayada.begin(), yadayada.end(), OutInt);
	std::cout << std::endl;
	for_each(etcetera.begin(), etcetera.end(), OutInt);
	std::cout << std::endl;

	yadayada.remove_if([](int n) { return n > 100; });
	etcetera.remove_if([](int n) { return n > 200; });

	std::cout << "\nTrimmed lists:" << std::endl;
	for (auto item : yadayada)
		std::cout << item << " ";
	std::cout << std::endl;
	for (auto item : etcetera)
		std::cout << item << " ";
	std::cout << std::endl;

	std::cin.get();

	return 0;
}