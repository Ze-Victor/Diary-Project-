#ifndef MESSAGE_H
#define MESSAGE_H

#include "time_date.h"

struct Message
{
	Time_date registration_date;
	Time_date registration_time;
	std::string content;

	std::bool compare_date(const Time_date& date_other_message);
	std::string format_messege(const Time_date& date, const Time_date& time, const std::string& content);
	
};

#endif