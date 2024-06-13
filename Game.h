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
            imprimirFinalRonda(rondas, nombre, puntajeTotal, puntajeRonda);
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
  int numero[6];
  int rondas = 1, intentos = 0;
  int puntajeTotalJugador1 = 0, puntajeRondaJugador1 = 0, puntajeIntentoJugador1 = 0;
  int puntajeTotalJugador2 = 0, puntajeRondaJugador2 = 0, puntajeIntentoJugador2 = 0;
  string jugadorActual = nombre; // Inicia el juego el jugador 1

  while(true){
    system("cls");

    // Turno del jugador 1
    if (jugadorActual == nombre){
      intentos = 0;
      puntajeRondaJugador1 = 0;
      puntajeIntentoJugador1 = 0;

      while (intentos < 3){
        intentos++;

        // Generar dados aleatorios
        cargarAleatorio(numero, 6, 6);

        // Calcular puntuaciones
        bool dadosIguales = sonIguales(numero, 6);
        bool dadosEscalera = esEscalera(numero, 6);

        if (dadosEscalera == 1){
          puntajeRondaJugador1 = puntajeParaGanar;
        } else if (dadosIguales && numero[0] == 6){
          puntajeTotalJugador1 = 0;
        } else if (dadosIguales && numero[0] != 6){
          puntajeIntentoJugador1 = numero[0] * 10;
        } else {
          puntajeIntentoJugador1 = sumaVector(numero, cantidadDados);
        }

        // Actualizar puntuaciones
        if (intentos <= 3 && puntajeIntentoJugador1 > puntajeRondaJugador1){
          puntajeRondaJugador1 = puntajeIntentoJugador1;
        }

        // Mostrar informaci�n
        imprimirCabezera(rondas, puntajeTotalJugador1, puntajeRondaJugador1, intentos, puntajeIntentoJugador1, nombre);
        DibujarDados(numero);
        system("pause");
        system("cls");
      }

      // Actualizar puntuaciones totales
      puntajeTotalJugador1 += puntajeRondaJugador1;

      // Cambiar de turno
      imprimirFinalRonda(rondas,nombre, puntajeTotalJugador1,puntajeRondaJugador1);
      jugadorActual = nombrePlayer2;
    }

    //player2
   if (jugadorActual == nombrePlayer2){
      intentos = 0;
      puntajeRondaJugador2 = 0;
      puntajeIntentoJugador2 = 0;

      while (intentos < 3){
        intentos++;

        // Generar dados aleatorios
        cargarAleatorio(numero, 6, 6);

        // Calcular puntuaciones
        bool dadosIguales = sonIguales(numero, 6);
        bool dadosEscalera = esEscalera(numero, 6);

        if (dadosEscalera == 1){
          puntajeRondaJugador2 = puntajeParaGanar;
        } else if (dadosIguales && numero[0] == 6){
          puntajeTotalJugador2 = 0;
        } else if (dadosIguales && numero[0] != 6){
          puntajeIntentoJugador2 = numero[0] * 10;
        } else {
          puntajeIntentoJugador2 = sumaVector(numero, cantidadDados);
        }

        // Actualizar puntuaciones
        if (intentos <= 3 && puntajeIntentoJugador2 > puntajeRondaJugador2){
          puntajeRondaJugador2 = puntajeIntentoJugador2;
        }

        // Mostrar informaci�n
        imprimirCabezera(rondas, puntajeTotalJugador2, puntajeRondaJugador2, intentos, puntajeIntentoJugador2, nombrePlayer2);
        DibujarDados(numero);
        system("pause");

        system("cls");
      }

      // Actualizar puntuaciones totales
      puntajeTotalJugador2 += puntajeRondaJugador2;
      rondas++;
      // Cambiar de turno
      imprimirFinalRonda(rondas,nombrePlayer2, puntajeTotalJugador2,puntajeRondaJugador2);
      jugadorActual = nombre;
    }

    // Comprobar ganador
    if (puntajeTotalJugador1 >= puntajeParaGanar || puntajeTotalJugador2 >= puntajeParaGanar){
      // Determinar ganador y mostrar mensaje final
      return puntajeTotalJugador1 > puntajeTotalJugador2 ? puntajeTotalJugador1 : puntajeTotalJugador2;
    }

    //system("pause");
    system("pause");
  }
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
            if(valor > 6 || valor < 1){
                cout << "Debe ingresar un numero entre 1 y 6 \n";
                i++;
                continue;
            }
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
int jugarSimuladoDuo(){
  int numero[6];
  int rondas = 1, intentos = 0;
  int puntajeTotalJugador1 = 0, puntajeRondaJugador1 = 0, puntajeIntentoJugador1 = 0;
  int puntajeTotalJugador2 = 0, puntajeRondaJugador2 = 0, puntajeIntentoJugador2 = 0;
  string jugadorActual = nombre; // Inicia el juego el jugador 1

  while(true){
    system("cls");

    // Turno del jugador 1
    if (jugadorActual == nombre){
      intentos = 0;
      puntajeRondaJugador1 = 0;
      puntajeIntentoJugador1 = 0;

      while (intentos < 3){
        intentos++;

        //Pedimos los numeros que queres que te salgan en los dados
        for(int i = 0; i < cantidadDados; i++){
            int valor;
            cout << "Ingrese el valor del dado numero " << i+1 << ": ";
            cin >> valor;
            if(valor > 6 || valor < 1){
                cout << "Debe ingresar un numero entre 1 y 6 \n";
                i++;
                continue;
            }
            numero[i] = valor;
        }

        // Calcular puntuaciones
        bool dadosIguales = sonIguales(numero, 6);
        bool dadosEscalera = esEscalera(numero, 6);

        if (dadosEscalera == 1){
          puntajeRondaJugador1 = puntajeParaGanar;
        } else if (dadosIguales && numero[0] == 6){
          puntajeTotalJugador1 = 0;
        } else if (dadosIguales && numero[0] != 6){
          puntajeIntentoJugador1 = numero[0] * 10;
        } else {
          puntajeIntentoJugador1 = sumaVector(numero, cantidadDados);
        }

        // Actualizar puntuaciones
        if (intentos <= 3 && puntajeIntentoJugador1 > puntajeRondaJugador1){
          puntajeRondaJugador1 = puntajeIntentoJugador1;
        }

        // Mostrar informaci�n
        imprimirCabezera(rondas, puntajeTotalJugador1, puntajeRondaJugador1, intentos, puntajeIntentoJugador1, nombre);
        DibujarDados(numero);
        system("pause");
        system("cls");
      }

      // Actualizar puntuaciones totales
      puntajeTotalJugador1 += puntajeRondaJugador1;

      // Cambiar de turno
      imprimirFinalRonda(rondas,nombre, puntajeTotalJugador1,puntajeRondaJugador1);
      jugadorActual = nombrePlayer2;
    }

    //player2
   if (jugadorActual == nombrePlayer2){
      intentos = 0;
      puntajeRondaJugador2 = 0;
      puntajeIntentoJugador2 = 0;

      while (intentos < 3){
        intentos++;

        //Pedimos los numeros que queres que te salgan en los dados
        for(int i = 0; i < cantidadDados; i++){
            int valor;
            cout << "Ingrese el valor del dado numero " << i+1 << ": ";
            cin >> valor;
            if(valor > 6 || valor < 1){
                cout << "Debe ingresar un numero entre 1 y 6 \n";
                i++;
                continue;
            }
            numero[i] = valor;
        }

        // Calcular puntuaciones
        bool dadosIguales = sonIguales(numero, 6);
        bool dadosEscalera = esEscalera(numero, 6);

        if (dadosEscalera == 1){
          puntajeRondaJugador2 = puntajeParaGanar;
        } else if (dadosIguales && numero[0] == 6){
          puntajeTotalJugador2 = 0;
        } else if (dadosIguales && numero[0] != 6){
          puntajeIntentoJugador2 = numero[0] * 10;
        } else {
          puntajeIntentoJugador2 = sumaVector(numero, cantidadDados);
        }

        // Actualizar puntuaciones
        if (intentos <= 3 && puntajeIntentoJugador2 > puntajeRondaJugador2){
          puntajeRondaJugador2 = puntajeIntentoJugador2;
        }

        // Mostrar informaci�n
        imprimirCabezera(rondas, puntajeTotalJugador2, puntajeRondaJugador2, intentos, puntajeIntentoJugador2, nombrePlayer2);
        DibujarDados(numero);
        system("pause");

        system("cls");
      }

      // Actualizar puntuaciones totales
      puntajeTotalJugador2 += puntajeRondaJugador2;
      rondas++;
      // Cambiar de turno
      imprimirFinalRonda(rondas,nombrePlayer2, puntajeTotalJugador2,puntajeRondaJugador2);
      jugadorActual = nombre;
    }

    // Comprobar ganador
    if (puntajeTotalJugador1 >= puntajeParaGanar || puntajeTotalJugador2 >= puntajeParaGanar){
      // Determinar ganador y mostrar mensaje final
      return puntajeTotalJugador1 > puntajeTotalJugador2 ? puntajeTotalJugador1 : puntajeTotalJugador2;
    }

    //system("pause");
    system("pause");
  }
}


#endif // JUEGO_H_INCLUDED
