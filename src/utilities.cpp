#include "../include/utilities.h"
#include <iostream>

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
bool compare(std::string filename){
	Date d;
    d.set_from_string(get_date());
    std::string aux_date, aux;
    aux_date = d.to_string();
    bool validator = false;

    std::ifstream read(filename);
    if(read.is_open()){
    	while(!read.eof()){
			std::getline(read, aux);
		    if(aux == "# " + aux_date){
		    validator = true;
		    break;
		    }
   		}
    }
   read.close();

    return validator;

}