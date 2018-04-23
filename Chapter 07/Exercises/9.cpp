#include <iostream>

using namespace std;
const int SLEN = 30;

struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);

// display1() takes a student structure as an argument
// and displays its contents
void display1(student st);

// display2() takes the address of student structure as an
// argument and displays the structure's contents
void display2(const student * ps);

// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	if (class_size == 0)
	{
		cout << "\n\aCan't have a class without students." << endl;
		cin.get();
		return 0;
	}

	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);

	if (entered > 0)
	{
		for (int i = 0; i < entered; i++)
		{
			display1(ptr_stu[i]);
			display2(&ptr_stu[i]);
		}
		display3(ptr_stu, entered);
		delete[] ptr_stu;
		
		cout << "\nDone.\n";
	}
	else
	{
		cout << "\aNo student information was entered." << endl;
	}

	cin.get();

	return 0;
}

int getinfo(student pa[], int n)
{
	cout << "You can enter information for up to " << n << " students." << endl;

	int i;

	for (i = 0; i < n; i++)
	{
		cout << "\nEnter the full name of student #" << i + 1 << ":" << endl;
		cin.getline(pa[i].fullname, SLEN);
		if (strlen(pa[i].fullname) == 0)
			break;
		else
		{
			cout << "Enter " << pa[i].fullname << "'s hobby:" << endl;
			cin.getline(pa[i].hobby, SLEN);

			cout << "Enter " << pa[i].fullname << "'s OOP level:" << endl;
			cin >> pa[i].ooplevel;
			cin.get();
		}
	}

	return i;
}

void display1(student st)
{
	cout << "\nName: " << st.fullname << endl;
	cout << "Hobby: " << st.hobby << endl;
	cout << "OOP level: " << st.ooplevel << endl;
}

void display2(const student * ps)
{
	cout << "\nName: " << ps->fullname << endl;
	cout << "Hobby: " << ps->hobby << endl;
	cout << "OOP level: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nStudent #" << (i + 1) << ":";
		display2(pa + i);
	}
}
