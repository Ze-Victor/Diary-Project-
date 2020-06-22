#ifndef DIARY_H
#define DIARY_H

#include "message.h"

struct Diary{

	int action;

	Message add_message(const message& content_formated);
	Message list_messages();

};

#endif