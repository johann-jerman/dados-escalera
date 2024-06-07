#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

bool EstanJugando = false;

const int cantidadDados = 6;

bool sonIguales(int dados[], int tam){
    int valor = dados[0];
    for(int i = 0; i < tam; i++){
        if(valor != dados[i]) return false;
    }

    return true;
}

#endif // UTILS_H_INCLUDED
