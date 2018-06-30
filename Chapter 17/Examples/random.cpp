#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

const char * file = "planets.dat";	// ASSUMED TO EXIST (see "binary.cpp")
const int LIM = 20;

struct Planet
{
	char name[LIM];		// name of planet
	double population;	// population of planet
	double g;			// acceleration of gravity of planet
};

inline void EatLine() { while (std::cin.get() != '\n') continue; }

int main()
{
	Planet pl;
	std::cout << std::fixed;


	// show initial contents
	std::fstream finout;
	finout.open(file, std::ios_base::in | std::ios_base::out | std::ios_base::binary);	

	int ct = 0;

	if (finout.is_open())
	{
		std::cout << "Here are the current contents of the " << file << " file:" << std::endl;
		
		while (finout.read((char *)&pl, sizeof(pl)));
		{
			std::cout << ct++ << ": " << std::setw(LIM) << pl.name << ": "
				<< std::setprecision(0) << std::setw(12) << pl.population
				<< std::setprecision(2) << std::setw(6) << pl.g << std::endl;
		}
		
		if (finout.eof())
			finout.clear();
		else
		{
			std::cerr << "Error in reading " << file << "." << std::endl;
			std::cin.get();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		std::cerr << file << " could not be opened. Bye." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}


	// change a record
	std::cout << "Enter the record number you wish to change: ";
	long rec;
	std::cin >> rec;
	EatLine();

	if (rec < 0 || rec >= ct)
	{
		std::cerr << "Invalid record number. Bye." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::streampos place = rec * sizeof(pl);	// convert to streampos type
	finout.seekg(place);	// random access

	if (finout.fail())
	{
		std::cerr << "Error on attempted seek. Bye." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	finout.read((char *)&pl, sizeof(pl));
	std::cout << "Your selection:" << std::endl;
	std::cout << rec << ": " << std::setw(LIM) << pl.name << ": "
		<< std::setprecision(0) << std::setw(12) << pl.population
		<< std::setprecision(2) << std::setw(6) << pl.g << std::endl;

	if (finout.eof())
		finout.clear();	// clear EOF flag

	std::cout << "Enter planet name: ";
	std::cin.get(pl.name, LIM);
	EatLine();

	std::cout << "Enter planetary population: ";
	std::cin >> pl.population;
	
	std::cout << "Enter planet's acceleration of gravity: ";
	std::cin >> pl.g;

	finout.seekp(place); // go back
	finout.write((char *)&pl, sizeof pl) << std::flush;

	if (finout.fail())
	{
		std::cerr << "Error on attempted write. Bye." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}


	// show revised file
	ct = 0;
	finout.seekg(0);	// go to beginning of file
	std::cout << "Here are the new contents of the " << file << " file:" << std::endl;

	while (finout.read((char *)&pl, sizeof(pl)))
	{
		std::cout << ct++ << ": " << std::setw(LIM) << pl.name << ": "
			<< std::setprecision(0) << std::setw(12) << pl.population
			<< std::setprecision(2) << std::setw(6) << pl.g << std::endl;
	}

	finout.close();

	std::cout << "Done." << std::endl;

	float seconds = 10.0f;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	clock_t start = clock();
	while (clock() - start < delay);

	return 0;
}