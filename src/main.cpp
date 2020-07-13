#include "../include/app.h"

int main(int argc, char* argv[]){

    App aplicativo(get_path());
    return aplicativo.run(argc, argv);
}
