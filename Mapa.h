#ifndef _MAPA_H
#define _MAPA_H

#include <iostream>
#include <list>

#include "TablaHash.h"

using namespace std;

class Mapa {
    private:

        TablaHash th;  
        int contador;

    public: 
        Mapa();
        void vaciar(); 
        void insertar(Lugar l); 
        Lugar * consultar (string nombre); 
        int nLugares(void);
        int nCarreteras(void);
        //void imprimirLista (void);
        
        //FUNCIONES REALTIVAS A CARRETERA
        void insertarCarretera (string origen, string destino, int coste, string informacion);
        Carretera *consultarCarretera (string origen, string destino);
        void listarAdyacentes (string origen);
};

#endif