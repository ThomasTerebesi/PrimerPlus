#include <iostream>
#include <utility>

// interface
class Useless
{
private:
	int n;			// number of elements
	char * pc;		// pointer to data
	static int ct;	// number of objects

	void ShowObject() const;

public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless & f);	// regular copy constructor
	Useless(Useless && f);		// move constructor
	~Useless();

	Useless operator+(const Useless f) const;
	Useless & operator=(const Useless & f);	// copy assignment
	Useless & operator=(Useless && f);		// move assignment

	// need operator=() in copy and move versions

	void ShowData() const;
};


// implementation
int Useless::ct = 0;

void Useless::ShowObject() const
{
	std::cout << "Number of elements: " << n << "\tData address: " << (void *)pc << std::endl;
}

Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
}

Useless::Useless(int k)
	: n(k)
{
	++ct;
	pc = new char[n];
}

Useless::Useless(int k, char ch)
	: n(k)
{
	++ct;
	pc = new char[n];

	for (int i = 0; i < n; i++)
		pc[i] = ch;
}

Useless::Useless(const Useless & f)
	: n(f.n)
{
	++ct;
	pc = new char[n];

	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
}

Useless::Useless(Useless && f)
	: n(f.n)
{
	++ct;
	pc = f.pc;		// steal address
	f.pc = nullptr;	// give old object nothing in return
	f.n = 0;
}

Useless::~Useless()
{
	delete[] pc;
}

Useless Useless::operator+(const Useless f) const
{
	Useless temp = Useless(n + f.n);

	for (int i = 0; i < n; i++)
		temp.pc[i] = pc[i];

	for (int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];

	return temp;
}

Useless & Useless::operator=(const Useless & f)	// copy assignment
{
	std::cout << "Copy assignment operator called:" << std::endl;
	
	if (this == &f)
		return *this;

	delete[] pc;
	
	n = f.n;
	pc = new char[n];

	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];

	return *this;
}

Useless & Useless::operator=(Useless && f)		// move assignment
{
	std::cout << "Move assignment operator called:" << std::endl;
	
	if (this == &f)
		return *this;

	delete[] pc;

	n = f.n;
	pc = f.pc;
	
	f.n = 0;
	f.pc = nullptr;

	return *this;
}

void Useless::ShowData() const
{
	if (n == 0)
		std::cout << "[Object is empty.]";
	else
		for (int i = 0; i < n; i++)
			std::cout << pc[i];

	std::cout << std::endl;
}


// application
int main()
{
	{
		Useless one(10, 'x');
		Useless two = one + one;			// calls move constructor

		std::cout << "Object 'one': ";
		one.ShowData();

		std::cout << "\nObject 'two': ";
		two.ShowData();

		Useless three, four;

		std::cout << "\n'three = one':" << std::endl;
		three = one;						// automatic copy assignment

		std::cout << "\nNow, object 'three' = ";
		three.ShowData();

		std::cout << "\n... and object 'one' = ";
		one.ShowData();

		std::cout << "\n'four = one + two':" << std::endl;
		four = one + two;					// automatic move assignment

		std::cout << "\nNow, object 'four' = ";
		four.ShowData();

		std::cout << "\n'four = std::move(one);':" << std::endl;
		four = std::move(one);				// forced move assignment (included in 'utility')

		std::cout << "\nNow, object 'four' = ";
		four.ShowData();

		std::cout << "\nNow, object 'one' = ";
		one.ShowData();
	}

	std::cin.get();

	return 0;
}
