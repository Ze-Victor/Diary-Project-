#include "../include/utilities.h"

std::string format_string(std::string format){
	time_t t;
	time(&t);

	struct tm * dataLocal;
	dataLocal = localtime(&t);

	std::string aux_time = std::to_string(dataLocal->tm_hour) + ":"
						 + std::to_string(dataLocal->tm_min) + ":"
						 + std::to_string(dataLocal->tm_sec);

	std::string aux_date = std::to_string(dataLocal->tm_mday) + "/"
						 + std::to_string(dataLocal->tm_mon+1) + "/"
						 + std::to_string(dataLocal->tm_year+1900);


	if(format == "date") return aux_date;
	else return aux_time;

}
std::string get_date(){
	return format_string("date");
}
std::string get_time(){
	return format_string("time");
}