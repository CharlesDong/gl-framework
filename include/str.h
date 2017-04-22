#ifndef STR_H_
#define STR_H_

#include <string>
#include <sstream>

template <typename T>
std::string toString(const T & val);

template <typename T>
std::string toString(const T & val)
{
	std::ostringstream ss;
	ss << val;
	return ss.str();
}

#endif