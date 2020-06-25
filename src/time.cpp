#include "../include/time.h"

Time::Time() : hour(0), minute(0), second(0)
{

}
void Time::set_from_string(const std::string& time){

	Time t;
	char discard;

	std::stringstream stream(time);

	stream >> t.hour;
	stream >> discard;
	stream >> t.minute;
	stream >> discard;
	stream >> t.second;

}