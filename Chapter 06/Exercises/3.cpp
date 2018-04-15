#include <iostream>

int main()
{
	std::cout << "Please enter one of the following choices:" << std::endl;
	std::cout << "c) carnivore\tp) pianist" << std::endl;
	std::cout << "t) tree\t\tg) game" << std::endl;

	char ch;

	std::cin >> ch;
	
	while ((ch != 'c') && (ch != 'p') && (ch != 't') && (ch != 'g'))
	{
		std::cout << "Please enter a 'c', 'p', 't' or 'g': ";
		std::cin >> ch;
	}

	switch (ch)
	{
	case 'c':
		std::cout << "A fox is a carnivore." << std::endl;
		break;
	case 'p':
		std::cout << "Chopin was a pianist." << std::endl;
		break;
	case 't':
		std::cout << "A maple is a tree." << std::endl;
		break;
	case 'g':
		std::cout << "Chess is a game." << std::endl;
		break;
	default:
		std::cout << "Something went very wrong." << std::endl;
		break;
	}

	std::cin.get();
	std::cin.get();

	return 0;
}