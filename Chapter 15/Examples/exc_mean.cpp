#include "exc_mean.h"

void bad_hmean::mesg()
{
	std::cout << "hmean(" << v1 << ", " << v2 << "): invalid arguments: a = -b" << std::endl;
}

const char * bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}
