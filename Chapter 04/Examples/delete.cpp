#include <iostream>
#include <cstring>

char* GetName(void);

int main()
{
	char* name;

	name = GetName();
	std::cout << name << " at " << (int*)name << "\n";
	delete[] name;

	name = GetName();
	std::cout << name << " at " << (int*)name << "\n";
	delete[] name;


	std::cin.get();
	std::cin.get();
	return 0;
}

char* GetName()
{
	char temp[80];
	std::cout << "Enter last name: ";
	std::cin >> temp;
	char* pn = new char[strlen(temp) + 1];
	strcpy_s(pn, strlen(temp) + 1, temp);

	return pn;
}