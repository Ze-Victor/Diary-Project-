#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include <fstream>

#include "diary.h"

void printError(std::string n_prog);
std::string format_current_date(const std::string &format);
std::string get_current_date();
std::string get_current_time();

int main(int argc, char* argv[]){

	//Arquivo de saída
	std::ofstream file_out("arquivo.txt", std::ios::app);
	std::string message, verificador, auxiliarSaida;
	bool validator;

	if(file_out.fail()){
		std::cerr << "O arquivo não pode ser aberto" << std::endl;
		return 1;
	}

	//Arquivo de entrada
	std::ifstream file_in("arquivo.txt");

	if(file_in.fail()){
		std::cerr << "O arquivo não pode ser aberto." << std::endl;
		return 1;
	}

	if(argc == 1){
		
		printError(argv[0]);
		return 1;

	}

	if(argc > 1 && strcmp(argv[1], "add") != 0 && strcmp(argv[1], "list") != 0){
		printError(argv[0]);
		return 1;
	}

	if (strcmp(argv[1], "add") == 0 && argc < 3)
	{
		verificador = "# " + get_current_date();
		while(!file_in.eof() && message != verificador){
			std::getline(file_in, message);
			if(message == verificador){
				validator = true;
			}
		}

		std::cout << "Informe uma mensagem: " << std::endl;
		std::getline(std::cin, message);

		if (validator == true)
		{
			file_out << " - " << get_current_time() << " " << message << "\n";

		}else{
			file_out <<  verificador << "\n" << " - " << get_current_time() << " " << message << "\n";
		}
		

	}else if(strcmp(argv[1], "list") == 0 && argc < 3){

		while(!file_in.eof()){
			std::getline(file_in, message);
			if(message.size() == 0){
				continue;
			}
			if(message.length() != 12){
				std::cout << message << std::endl;
			}
		}

	}else{

		verificador = "# " + get_current_date();
		while(!file_in.eof() && message != verificador){
			std::getline(file_in, message);
			if(message == verificador){
				validator = true;
			}
		}
		if(validator == true){
			message = argv[2];
			file_out << " - " << get_current_time() << " " << message << "\n";

		} else{
			message = argv[2];
			file_out << verificador << "\n" << " - " << get_current_time() << " " << message << "\n";
		} 
	}

	file_out.close();
	file_in.close();

	return 0;
}

void printError(std::string n_prog){
	std::cout << "Uso: " << n_prog << " add <message>" << std::endl;
	std::cout << "Uso: " << n_prog << " list" << std::endl;
}


std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  //std::cout << sizeof(result) << std::endl;

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { return format_current_date("%d/%m/%Y"); }

std::string get_current_time() { return format_current_date("%H:%M:%S"); }
