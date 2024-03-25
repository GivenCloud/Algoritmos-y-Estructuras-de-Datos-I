#ifndef _NODO_H
#define _NODO_H

#include <iostream>
#include "Carretera.h"

using namespace std;


//las rotaciones cambian la raiz. POr tanto al rotar un nodo la nueva raiz es otro nodo.
//Pero el puntero this no se debe modificar. 

class Nodo {

friend class Arbol;

private:
    int alturaNodo; 
    Carretera carretera;
    Nodo *derecho;
    Nodo *izquierdo;
    
public:

    Nodo(Carretera c);
    ~Nodo() {delete derecho; delete izquierdo;};     
};

#endif