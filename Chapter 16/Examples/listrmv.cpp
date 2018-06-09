#include <iostream>
#include <list>
#include <algorithm>

inline void Show(int v);

const int LIMIT = 10;

int main()
{
	int ar[LIMIT] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };
	std::list<int> la(ar, ar + LIMIT);
	std::list<int> lb(la);

	std::cout << "Original list contents:\n\t";
	for (auto item : la)
		std::cout << item << ' ';
	std::cout << std::endl;

	la.remove(4);
	std::cout << "After using the remove() method:" << std::endl;
	std::cout << "la:\t";
	for_each(la.begin(), la.end(), Show);
	std::cout << std::endl;

	std::list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);
	std::cout << "After using the remove() function:" << std::endl;
	std::cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	std::cout << std::endl;

	lb.erase(last, lb.end());
	std::cout << "After using the erase() method:" << std::endl;
	std::cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	std::cout << std::endl;

	std::cin.get();

	return 0;
}

void Show(int v)
{
	std::cout << v << ' ';
}
