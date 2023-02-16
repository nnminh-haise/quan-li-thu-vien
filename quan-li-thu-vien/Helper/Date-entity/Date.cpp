#include "Date.h"
#include <iostream>



Date::Date()
	: m_Day(12), m_Month(10), m_Year(2002)
{
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
	: m_Day(day), m_Month(month), m_Year(year)
{
	if (DateValidation(day, month, year) == false)
	{
		std::cout << day << " - " << month << " - " << year << " is not a valid date!" << std::endl;
		this->m_Day = 12;
		this->m_Month = 10;
		this->m_Year = 2002;
		return;
	}
}

//const char* Date::Stringfy()
//{
//	//const char* stringForm = "("
//}




bool DateValidation(Date date)
{
	if (date.m_Day > 31) { return false; }
	if (date.m_Month > 13) { return false; }
	if (date.m_Month == 2 && date.m_Day >= 30) { return false; }
	if ((date.m_Month == 4 || date.m_Month == 6 || date.m_Month == 9 || date.m_Month == 11) && date.m_Day > 30) { return false; }
	if (!(((date.m_Year % 4 == 0) && (date.m_Year % 100 != 0)) || (date.m_Year % 400 == 0)) && date.m_Day >= 29) { return false; }

	return true;
}

bool DateValidation(int day, int month, int year)
{
	if (day > 31) { return false; }
	if (month > 13) { return false; }
	if (month == 2 && day >= 30) { return false; }
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) { return false; }
	if (!(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && day >= 29) { return false; }

	return true;
}
