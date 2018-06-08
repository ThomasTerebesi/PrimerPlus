#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<typename T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T & t) :
		cutoff(t)
	{
	}

	bool operator() (const T & v) { return v > cutoff; }
};

void OutInt(int n) { std::cout << n << " "; }

int main()
{
	TooBig<int> f100(100);	// limit = 100
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };

	std::list<int> yadayada(vals, vals + 10);	// range constructor
	std::list<int> etcetera(vals, vals + 10);
	// C++11 initialization list possible: "std::list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};"

	std::cout << "Original lists:" << std::endl;
	for_each(yadayada.begin(), yadayada.end(), OutInt);
	std::cout << std::endl;
	for_each(etcetera.begin(), etcetera.end(), OutInt);
	std::cout << std::endl;

	yadayada.remove_if(f100);				// use a named function object
	etcetera.remove_if(TooBig<int>(200));	// construct a function object

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