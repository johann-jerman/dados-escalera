#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Game.h"
#include "Player.h"
void menu();


using namespace std;

void menu(){
    int opcion;



    while(true){
        system("cls");
        if(nombre != ""){
            cout << "Hola " << nombre << endl;
            cout << "------------------------------\n"<< endl;
        }

        cout << "1- Cargar Nombre" << endl;
        cout << "2- Jugar solo " << endl;
        cout << "3- Jugar doble " << endl;
        cout << "0- Salir" << endl;
        cout << "----------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){
        case 1:
            cout << "Ingrese nombre jugador 1: ";
            cin.ignore(); /// ignora el enter del cin anterior
            getline(cin, nombre);
            break;
        case 2:
            {
                int puntos;
                system("cls");
                puntos = jugar();

                system("cls");
                cout << "Bien! El jugador " << nombre ;
                cout << " obtuvo " << puntos << " puntos"<< endl;
                system("pause");
            }
            break;
        case 3:
            {
                int puntos;
                puntos = jugarDuo();

                system("cls");
                cout << "Bien! El jugador " << nombre << "Es el ganador \n" ;
                cout << " obtuvo " << puntos << " puntos"<< endl;
                system("pause");
            }
            break;
        case 4:
            {
                //modo simulado
                int puntos;
                puntos = jugarSimulado();
                system("cls");
                cout << "Bien! El jugador " << nombre ;
                cout << " obtuvo " << puntos << " puntos"<< endl;
                system("pause");
            }
        case 5:
            {
                         //modo simulado
                int puntos;
                puntos = jugarSimuladoDuo();
                system("cls");
                cout << " obtuvo " << puntos << " puntos"<< endl;
                system("pause");

            }
        case 0:
            return;
        }

    }
}


#endif // MENU_H_INCLUDED
