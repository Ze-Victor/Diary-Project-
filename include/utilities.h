#ifndef UTILITIES_H
#define UTILITIES_H

#include <ctime>
#include <string>
#include <fstream>
#include "date.h"

	std::string format_string(std::string format);
	std::string get_date();
	std::string get_time();
	bool compare( std::string filename);


#endif