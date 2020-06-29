#include "../include/diary.h"

Diary::Diary(const std::string& name) : filename(name), messages(nullptr), 
messages_capacity(10), messages_size(0)
{
    messages_size = 0;
	messages = new Message[messages_capacity];
    std::ifstream file_in(filename);
    if(file_in.is_open()){
        std::string aux;
        char discard;
        getline(file_in, aux);

        while(!file_in.eof() && aux.size() != 0){

            std::stringstream stream (aux);
            stream >> discard;

            aux = discard;

            if(aux == "#"){
                stream >> messages[messages_size].date.day;
                stream >> discard;
                stream >> messages[messages_size].date.month;
                stream >> discard;
                stream >> messages[messages_size].date.year;
                getline(file_in, aux);
                std::stringstream stream (aux);
                stream >> discard;
                aux = discard;
                if(aux == "-"){
                    stream >> messages[messages_size].time.hour;
                    stream >> discard;
                    stream >> messages[messages_size].time.minute;
                    stream >> discard;
                    stream >> messages[messages_size].time.second;
                    stream >> discard;
                    getline(stream, messages[messages_size].content);
                }
                messages_size++;

            }else if(aux == "-"){
                stream >> messages[messages_size].time.hour;
                stream >> discard;
                stream >> messages[messages_size].time.minute;
                stream >> discard;
                stream >> messages[messages_size].time.second;
                stream >> discard;
                getline(stream, messages[messages_size].content);
                messages[messages_size].date.day = messages[messages_size-1].date.day;
                messages[messages_size].date.month = messages[messages_size-1].date.month;
                messages[messages_size].date.year = messages[messages_size-1].date.year;
                messages_size++;
            }
            if(messages_size == messages_capacity){
                    messages_capacity *=2;
                    Message* new_messages = new Message[messages_capacity];
                    for(int i = 0;i<(messages_capacity/2); i++){
                    new_messages[i] = messages[i];
                }
                delete[] messages;
                messages = new_messages;
            }
            getline(file_in, aux);
        }
    }

    file_in.close();
}
Diary::~Diary(){
    delete[] messages;
}
void Diary::add(const std::string& message)
{
    Message m;
    std::string aux_Saida;

    m.content = message;
    m.date.set_from_string(get_date());
    m.time.set_from_string(get_time());

    messages[messages_size] = m;
    aux_Saida = "- " + messages[messages_size].time.to_string()
                + ": " + messages[messages_size].content + "\n";
    write(aux_Saida);
    messages_size++;

    if(messages_size == messages_capacity){
        messages_capacity *=2;
        Message* new_messages = new Message[messages_capacity];
        for(int i = 0;i<(messages_capacity/2); i++){
            new_messages[i] = messages[i];
        }
        delete[] messages;
        messages = new_messages;
    };

}

void Diary::write(std::string message)
{
    bool validator = compare(filename);
    Date d;
    d.set_from_string(get_date());
    std::string aux = d.to_string();

    std::ofstream file_out(filename, std::ios::app);

    if(validator == true){
        file_out << message;

    } else{
        
        file_out << "# " << aux << "\n" << message;

    }

    file_out.close();
}