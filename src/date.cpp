#include "../include/date.h"

Date::Date(): year(0), month(0), day(0)
{

}
void Date::set_from_string(const std::string& date){

	Date d;
	char discard;

	std::stringstream stream(date);

	stream >> d.day;
	stream >> discard;
	stream >> d.month;
	stream >> discard;
	stream >> d.year;
}