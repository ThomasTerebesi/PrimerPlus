#include <iostream>
#include <cstring>

int main()
{
	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;

	std::cout << animal << " and " << bird << std::endl;

	std::cout << "Enter a kind of animal: ";
	std::cin >> animal;

	ps = animal;
	std::cout << ps << "!\n";
	std::cout << "Before using strcpy_s():\n";
	std::cout << animal << " at " << (int*)animal << std::endl;
	std::cout << ps << " at " << (int*)ps << std::endl;

	ps = new char[strlen(animal) + 1];
	// strcpy_s: when using pointers you have to specify the number of elements of the destination buffer
	strcpy_s(ps, strlen(animal) + 1, animal); 

	std::cout << "After using strcpy_s():\n";
	std::cout << animal << " at " << (int*)animal << std::endl;
	std::cout << ps << " at " << (int*)ps << std::endl;

	
	std::cout << "Address of string literal \"Test\": " << (int*)"Test" << std::endl;

	delete[] ps;

	std::cin.get();
	std::cin.get();
	return 0;
}