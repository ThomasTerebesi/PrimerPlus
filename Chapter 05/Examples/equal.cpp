#include <iostream>

int main()
{
	int quizScores[10] = { 20,20,20,20,20,19,20,18,20,20 };

	std::cout << "Doing it right:\n";
	int i;
	for (i = 0; quizScores[i] == 20; i++)
		std::cout << "quiz " << i << " is a 20\n";


	std::cout << "Doing it dangeously wrong:\n";
	for (i = 0; quizScores[i] = 20; i++) // intentional error
		std::cout << "quiz " << i << " is a 20\n";


	std::cin.get();
	return 0;
}