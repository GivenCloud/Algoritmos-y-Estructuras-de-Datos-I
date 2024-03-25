#ifndef _ARBOLAVL_H
#define _ARBOLAVL_H

#include <iostream>

#include "Nodo.h"

using namespace std;

//el nodo se pasa como parametro. Ademas debe ser un parametro por referencia (&) puesto que se actualiza la nueva raiz. 

class Arbol
{
    private:

        Nodo *raiz;
        void insertarNodo (Nodo *&A, Carretera c);
        void listarNodos (Nodo *&A, bool &primero);
        
    public:
        //Constructor y destructor
        Arbol();
        ~Arbol() {delete raiz;};
        
        int altura (Nodo *A);

        //insertar carretera en el árbol
        bool insertar (Carretera c);
        
        //Rotaciones
        void RSI (Nodo *&A);
        void RDI (Nodo *&A);
        void RSD (Nodo *&A);
        void RDD (Nodo *&A);

        //consultar destino
        Carretera *consultar (string destino);
        //listar todos los elementos del arbol (NODOS)
        void listarArbol();
};

#endif