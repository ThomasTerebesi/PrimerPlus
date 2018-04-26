#include <iostream>

struct Job
{
	char name[40];
	double salary;
	int floor;
};

template<typename T>
void Swap(T &a, T &b);

// explicit specialization
template <> void Swap<Job>(Job &j1, Job &j2);

void Show(Job &j);

int main()
{
	std::cout.precision(2);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);

	int i = 10, j = 20;

	std::cout << "i, j = " << i << ", " << j << "." << std::endl;
	std::cout << "Using compiler-generated int swapper:" << std::endl;
	Swap(i, j); // generates void Swap(int &, int &)
	std::cout << "Now i, j = " << i << ", " << j << "." << std::endl;


	Job sue = { "Susan Yaffee", 73000.60, 7 };
	Job sidney = { "Sidney Yaffee", 78060.72, 9 };

	std::cout << "Before job swapping:" << std::endl;
	Show(sue);
	Show(sidney);
	
	Swap(sue, sidney); // uses void Swap(Job &, Job &)

	std::cout << "After job swapping:" << std::endl;
	Show(sue);
	Show(sidney);


	std::cin.get();

	return 0;
}

template<typename T>
void Swap(T & a, T & b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}


// swaps just the salary and floor fields of a job structure
template<> void Swap<Job>(Job & j1, Job & j2)
{
	double t1;
	int t2;

	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;

	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(Job & j)
{
	std::cout << j.name << ": $" << j.salary << " on floor " << j.floor << "." << std::endl;
}
