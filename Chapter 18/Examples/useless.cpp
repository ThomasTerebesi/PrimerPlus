#include <iostream>

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
	std::cout << "Default constructor called; number of objects: " << ct << std::endl;
	ShowObject();
}

Useless::Useless(int k)
	: n(k)
{
	++ct;
	std::cout << "Integer constructor called; number of objects: " << ct << std::endl;
	pc = new char[n];
	ShowObject();
}

Useless::Useless(int k, char ch)
	: n(k)
{
	++ct;
	std::cout << "Integer, character constructor called; number of objects: " << ct << std::endl;
	pc = new char[n];
	
	for (int i = 0; i < n; i++)
		pc[i] = ch;
	
	ShowObject();
}

Useless::Useless(const Useless & f)
	: n(f.n)
{
	++ct;
	std::cout << "Copy constructor called; number of objects: " << ct << std::endl;
	pc = new char[n];
	
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	
	ShowObject();
}

Useless::Useless(Useless && f)
	: n(f.n)
{
	++ct;
	std::cout << "Move constructor called; number of objects: " << ct << std::endl;
	pc = f.pc;		// steal address
	f.pc = nullptr;	// give old object nothing in return
	f.n = 0;
	ShowObject();
}

Useless::~Useless()
{
	std::cout << "Destructor called; objects left: " << --ct << std::endl;
	std::cout << "Deleted object:" << std::endl;
	ShowObject();
	delete[] pc;
}

Useless Useless::operator+(const Useless f) const
{
	std::cout << "Entering operator+() ..." << std::endl;
	Useless temp = Useless(n + f.n);
	
	for (int i = 0; i < n; i++)
		temp.pc[i] = pc[i];

	for (int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];

	std::cout << "Temporary object:" << std::endl;
	std::cout << "Leaving operator+() ..." << std::endl;

	return temp;
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
		Useless two = one;			// calls copy constructor
		Useless three(20, 'o');
		Useless four(one + three);	// calls operator+() and move constructor

		std::cout << "Object 'one': ";
		one.ShowData();
		
		std::cout << "Object 'two': ";
		two.ShowData();
		
		std::cout << "Object 'three': ";
		three.ShowData(); 
		
		std::cout << "Object 'four': ";
		four.ShowData();
	}

	std::cin.get();

	return 0;
}
