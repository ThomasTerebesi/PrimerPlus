#include <iostream>
#include <initializer_list>

double Sum(std::initializer_list<double> il);
double Average(const std::initializer_list<double> & ril);

int main()
{
	std::cout << "List 1: sum = " << Sum({ 2,3,4 });
	std::cout << ", average = " << Average({ 2,3,4 }) << std::endl;

	std::initializer_list<double> dl = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	std::cout << "List 2: sum = " << Sum(dl);
	std::cout << ", average = " << Average(dl) << std::endl;

	dl = { 16.0, 25.0, 36.0, 40.0, 64.0 };
	std::cout << "List 3: sum = " << Sum(dl);
	std::cout << ", average = " << Average(dl) << std::endl;

	std::cin.get();

	return 0;
}

double Sum(std::initializer_list<double> il)
{
	double total = 0;
	
	for (auto p = il.begin(); p != il.end(); p++)
		total += *p;

	return total;
}

double Average(const std::initializer_list<double> & ril)
{
	int n = ril.size();
	double total = 0;

	if (n > 0)
	{
		for (auto p = ril.begin(); p != ril.end(); p++)
			total += *p;
	}

	return total / n;
}