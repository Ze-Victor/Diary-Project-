#ifndef TIME_DATE_H
#define TIME_DATE_H

#include <string>

struct Time_date
{
	unsigned short int day, month, year;
	unsigned short int hour, minute, second;

	std::string format_current_date(const std::string &format);
	std::string get_current_date();
	std::string get_current_time();

};

#endif