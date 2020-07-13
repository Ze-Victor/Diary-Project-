#ifndef UTILITIES_H
#define UTILITIES_H

#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "message.h"
#include "date.h"

	std::string format_string(std::string format);
	std::string get_date();
	std::string get_time();
	bool compare( std::string filename);
	void continue_enter();
	void file_config();
	std::string get_path();
	std::string get_format();
	std::string format_message(std::string format, Message m);


#endif