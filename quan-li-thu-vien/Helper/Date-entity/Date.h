#pragma once
#include <iostream>
#include <string>


class Date
{
public:
	unsigned int m_Day;
	unsigned int m_Month;
	unsigned int m_Year;

public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year);
	std::string Stringfy();
	bool Valid();
};
