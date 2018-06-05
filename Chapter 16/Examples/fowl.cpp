#include <iostream>
#include <string>
#include <memory>

int main()
{
	// ORIGINAL AUTO_PTR VERSION FROM PAGE 973
	/*
	std::auto_ptr<std::string> films[5] = {
		std::auto_ptr<std::string>(new std::string("Fowl Balls")),
		std::auto_ptr<std::string>(new std::string("Duck Walks")),
		std::auto_ptr<std::string>(new std::string("Chicken Runs")),
		std::auto_ptr<std::string>(new std::string("Turkey Errors")),
		std::auto_ptr<std::string>(new std::string("Goose Eggs"))
	};

	std::auto_ptr<std::string> pwin;
	pwin = films[2];	// films[2] loses ownership
	*/
	
	// SHARED_PTR VERSION SUGGESTED ON PAGE 974
	std::shared_ptr<std::string> films[5] = {
		std::shared_ptr<std::string>(new std::string("Fowl Balls")),
		std::shared_ptr<std::string>(new std::string("Duck Walks")),
		std::shared_ptr<std::string>(new std::string("Chicken Runs")),
		std::shared_ptr<std::string>(new std::string("Turkey Errors")),
		std::shared_ptr<std::string>(new std::string("Goose Eggs"))
	};

	std::shared_ptr<std::string> pwin;


	// UNIQUE_PTR VERSION SUGGESTED ON PAGE 975
	/*
	std::unique_ptr<std::string> films[5] = {
		std::unique_ptr<std::string>(new std::string("Fowl Balls")),
		std::unique_ptr<std::string>(new std::string("Duck Walks")),
		std::unique_ptr<std::string>(new std::string("Chicken Runs")),
		std::unique_ptr<std::string>(new std::string("Turkey Errors")),
		std::unique_ptr<std::string>(new std::string("Goose Eggs"))
	};

	std::unique_ptr<std::string> pwin;
	*/

	pwin = films[2];	// films[2] loses ownership

	std::cout << "The nominees for best avian baseball film are" << std::endl;
	
	for (int i = 0; i < 5; i++)
		std::cout << *films[i] << std::endl;
	
	std::cout << "The winner is " << *pwin << "!" << std::endl;

	std::cin.get();

	return 0;
}