#include "../include/app.h"

#include <iostream>
#include <string>
#include <sstream>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return show_usage();
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
        add();
        }else{
        std::string message = argv[2];
        add(message);
        }
    }else if(action == "list"){
        if(argc == 2){
            list_messages(get_format());
        }else{
            std::string format = argv[2];
            list_messages(format);
        }
         
    }else if(action == "interactive") {
        diary_interactive();
    }
    else if (action == "search") {
        if(argc == 2){
            search();
        }else{
            std::string message = argv[2];
            search_messege(message);
        }
        
    } else {
        return show_usage();
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::stringstream stream;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    //diary.write();
}

void App::list_messages(std::string format)
{
    if(diary.messages.size() == 0){
        std::cout << "Não há mensages" << std::endl;
    }
    for (size_t i = 0; i < diary.messages.size(); ++i) {
        const Message& message = diary.messages[i];
        std::cout << format_message(format, message) << std::endl;
    }
}

int App::show_usage() {
    std::cerr << "Bad Use" << std::endl;
    return 1;
}
void App::search()
{
    std::string message;
    std::stringstream stream;
    std::cout << "Enter your word:" << std::endl;
    std::getline(std::cin, message);

    search_messege(message);
}
void App::search_messege(std::string message){

    std::vector<Message*> what = diary.search(message);

    if(what.empty()){
        std::cout << "Não existe mensages com a palavra '" << message << "' no diário." << std::endl;
    }else{
        for (auto i : what)
        {
            std::cout << " -> " <<  i->content << std::endl;
        }
    }
}
void App::diary_interactive(){
    int op;
    bool interactive = true;
    std::string message;

    std::cout << "Bem vindo ao seu diário. Escolha uma opção do quadro abaixo para continuar. ^^" << std::endl;

    while(interactive == true){
        std::cout << std::endl;
        std::cout<< "+-------------------------------------+" << std::endl;
        std::cout<< "|           OPÇÕES DE ENTRADA         |" <<std::endl;
        std::cout<< "+-------------------------------------+" << std::endl;
        std::cout<< "|                                     |" <<std::endl;
        std::cout<< "|   1 - Listar Mensagens              |" <<std::endl;
        std::cout<< "|   2 - Adicionar nova mensagem       |" <<std::endl;
        std::cout<< "|                                     |" <<std::endl;
        std::cout<< "|   0 - Finalizar                     |" <<std::endl;
        std::cout<< "|                                     |" <<std::endl;
        std::cout<< "+-------------------------------------+" << std::endl;

        std::cin >> op;
        std::cin.ignore();

        if(op==0){
            interactive = false;
        }
        else if(op==1){
            std::cout << std::endl;
            list_messages(get_format());
            continue_enter();
        }
        else if(op==2){
            add();
            continue_enter();
        }
        else{
            std::cout << "Opção inválida. Tente novamente! " << std::endl;
            continue_enter();
        }

        system("clear");
    }

}
