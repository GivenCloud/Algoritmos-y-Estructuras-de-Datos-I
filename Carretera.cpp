#include "Carretera.h"
#include "Lugar.h"

Carretera::Carretera() 
{
    destino = NULL; 
    coste = 0;
}

Lugar *Carretera::getDestino() 
{
    return destino;
}

int Carretera::getCoste()
{
    return coste;
}

string Carretera::getInfo()
{
    return informacion;
}

void Carretera::setCarretera(Lugar * destino, int coste, string informacion)
{
    this->destino = destino;
    this->coste = coste; 
    this->informacion = informacion;
}

void Carretera::escribirCarretera(string orig) 
{
    string dest = destino->getNombre();
    cout << "Encontrado: " << orig << "-" << dest << endl;
    cout << "Coste: " << coste << endl;
    cout << "Información: " << informacion << endl;
}


