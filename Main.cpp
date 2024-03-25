#include <iostream>
using namespace std;

#include "Interprete.h"

int main(void) {
	
	string comando, lineaParam;
	char letra;
	
    //leer comandos y parámetros 
	while(cin >> comando) 
    {
        letra = cin.get();

        //lista de parámetros vacía  
        if (letra == '\n') 
        {
            lineaParam = ""; 
        }

        //leo la lista de parámetros del comando leído previamente 
        else 
        {
            getline (cin, lineaParam); 
        }

        //llamo al interprete de comandos con el comando leido y su linea de parámetros
        interprete_comandos(comando, lineaParam); 
    }
}