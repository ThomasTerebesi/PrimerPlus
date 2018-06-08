#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void OutInt(int n) { std::cout << n << " "; }

int main()
{
	std::list<int> one(5, 2);	// list of 5 2s
	std::list<int> two;
	int stuff[5] = { 1, 2, 4, 8, 6 };
	

	two.insert(two.begin(), stuff, stuff + 5);
	
	int more[6] = { 6, 4, 2, 4, 6, 5 };

	std::list<int> three(two);
	three.insert(three.end(), more, more + 6);

	std::cout << "List one: ";
	for (auto item : one)	// as suggested on page 1016 (and before)
		std::cout << item;

	std::cout << "\nList two: ";
	for_each(two.begin(), two.end(), OutInt);

	std::cout << "\nList three: ";
	for_each(three.begin(), three.end(), OutInt);

	three.remove(2);
	std::cout << "\nList three minus 2s: ";
	for (auto item : three)
		std::cout << item;

	three.splice(three.begin(), one);	// moves the original range into the destination, not a copy
	std::cout << "\nList three after splice: ";
	for_each(three.begin(), three.end(), OutInt);

	std::cout << "\nList one: ";
	for_each(one.begin(), one.end(), OutInt);

	three.unique();
	std::cout << "\nList three after unique: ";
	for (auto item : three)
		std::cout << item;

	three.sort();
	three.unique();
	std::cout << "\nList three after sort & unique: ";
	for (auto item : three)
		std::cout << item;

	two.sort();
	three.merge(two);
	std::cout << "\nSorted list two merged into list three: ";
	for_each(three.begin(), three.end(), OutInt);

	std::cout << std::endl;

	std::cin.get();

	return 0;
}