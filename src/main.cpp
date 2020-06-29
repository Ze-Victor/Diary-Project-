#include "../include/app.h"

int main(int argc, char* argv[]){

    App aplicativo("diary.md");
    for (int i = 0; i < 100; ++i)
    {
    	aplicativo.add("Mes");
    }
    return aplicativo.run(argc, argv);
}
