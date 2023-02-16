#pragma once



class Date
{
public:
	unsigned int m_Day;
	unsigned int m_Month;
	unsigned int m_Year;

public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year);
	//const char* Stringfy();
};



bool DateValidation(Date date);
bool DateValidation(int day, int month, int year);






