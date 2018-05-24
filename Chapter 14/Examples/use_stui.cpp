// compile with studenti.h and studenti.cpp

#include <iostream>
#include "studenti.h"

void Set(Student & sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
	Student ada[pupils] = { Student(quizzes), Student(quizzes), Student(quizzes) };

	// std::cout << "Size of Student: " << sizeof(Student) << std::endl;

	int i;
	for (i = 0; i < pupils; ++i)
		Set(ada[i], quizzes);

	std::cout << "\nStudent List:" << std::endl;
	for (i = 0; i < pupils; ++i)
		std::cout << ada[i].Name() << std::endl;

	std::cout << "\nResults:";
	for (i = 0; i < pupils; ++i)
	{
		std::cout << std::endl << ada[i];
		std::cout << "average: " << ada[i].Average() << std::endl;
	}

	std::cout << "\nDone." << std::endl;


	std::cin.get();

	return 0;
}

void Set(Student & sa, int n)
{
	std::cout << "Please enter the student's name: ";
	getline(std::cin, sa);
	std::cout << "Please enter " << n << " quiz scores:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> sa[i];
	while (std::cin.get() != '\n')
		continue;
}
