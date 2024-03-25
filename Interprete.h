#ifndef _INTERPRETE_H
#define _INTERPRETE_H

#include <iostream>

#include "Mapa.h"

using namespace std;


void dividir_parametros(string lineaParam, string param[4]);

void inicializar();

void insertarLugar(string nombre, string info);

void insertarLugarCorto(string nombre);

void insertarCarretera(string orig, string dest, string coste, string info);

void insertarCarreteraCorto();

void consultarLugar(string nombre);

void consultarCarretera(string orig, string dest);

void listarAdyacentes(string nombre);

void listarLugares();

void calcularRuta(string orig, string dest);

void interprete_comandos(string comando, string lineaParam); 

#endif