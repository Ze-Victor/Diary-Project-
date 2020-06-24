#include "../include/diary.h"

Diary::Diary(const std::string& filename) : filename(filename), messages(nullptr), 
messages_capacity(10), messages_size(0)
{
	messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message)
{
	int aux = messages_size;
    if(messages_size < messages_capacity){
    	messages[messages_size].content = message;
    	messages_size++;
    	std::cout << "Mensagem adicionada. " << std::endl;
    }
    else{
    	std::cout << "Limite de mensagens atingido." << std::endl;
    	return;
    }

}

void Diary::write()
{
    // gravar as mensagens no disco
}