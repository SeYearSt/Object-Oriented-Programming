#pragma once;
#include <string>

class StrInterface {
public :
	virtual std::string toString() = 0;
	virtual void fromString(const std::string &) = 0;
};