#include <iostream>
#include <fstream>
#include <cstdlib>	// for exit()

int main(int argc, char * argv[])
{
	if (argc == 1)
	{
		std::cerr << "Usage: " << argv[0] << " filename[s]." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::ifstream fin;	// open stream
	long count;
	long total = 0;
	char ch;

	for (int file = 1; file < argc; file++)
	{
		fin.open(argv[file]);	// connect stream to argv[file]
		if (!fin.is_open())
		{
			std::cerr << "Could not open " << argv[file] << "." << std::endl;
			fin.clear();
			continue;
		}

		count = 0;
		while (fin.get(ch))
			count++;

		std::cout << count << " characters in " << argv[file] << "." << std::endl;
		total += count;
		fin.clear();			// needed for some implementations
		fin.close();			// disconnect file
	}

	std::cout << total << " characters in all files." << std::endl;

	std::cin.get();

	return 0;
}