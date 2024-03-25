#ifndef _CARRETERA_H
#define _CARRETERA_H

#include <iostream>

using namespace std;

class Lugar;

//Unen 2 lugares que deben haber sido insertados previamente en el mapa. 
//TIenen un coste y una info asociadas. !!TIenen direccion A -> B != B ->A

class Carretera {

    private:

        Lugar *destino;
        int coste;
        string informacion;

    public:
        Carretera(); 
        //método para obtener el destino de una carretera
        Lugar *getDestino();
        //método para obtener el coste de una carretera
        int getCoste(); 
        //método para obtener la informacion de una carretera
        string getInfo();
        //metodo para inicializar una carretera
        void setCarretera (Lugar *destino, int coste, string informacion);
        //metodo para imprimir una carretera por pantalla
        void escribirCarretera (string orig);
};

#endif
