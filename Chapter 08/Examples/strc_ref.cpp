#include <iostream>
#include <string>

struct FreeThrows
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

void Display(const FreeThrows & ft);
void SetPercent(FreeThrows & ft);
FreeThrows & Accumulate(FreeThrows & target, const FreeThrows & source);

int main()
{
	FreeThrows one = { "Ifelsa Branch", 13, 14 };
	FreeThrows two = { "Andor Knott", 10, 16 };
	FreeThrows three = { "Minnie Max", 7, 9 };
	FreeThrows four = { "Whily Looper", 5, 9 };
	FreeThrows five = { "Long Long", 6, 14 };
	FreeThrows team = { "Throwgoods", 0, 0 };

	FreeThrows dup;

	SetPercent(one);
	Display(one);
	
	Accumulate(team, one);
	Display(team);

	Display(Accumulate(team, two));
	Accumulate(Accumulate(team, three), four);
	Display(team);

	dup = Accumulate(team, five);

	std::cout << "Displaying team:" << std::endl;
	Display(team);

	std::cout << "Displaying dup after assignment:" << std::endl;
	Display(dup);
	
	SetPercent(four);

	Accumulate(dup, five) = four;
	std::cout << "Displaying dup after ill-advised assignment:" << std::endl;
	Display(dup);

	std::cin.get();
	
	return 0;
}

void Display(const FreeThrows & ft)
{
	std::cout << "Name: " << ft.name << '\n';
	std::cout << "  Made: " << ft.made << '\t';
	std::cout << "Attempts: " << ft.attempts << '\t';
	std::cout << "Percent: " << ft.percent << std::endl;
}

void SetPercent(FreeThrows & ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f * static_cast<float>(ft.made) / static_cast<float>(ft.attempts);
	else
		ft.percent = 0;
}

FreeThrows & Accumulate(FreeThrows & target, const FreeThrows & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	SetPercent(target);
	return target;
}
