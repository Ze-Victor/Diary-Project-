#ifndef MESSAGE_H
#define MESSAGE_H

#include "date.h"
#include "time.h"

#include <string>

struct Message
{
    std::string content;
    Date date;
    Time time;
};

#endif