#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

using namespace std;

string nombre = "Jugador";
string nombrePlayer2 = "Jugador2";

//imprimir cabezera pero sin el nombre
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

//sobreescribimos imprimir cabezera pero con el nombre
void imprimirCabezera(
        int ronda,
        int puntajeTotal,
        int puntajeMaximoRonda,
        int intento,
        int puntajeIntento,
        string nombre
){
    cout << "\n";
    cout << "Nombre: "<< nombre <<" | Ronda Numero " << ronda << " | Puntaje Total: " << puntajeTotal << "\n";
    cout << "------------------------------------------------------------------------\n";
    cout << " Maximo Puntaje de la Ronda: " << puntajeMaximoRonda << "\n";
    cout << " Intento " << intento << " | " << "PuntajeIntento " << puntajeIntento <<"\n";
    cout << "\n";

}

void imprimirFinalRonda(int ronda, string nombreJugador, int puntajeTotal, int puntajeRonda){
    system("cls");
    cout << "------------------------------------\n";
    cout << "Ronda Numero " << ronda << "\n";
    cout << "Nombre de Jugador: " << nombreJugador<< "\n";
    cout << "Puntaje Total " << puntajeTotal << "\n";
    cout << "PuntajeRonda " << puntajeRonda << "\n";
    cout << "------------------------------------\n";
    system("pause");
    system("cls");
}

#endif // PLAYER_H_INCLUDED
