#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "Game.h"
#include "Utils.h"
#include "Dices.h"
int jugar();
int lanzar();

using namespace std;

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

int jugar(){
    int numero[6];
    int rondas = 1, intentos = 0;
    int puntajeMaximo = 0, puntajeMaximoRonda = 0;

    while(true){
        intentos++;

        cargarAleatorio(numero, 6, 6);
        DibujarDados(numero);
        //ver si es escalera
        //6 iguales -> si son 6 puntos es 0

        //intentos x ronda
        if(intentos == 3){
        //actualizamos el valor de los puntos maximos que tenemos

        //definir si ganamos
        };

        system("pause");
    }
}





#endif // JUEGO_H_INCLUDED
