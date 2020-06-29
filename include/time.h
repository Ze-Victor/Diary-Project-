#ifndef TIME_H
#define TIME_H

#include <string>
#include <iostream>
#include <sstream>

struct Time
{
	Time();
    unsigned hour;
    unsigned minute;
    unsigned second;
    
    void set_from_string(const std::string& time);
    std::string to_string();
};

#endif