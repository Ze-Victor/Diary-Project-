#include "../include/diary.h"

Diary::Diary(const std::string& filename) : filename(filename), messages(nullptr), 
messages_capacity(10), messages_size(0)
{
    messages_size = 0;
	messages = new Message[messages_capacity];
}
Diary::~Diary(){
    delete[] messages;
}
void Diary::add(const std::string& message)
{
    Message m;

    m.content = message;
    m.date.set_from_string(get_date());
    m.time.set_from_string(get_time());

    messages[messages_size] = m;
    messages_size++;

    if(messages_size == messages_capacity) return;

}

void Diary::write()
{
    // gravar as mensagens no disco
}