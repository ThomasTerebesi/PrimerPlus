#include <iostream>

struct TravelTime
{
	int hours;
	int minutes;
};

const int MINUTES_PER_HOUR = 60;

TravelTime Sum(TravelTime t1, TravelTime t2);
void ShowTime(TravelTime t);

int main()
{
	TravelTime day1 = { 5, 45 };
	TravelTime day2 = { 4, 55 };

	TravelTime trip = Sum(day1, day2);

	std::cout << "Two-day total: ";
	ShowTime(trip);

	TravelTime day3 = { 4, 32 };
	std::cout << "Three-day total: ";
	ShowTime(Sum(trip, day3));

	std::cin.get();

	return 0;
}

TravelTime Sum(TravelTime t1, TravelTime t2)
{
	TravelTime total;

	total.minutes = (t1.minutes + t2.minutes) % MINUTES_PER_HOUR;
	total.hours = t1.hours + t2.hours + (t1.minutes + t2.minutes) / MINUTES_PER_HOUR;

	return total;
}

void ShowTime(TravelTime t)
{
	std::cout << t.hours << " hours, " << t.minutes << " minutes " << std::endl;
}