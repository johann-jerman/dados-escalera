#ifndef DICES_H_INCLUDED
#define DICES_H_INCLUDED

#include <string>

using namespace std;

void DibujarDados(int dados[]){
    std::cout << "*-------* *-------* *-------* *-------* *-------* *-------*\n";
    std::cout << "|       | |       | |       | |       | |       | |       |\n";
    std::cout << "|   "<<dados[0]<<"   | |   "<<dados[1]<<"   | |   "<<dados[2]<<"   | |   "<< dados[3]<<"   | |   "<<dados[4]<<"   | |   "<<dados[5]<<"   |\n";
    std::cout << "|       | |       | |       | |       | |       | |       |\n";
    std::cout << "*-------* *-------* *-------* *-------* *-------* *-------*\n";
    //printf("*-------* *-------* *-------* *-------* *-------* *-------*\n");
    //printf("|       | |       | |       | |       | |       | |       |\n");
    //printf("|   1   | |   1   | |   1   | |   1   | |   1   | |   1   |\n");
    //printf("|       | |       | |       | |       | |       | |       |\n");
    //printf("*-------* *-------* *-------* *-------* *-------* *-------*\n");

}

void GeneradDadosRandom(){

}

void GeneradDadosModoPrueba(){

}

#endif // DICES_H_INCLUDED
