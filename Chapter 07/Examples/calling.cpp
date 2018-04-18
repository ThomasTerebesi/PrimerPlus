#include <iostream>

void simple(); // function prototype

int main()
{
	std::cout << "main() will call the simple()-function:" << std::endl;
	
	simple(); // function call 

	std::cout << "main() is finished with the simple()-function." << std::endl;

	std::cin.get();
	return 0;
}

void simple() // function definition
{
	std::cout << "I'm but a simple function." << std::endl;
	return;
}