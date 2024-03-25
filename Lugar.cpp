#include "Lugar.h"

//método para obtener el nombre del lugar
string Lugar::getNombre() { return nombre;}

string Lugar::getInfo() {return info;}

//método para obtener el árbol de adyacentes
Arbol *Lugar::getAdyacentes() {return &adyacentes;}

//método para inicializar un lugar con los valores pasados por parámetro
void Lugar::setLugar (string nom, string inf) {nombre = nom; info = inf;}

//método para imprimir un lugar por pantalla 
void Lugar::escribirLugar() 
{
    cout << "Encontrado: " << nombre << endl; 
    cout << "Información: " << info << endl; 
}



