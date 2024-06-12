#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

using namespace std;

void imprimirCabezera(
        int ronda,
        int puntajeTotal,
        int puntajeMaximoRonda,
        int intento,
        int puntajeIntento
){
    cout << "\n";
    cout << " Ronda Numero " << ronda << " | Puntaje Total: " << puntajeTotal << "\n";
    cout << "------------------------------------------------------------------------\n";
    cout << " Maximo Puntaje de la Ronda: " << puntajeMaximoRonda << "\n";
    cout << " Intento " << intento << " | " << "PuntajeIntento " << puntajeIntento <<"\n";
    cout << "\n";

}

void imprimirFinalRonda(int ronda, string nombreJugador, int puntajeTotal, int puntajeRonda){
    cout << "------------------------------------";
    cout << "Ronda Numero " << ronda;
    cout << "Nombre de jugador" << nombreJugador;
    cout << "Puntaje Total " << puntajeTotal;
    cout << "PuntajeRonda " << puntajeRonda;
    cout << "------------------------------------";
}

#endif // PLAYER_H_INCLUDED
