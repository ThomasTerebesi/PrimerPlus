#include <iostream>

void Change(const int * pt, int n);

int main()
{
	int pop1 = 38383;
	const int pop2 = 2000;

	std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;
	
	Change(&pop1, -103);
	Change(&pop2, -103);

	std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;

	std::cin.get();

	return 0;
}

void Change(const int * pt, int n)
{
	int * pc;

	pc = const_cast<int *>(pt);
	*pc += n;
}