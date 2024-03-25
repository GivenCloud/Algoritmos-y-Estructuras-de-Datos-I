#ifndef _TABLAHASH_H
#define _TABLAHASH_H

#include <iostream>
#include <sstream>
#include <list>

#include "Lugar.h"

using namespace std;

const int TAM = 800; //TAMAÑO DE LA TABLA HASH 

class TablaHash {
    private: 
        list <Lugar> tablaLugares[TAM];  // --> dispersión abierta 
        int nElem;
        unsigned dispersionHash(string nombre); 

    public: 
        TablaHash(); 
        void inserta(Lugar L); 
        Lugar * consulta (string nombre); 
        void vacia (void);
        int nTotal (void) {return nElem;}; 
};

#endif