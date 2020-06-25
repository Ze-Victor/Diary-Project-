#ifndef DIARY_H
#define DIARY_H

#include "message.h"
#include "utilities.h"


#include <string>
#include <iostream>

struct Diary
{
    Diary(const std::string& filename);
    ~Diary();

    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string& message);
    void write();
};

#endif