#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
	std::string str;
public:
	Report(const std::string s)
		: str(s)
	{
		std::cout << "Object created!" << std::endl;
	}

	~Report()
	{
		std::cout << "Object deleted!" << std::endl;
	}

	void Comment() const
	{
		std::cout << str << std::endl;
	}
};


int main()
{
	{
		std::auto_ptr<Report> pr(new Report("using auto_ptr"));
		pr->Comment();	// use -> to invoke a member function 
	}

	std::cout << std::endl;

	{
		std::shared_ptr<Report> pr(new Report("using shared_ptr"));
		pr->Comment();
	}

	std::cout << std::endl;

	{
		std::unique_ptr<Report> pr(new Report("using unique_ptr"));
		pr->Comment();
	}

	std::cin.get();

	return 0;
}