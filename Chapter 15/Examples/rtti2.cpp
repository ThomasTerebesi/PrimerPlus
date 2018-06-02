#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class Grand
{
private:
	int hold;
public:
	Grand(int h = 0)
		: hold(h)
	{
	}

	virtual void Speak() const { std::cout << "I am a grand class!" << std::endl; }
	virtual int Value() const { return hold; }
};

class Superb : public Grand
{
public:
	Superb(int h = 0)
		: Grand(h)
	{
	}

	void Speak() const { std::cout << "I am a superb class!" << std::endl; }
	virtual void Say() const { std::cout << "I hold the superb value of " << Value() << "!" << std::endl; }
};

class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A')
		: Superb(h), ch(c)
	{
	}

	void Speak() const { std::cout << "I am a magnificent class!" << std::endl; }
	void Say() const { std::cout << "I hold the character " << ch << " and the integer " << Value() << "!" << std::endl; }
};

Grand * GetOne();

int main()
{
	srand(static_cast<int>(time(0)));

	Grand * pg;
	Superb * ps;

	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		std::cout << "Now processing " << typeid(*pg).name() << "." << std::endl;
		pg->Speak();

		if (ps = dynamic_cast<Superb *>(pg))
			ps->Say();
		if (typeid(Magnificent) == typeid(*pg))
			std::cout << "Yes, you are really magnificent." << std::endl;
	}

	std::cin.get();

	return 0;
}

// Generate one of three kinds of objects randomly
Grand * GetOne()
{
	Grand * p = nullptr;

	switch (rand() % 3)
	{
	case 0:
		p = new Grand(rand() % 100);
		break;
	case 1:
		p = new Superb(rand() % 100);
		break;
	case 2:
		p = new Magnificent(rand() % 100, 'A' + rand() % 26);
		break;
	default:
		break;
	}

	return p;
}