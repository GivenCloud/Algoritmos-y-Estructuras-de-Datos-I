
#include "Interprete.h"

//variable global 
Mapa mapaLugares;

//pasamos como argumentos la linea de parámetros y un array para guardar los parámetros separados
void dividir_parametros(string lineaParam, string param[4]) 
{
	string parametro;
    int numParam = 0;  
	int length = lineaParam.length();
	
	for (int i = 0; i < length; i++) 
    {
		if(lineaParam[i] == ',') 
        {
            //para cada posición del array guardamos el parámetro correspondiente 
            param[numParam] = parametro;  
			numParam ++;
			parametro = "";
		}
		
		else 
        {
			parametro = parametro + lineaParam[i];
		}
	
	}
    //último parámetro 
	param[numParam] = parametro; 	

}


//PROCEDIMIENTOS AUXILIARES PARA EL INTERPRETE

void inicializar() 
{
    mapaLugares.vaciar();
    
    cout << "Mapa inicializado" << endl; 
}

void insertarLugar(string nombre, string info) 
{
    Lugar l;
    l.setLugar(nombre,info);
    mapaLugares.insertar(l);
     
    cout << "Añadido: " << nombre << ". Total: " << mapaLugares.nLugares() << " lugares" << endl;
}

void insertarLugarCorto(string nombre) 
{
    Lugar l;
    l.setLugar(nombre,"");  
    mapaLugares.insertar(l); 
}


void insertarCarretera (string orig, string dest, string coste, string info) 
{
    mapaLugares.insertarCarretera(orig, dest, atoi(coste.c_str()), info); 
}


void insertarCarreteraCorto (string orig, string dest, string coste) 
{
    mapaLugares.insertarCarretera (orig, dest, atoi(coste.c_str()), ""); 
}

    
void consultarLugar (string nombre) 
{
    Lugar * l; 
    l = mapaLugares.consultar (nombre); 
    
    if ( l != nullptr) { l->escribirLugar();}
    
    else {cout << "No encontrado: " << nombre << endl;}
     
}

void consultarCarretera (string origen, string destino)
{
    Carretera *carretera = mapaLugares.consultarCarretera (origen, destino);
    
    if (carretera != nullptr) {carretera->escribirCarretera(origen);}
    
    else {cout << "No encontrado: " << origen << "-" << destino << endl;}
     
}

void listarLugares () 
{
    cout << "Total: 0 lugares" << endl; 
}

void listarAdyacentes (string nombre)
{
    mapaLugares.listarAdyacentes (nombre);
}

void calcularRuta (string orig, string dest) 
{
    cout << "No existe ningún camino entre " << orig << " y " << dest << endl; 
}


//INTERPRETE DE COMANDOS 
void interprete_comandos(string comando, string lineaParam)  
{
    string param[4]; //los max parametros que podemos tener por comando son 4
    
    //1º separo los parámetros del comando en cuestión para poder utilizarlos posteriormente en los procedimientos. 
    dividir_parametros(lineaParam, param);

    if (comando == "Inicializar") 
    {
        inicializar(); 
    }

    else if (comando == "AñadirLugar") 
    {
        insertarLugar(param[0], param[1]); 
    }

    else if (comando == "AñadirCarretera") 
    {
        insertarCarretera(param[0], param[1], param[2], param[3]); 
    }

    else if (comando == "AL") 
    {
        insertarLugarCorto(param[0]); 
    }

    else if (comando == "AC") 
    {
        insertarCarreteraCorto(param[0], param[1], param[2]); 
    }

    else if (comando == "ConsultarLugar") 
    {
        consultarLugar(param[0]); 
    }

    else if (comando == "ConsultarCarretera") 
    {
        consultarCarretera(param[0], param [1]); 
    }

    else if (comando == "ListarAdyacentes") 
    {
        listarAdyacentes(param[0]); 
    }

    else if (comando == "ListarLugares") 
    {
        listarLugares(); 
    }

    else if (comando == "CalcularRuta") 
    {
        calcularRuta(param[0], param[1]); 
    }
}
