#include "ArbolAVL.h"
#include "Lugar.h"
 
Arbol::Arbol()
{
    raiz = NULL;
}


int Arbol::altura (Nodo *A)
{
    if (A == NULL) {return -1;}
    else return A->alturaNodo;
}

//Rotacion Simple Izquierda
void Arbol::RSI(Nodo *&A)
{
    //cout << "RSI" << endl;
    Nodo *B = A->izquierdo; 
    A->izquierdo = B->derecho; 
    B->derecho = A;
    A->alturaNodo = 1 + max(altura(A->izquierdo), altura(A->derecho));
    B->alturaNodo = 1 + max(altura(B->izquierdo), A->alturaNodo);
    A = B; 
}

//Rotacion Simple Derecha
void Arbol::RSD(Nodo *&A)
{
    //cout << "RSD" << endl;
    Nodo *B = A->derecho; 
    A->derecho = B->izquierdo; 
    B->izquierdo = A; 
    A->alturaNodo = 1 + max(altura(A->izquierdo), altura(A->derecho));
    B->alturaNodo = 1 + max(altura(B->derecho), A->alturaNodo);
    A = B;
}

//Rotacion Doble Izquierda
void Arbol::RDI(Nodo *&A)
{
    //cout << "RDI" << endl;
    RSD(A->izquierdo);
    RSI(A);
}
//Rotacion Doble Derecha
void Arbol::RDD (Nodo *&A)
{
    //cout << "RDD" << endl;
    RSI(A->derecho); 
    RSD(A);
}

//Función recursiva usada en la función pública insertar
void Arbol::insertarNodo(Nodo *&A, Carretera c)
{
    //cout << "INSERTAR NODO" << endl;
    string destinoActual = A->carretera.getDestino()->getNombre();
    string destino = c.getDestino()->getNombre();
    
    //SUBARBOL IZQUIERDO
    if (destino < destinoActual) 
    {
        if (A->izquierdo == NULL) { A->izquierdo = new Nodo(c);}
        else {insertarNodo (A->izquierdo, c);}

        if ((altura(A->izquierdo) - altura(A->derecho)) > 1) 
        {
            //ROTACION SIMPLE IZQUIERDA
            if (destino < A->izquierdo->carretera.getDestino()->getNombre()) 
            { 
                RSI(A);
            }
            else 
            { 
                RDI(A);
            }
        }
        else {A->alturaNodo = 1 + max(altura(A->izquierdo), altura(A->derecho));}
    }

    //SUBARBOL DERECHO
    else if (destino > destinoActual)
    {
        if (A->derecho == NULL) {A->derecho = new Nodo(c);}
        else {insertarNodo (A->derecho, c);}

        if ((altura(A->derecho) - altura(A->izquierdo)) > 1)
        {
            //ROTACION SIMPLE DERECHA
            if (destino < A->derecho->carretera.getDestino()->getNombre()) 
            {
                RDD(A);
            }
            //ROTACION DOBLE DERECHA
            else 
            { 
                RSD(A);
            }
        }

        else {A->alturaNodo = 1 + max(altura(A->izquierdo), altura(A->derecho));}
    }
}

bool Arbol::insertar (Carretera c) 
{
    if (raiz == NULL) 
    {
        raiz = new Nodo(c);
        return true;
    }

    else 
    {
        //Si la carretera NO ha sido insertada
        Carretera *actual = consultar(c.getDestino()->getNombre()); 
        if (actual == NULL) 
        {
            //función recursiva
            insertarNodo(raiz, c);
            return true;
        }
        else 
        {
            //Si la carretera SI ha sido insertada, solo actualizo el coste y la información asociada
            actual->setCarretera(c.getDestino(), c.getCoste(), c.getInfo());
            return false;
        }
    }    
}


//buscar una carretera en el árbol, dado el lugar de destino de la carretera
Carretera *Arbol::consultar (string destino) 
{
    //cout << "CONSULTAR" << endl;
    Nodo * actual = raiz;

    //mientras que el nodo no sea null, se avanza en el arbol
    while (actual != NULL)
    {   
        string destinoActual = actual->carretera.getDestino()->getNombre(); 
        //Encontrado
        if (destino == destinoActual) {return &actual->carretera;}
        //avanzo por el Subarbol DERECHO
        else if (destino > destinoActual) 
        {
            actual = actual->derecho;
        }
        //avanzo por el subarbol IZQUIERDO
        else if (destino < destinoActual) 
        { 
            actual = actual->izquierdo;
        }
    }
    //si actual == NULL es que no hemos encontrado la carretera en el árbol 
    return nullptr; 
}

//Función recursiva para listarArbol nodo a nodo
void Arbol::listarNodos (Nodo *&A, bool &primero) 
{
    if (A != NULL) 
    {
        listarNodos (A->izquierdo, primero);
        
        if (primero)
        {
            cout << A->carretera.getDestino()->getNombre(); 
            primero = false; 
        } 
        else 
        {
            cout << ", " << A->carretera.getDestino()->getNombre();
        }
        listarNodos (A->derecho, primero);
    }
}

//listar todas las carreteras de un árbol por orden alfabético
void Arbol::listarArbol() 
{
    bool primero = true; 
    listarNodos (raiz, primero);
}


