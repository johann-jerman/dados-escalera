#include <iostream>
#include <locale>
#include <codecvt>
#include <cstdio>
#include "Menu.h"
#include "Utils.h"
#include "Dices.h"

using namespace std;

int main() {

    menu();
    srand(time(NULL));
    srand(getpid());
    int dados[6];
    dados[0] = 5;
    dados[1] = 5;
    dados[2] = 5;
    dados[3] = 5;
    dados[4] = 5;
    dados[5] = 5;

    //DibujarDados(dados);

    return 0;
}
