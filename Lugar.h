#ifndef _LUGAR_H
#define _LUGAR_H

#include <iostream>
#include "Carretera.h"
#include "ArbolAVL.h"

using namespace std;

//Cada lugar tendrá almacenado el conjunto de carreteras que salen de él.
//POR AHORA UNA ÚNICA CARRETERA.
class Lugar {
    
    private: 

        string nombre; 
        string info;
        //Arbol que contiene todas las carreteras adyacentes.
        Arbol adyacentes; 
    
    public:
        //método para obtener el nombre del lugar
        string getNombre();
        
        //método para obtener la información asociada al lugar
        string getInfo();

        //método para obtener el arbol de carreteras adyacentes
        Arbol *getAdyacentes(); 

        //método para inicializar un lugar con los valores pasados por parámetro
        void setLugar (string nom, string inf);
        
        //método para imprimir un lugar por pantalla 
        void escribirLugar();

        //método para insertar una carretera en su Arbol de carreteras
        bool insertarCarretera (Carretera c) {return adyacentes.insertar(c);}

        //método para consultar si existe carretera a un destino dado
        Carretera *consultarCarretera (string destino) {return adyacentes.consultar(destino);}

        //Listar todas las carreteras que existen
        void listarAdyacentes() {adyacentes.listarArbol();}
}; 

#endif