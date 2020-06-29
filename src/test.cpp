#include "../include/date.h"
#include "../include/diary.h"
#include "../include/app.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
	App di("Arquivo.md");
	di.list_messages();
}
