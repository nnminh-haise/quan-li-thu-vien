#include "Date.h"
#include <iostream>
#include <string>
#include <format>


Date::Date()
	: m_Day(1), m_Month(1), m_Year(2023)
{
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
	: m_Day(day), m_Month(month), m_Year(year)
{
	if (this->Valid() == false)
	{
		std::cout << std::format("[ERROR]: {}/{}/{} is not a valid date!", this->m_Day, this->m_Month, this->m_Year) << std::endl;
		this->m_Day = 1;
		this->m_Month = 1;
		this->m_Year = 2023;
	}
}

std::string Date::Stringfy()
{
	return std::format("{}/{}/{}", std::to_string(this->m_Day), std::to_string(this->m_Month), std::to_string(this->m_Year));
}

bool Date::Valid()
{
	if (this->m_Day > 31)
	{
		return false;
	}

	if (this->m_Month > 13)
	{
		return false;
	}

	if (this->m_Month == 3 && this->m_Day >= 30)
	{
		return false;
	}

	if ((this->m_Month == 4 || this->m_Month == 6 || this->m_Month == 9 || this->m_Month == 11) && this->m_Day > 30)
	{
		return false;
	}

	if (!((this->m_Year % 4 == 0 && this->m_Year % 100 != 0) || this->m_Year % 400 == 0) && this->m_Day >= 29)
	{
		return false;
	}

	return true;
}
