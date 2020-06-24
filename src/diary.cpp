#include "../include/diary.h"

Diary::Diary(const std::string& filename) : filename(filename), messages(nullptr), 
messages_capacity(10), messages_size(0)
{
    messages_size = 0;
	messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message)
{
    std::string m;
    m = message;
    messages[messages_size].content = m;
    messages_size++;
    std::cout << "Mensagem adicionada. " << std::endl;

    if(messages_size < messages_capacity) return;

}

void Diary::write()
{
    // gravar as mensagens no disco
}