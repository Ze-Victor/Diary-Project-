#ifndef APP_H
#define APP_H

#include "diary.h"

#include <string>

struct App
{
    Diary diary;

    App(const std::string& filename);
    int run(int argc, char* argv[]);
    int show_usage();
    void add();
    void add(const std::string message);
    void list_messages(std::string format);
    void search();
    void search_messege(std::string message);
    void diary_interactive();
};

#endif