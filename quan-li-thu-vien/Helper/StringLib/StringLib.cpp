#include "StringLib.h"

#include <iostream>
#include <string>


std::string STR::ToString(int value, int maxDigit)
{
	int digitCount = 0;
	std::string result = "";
	while (value != 0)
	{
		result += (char)(value % 10 - '0');
		value /= 10;
		++digitCount;
	}

	while (digitCount < maxDigit)
	{
		result = "0" + result;
		++digitCount;
	}

	return result;
}