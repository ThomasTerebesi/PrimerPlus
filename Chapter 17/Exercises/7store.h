#include <fstream>
#include <string>

class Store
{
private:
	std::ofstream * pfo;
public:
	Store(std::ofstream & fout)
		: pfo(&fout)
	{
	}

	~Store() {};

	Store & operator()(const std::string & str);
};