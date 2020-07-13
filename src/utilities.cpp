#include "../include/utilities.h"

std::string format_string(std::string format){
	time_t t;
	time(&t);

	struct tm * dataLocal;
	dataLocal = localtime(&t);

	std::string aux_time = std::to_string(dataLocal->tm_hour) + ":"
						 + std::to_string(dataLocal->tm_min) + ":"
						 + std::to_string(dataLocal->tm_sec);

	std::string aux_date = std::to_string(dataLocal->tm_mday) + "/"
						 + std::to_string(dataLocal->tm_mon+1) + "/"
						 + std::to_string(dataLocal->tm_year+1900);


	if(format == "date") return aux_date;
	else return aux_time;

}
std::string get_date(){
	return format_string("date");
}
std::string get_time(){
	return format_string("time");
}
bool compare(std::string filename){
	Date d;
    d.set_from_string(get_date());
    std::string aux_date, aux;
    aux_date = d.to_string();
    bool validator = false;

    std::ifstream read(filename);
    if(read.is_open()){
    	while(!read.eof()){
			std::getline(read, aux);
		    if(aux == "# " + aux_date){
		    validator = true;
		    break;
		    }
   		}
    }
   read.close();

    return validator;

}

void continue_enter(){
	std::cout << "Pressione ENTER para continuar... " << std::endl;
    std::cin.ignore();
}
void file_config(){

	std::ofstream file("diary.config");
	file << "path=" << "diary.md" << "\n";
	file << "default_format=%d %t: %m" << "\n";

	file.close();
}
std::string get_path(){

		std::ifstream file("diary.config");
		if(file.fail()){
			file_config();
		}

		std::string aux, path;
		getline(file, aux);

		std::stringstream stream(aux);

		char discard;
		

		aux = " ";
		while(aux != "="){
			stream >> discard;
			aux = discard;
		}
		stream >> path;

		file.close();

		return path;
}
std::string get_format(){

		std::ifstream file("diary.config");
		if(file.fail()){
			file_config();
		}

		std::string aux, format;
		getline(file, aux);
		getline(file, aux);

		std::stringstream stream(aux);

		char discard;
		aux = " ";
		while(aux != "="){
			stream >> discard;
			aux = discard;
		}
		
		getline(stream, format);

		file.close();

		return format;
}
std::string format_message(std::string format, Message m){

	std::stringstream stream(format);


	size_t end = format.size();
	char discard;
	std::string aux, saida;
	saida = "";

	stream >> std::noskipws >> discard;

	while(end > 0){

		aux = discard;

		if(aux == "%"){
			end--;
			stream >> std::noskipws >> discard;

			aux = discard;
			if(aux == "d"){
				saida += m.date.to_string();
			}else if(aux == "t"){
				saida += m.time.to_string();
			}else if(aux == "m"){
				saida += m.content;
			}else{
				saida += "%"+aux;
			}
		}else{
			saida += aux;
		}
		stream >> std::noskipws >> discard;
		end--;
	}

	return saida;

}
