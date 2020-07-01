#include "../include/diary.h"

Diary::Diary(const std::string& name) : filename(name)
{
    std::ifstream file_in(filename);
    if(file_in.is_open()){
        std::string aux;
        char discard;
        getline(file_in, aux);
        Message m;

        while(!file_in.eof() && aux.size() != 0){

            std::stringstream stream (aux);
            stream >> discard;

            aux = discard;

            if(aux == "#"){
                stream >> m.date.day;
                stream >> discard;
                stream >> m.date.month;
                stream >> discard;
                stream >> m.date.year;
                getline(file_in, aux);
                std::stringstream stream (aux);
                stream >> discard;
                aux = discard;
                if(aux == "-"){
                    stream >> m.time.hour;
                    stream >> discard;
                    stream >> m.time.minute;
                    stream >> discard;
                    stream >> m.time.second;
                    stream >> discard;
                    getline(stream, m.content);
                }
                messages.push_back(m);

            }else if(aux == "-"){
                stream >> m.time.hour;
                stream >> discard;
                stream >> m.time.minute;
                stream >> discard;
                stream >> m.time.second;
                stream >> discard;
                getline(stream, m.content);
                m.date.day = messages[(messages.size())-1].date.day;
                m.date.month = messages[(messages.size())-1].date.month;
                m.date.year = messages[(messages.size())-1].date.year;
                messages.push_back(m);
            }

            getline(file_in, aux);
        }
    }

    file_in.close();
}
void Diary::add(const std::string& message)
{
    Message m;
    std::string aux_Saida;

    m.content = message;
    m.date.set_from_string(get_date());
    m.time.set_from_string(get_time());

    messages.push_back(m);
    aux_Saida = "- " + messages[(messages.size())-1].time.to_string()
                + ": " + messages[(messages.size())-1].content + "\n";
    write(aux_Saida);
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
std::vector<Message*> Diary::search(std::string what){
     std::size_t found;
     std::vector< Message* > m_search;
    for (auto it = messages.begin(); it < messages.end(); ++it)
    {
        found = (*it).content.find(what);
        if (found!=std::string::npos){
            m_search.push_back(&(*it));
        }
    }
    return m_search;
}