// compile with 5emp.h and 5emp.cpp

#include <iostream>
#include <string>
#include "5emp.h"

using namespace std;

int main(void)
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	cout << endl;

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	cout << endl;

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	cout << endl;

	highfink hf(ma, "Curly Kew"); // recruitment?
	hf.ShowAll();
	cout << "\nNext phase: " << endl;


	highfink hf2;
	hf2.SetAll();

	cout << endl;
	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp * tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
	{
		tri[i]->ShowAll();
		cout << endl;
	}

	while (std::cin.get() != '\n')
		continue;

	return 0;
}