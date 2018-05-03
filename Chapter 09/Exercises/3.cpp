#include <iostream>
#include <cstring>

const int ARRAY_SIZE = 2;

struct chaff
{
	char dross[20];
	int slag;
};

void SetChaff(chaff & c, const char * dross, const int slag);
void DisplayChaff(const chaff * c, const int n);

char buffer[sizeof(chaff) * ARRAY_SIZE];

int main()
{
	chaff * pc;
	pc = new (buffer) chaff[ARRAY_SIZE];

	SetChaff(pc[0], "Plastic waste", 16);
	SetChaff(pc[1], "Organic waste", 47);

	DisplayChaff(pc, ARRAY_SIZE);

	std::cin.get();

	return 0;
}

void SetChaff(chaff & c, const char * dross, const int slag)
{
	strcpy_s(c.dross, 20, dross);
	c.slag = slag;
}

void DisplayChaff(const chaff * c, const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Entry #" << (i + 1) << ":" << std::endl;
		std::cout << "Dross: " << c[i].dross << std::endl;
		std::cout << "Slag: " << c[i].slag << "\n" << std::endl;
	}
}
