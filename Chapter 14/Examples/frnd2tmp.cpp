#include <iostream>

template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T & i) : item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void Counts();
	friend void Reports(HasFriend<T> & hf);	// template parameter
};

// each specialization has its own static data member
template <typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
void Counts()
{
	std::cout << "int count: " << HasFriend<int>::ct << "; double count: " << HasFriend<double>::ct << std::endl;
}

// non-template friend to the HasFriend<int> class
void Reports(HasFriend<int> & hf)
{
	std::cout << "HasFriend<int>: " << hf.item << std::endl;
}

// non-template friend to the HasFriend<double> class
void Reports(HasFriend<double> & hf)
{
	std::cout << "HasFriend<double>: " << hf.item << std::endl;
}


int main()
{
	std::cout << "No objects declared: ";
	Counts();

	HasFriend<int> hfi1(10);
	std::cout << "After hfi1 declared: ";
	Counts();

	HasFriend<int> hfi2(20);
	std::cout << "After hfi2 declared: ";
	Counts();

	HasFriend<double> hfdb(10.5);
	std::cout << "After hfdb declared: ";
	Counts();

	Reports(hfi1);
	Reports(hfi2);
	Reports(hfdb);

	std::cin.get();

	return 0;
}