#include "7store.h"

Store & Store::operator()(const std::string & str)
{
	std::size_t length = str.length();
	pfo->write((char *)& length, sizeof(std::size_t));
	pfo->write(str.data(), length);
	return *this;
}
