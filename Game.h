#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "Game.h"
#include "Utils.h"
#include "Dices.h"
#include "Player.h"
int jugar();
int lanzar();

using namespace std;

int jugar(){
    int numero[6];
    int rondas = 1, intentos = 0;
    int puntajeTotal = 0, puntajeRonda = 0, puntajeIntento = 0;

    while(true){
        system("cls");
        intentos++;

        //generamos los dados aleatorios
        cargarAleatorio(numero, 6, 6);

        bool dadosIguales = sonIguales(numero, 6);
        bool dadosEscalera = esEscalera(numero, 6);
        //ver si es escalera
        if(dadosEscalera == 1){
            puntajeTotal = puntajeParaGanar;
        }
        //todos los dados son iguales a 6
        if(dadosIguales && numero[0] == 6){
            puntajeTotal = 0;
        }
        //todos los dados son >= 5
        if(dadosIguales && numero[0] != 6){
            puntajeIntento = numero[0] * 10;
        }
        // los dados no son iguales ni escalera
        if(!dadosIguales && !dadosEscalera){
            puntajeIntento = sumaVector(numero, cantidadDados);
        }

        //intentos x ronda
        if(intentos <= 3 && puntajeIntento > puntajeRonda){
            puntajeRonda = puntajeIntento;
        }

        imprimirCabezera(rondas, puntajeTotal, puntajeRonda, intentos, puntajeIntento);
        DibujarDados(numero);

        if(intentos == 3){
            //actualizamos el valor de los puntos maximos que tenemos
            //actualizar la ronda y la cantidad de intentos
            intentos = 0;
            rondas++;
            puntajeTotal += puntajeRonda;
            puntajeRonda = 0;
            puntajeIntento = 0;
            //definir si ganamos
        };
        if(puntajeTotal >= puntajeParaGanar){
            return puntajeTotal;
        }
        //system("pause");
        system("pause");
    }
}

int jugarDuo(){
}

int jugarSimulado(){
    int numero[6];
    int rondas = 1, intentos = 0;
    int puntajeTotal = 0, puntajeRonda = 0, puntajeIntento = 0;

    while(true){
        system("cls");
        intentos++;

        //Pedimos los numeros que queres que te salgan en los dados
        for(int i = 0; i < cantidadDados; i++){
            int valor;
            cout << "Ingrese el valor del dado numero " << i+1 << ": ";
            cin >> valor;
            numero[i] = valor;
        }

        bool dadosIguales = sonIguales(numero, 6);
        bool dadosEscalera = esEscalera(numero, 6);
        //ver si es escalera
        if(dadosEscalera == 1){
            puntajeTotal = puntajeParaGanar;
        }
        //todos los dados son iguales a 6
        if(dadosIguales && numero[0] == 6){
            puntajeTotal = 0;
        }
        //todos los dados son >= 5
        if(dadosIguales && numero[0] != 6){
            puntajeIntento = numero[0] * 10;
        }
        // los dados no son iguales ni escalera
        if(!dadosIguales && !dadosEscalera){
            puntajeIntento = sumaVector(numero, cantidadDados);
        }

        //intentos x ronda
        if(intentos <= 3 && puntajeIntento > puntajeRonda){
            puntajeRonda = puntajeIntento;
        }

        imprimirCabezera(rondas, puntajeTotal, puntajeRonda, intentos, puntajeIntento);
        DibujarDados(numero);

        if(intentos == 3){
            //actualizamos el valor de los puntos maximos que tenemos
            //actualizar la ronda y la cantidad de intentos
            intentos = 0;
            rondas++;
            puntajeTotal += puntajeRonda;
            puntajeRonda = 0;
            puntajeIntento = 0;
            //definir si ganamos
        };
        if(puntajeTotal >= puntajeParaGanar){
            return puntajeTotal;
        }
        //system("pause");
        system("pause");
    }
}



#endif // JUEGO_H_INCLUDED
