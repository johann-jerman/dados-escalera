#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

const int cantidadDados = 6;
const int puntajeParaGanar = 100;

bool sonIguales(int dados[], int tam){
    //iniciamos con el valor del primer dado
    int valor = dados[0];
    for(int i = 0; i < tam; i++){
        //si hay un valor distinto al primero no son todo iguales
        if(valor != dados[i]) return false;
    }

    return true;
}
bool esEscalera(int dados[], int tam){
    bool hay1 = false, hay2 = false, hay3 = false, hay4 = false, hay5 = false, hay6 = false;

    for(int i = 0; i < tam; i++){
        if(dados[i] == 1) hay1 = true;

        if(dados[i] == 2) hay2 = true;

        if(dados[i] == 3) hay3 = true;

        if(dados[i] == 4) hay4 = true;

        if(dados[i] == 5) hay5 = true;

        if(dados[i] == 6) hay6 = true;
    }
    return hay1 && hay2 && hay3 && hay4 && hay5 && hay6;
}
void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}
int sumaVector(int dados[], int tam){
    int sumaPuntaje = 0;

    for(int i = 0; i < tam; i++){
        sumaPuntaje += dados[i];
    }

    return sumaPuntaje;
}
#endif // UTILS_H_INCLUDED
