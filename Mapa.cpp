#include "Mapa.h"

Mapa::Mapa() 
{
    th = TablaHash();
    contador = 0;  
}

void Mapa::vaciar() 
{
    th.vacia();
    contador = 0;
}

void Mapa::insertar(Lugar l) 
{
    th.inserta(l); 
};

Lugar * Mapa::consultar (string nombre)
{
    return th.consulta(nombre); 
}

int Mapa::nLugares(void) {return th.nTotal();}
int Mapa::nCarreteras(void) {return contador;}

//FUNCIONES RELATIVAS A CARRETERA

void Mapa::insertarCarretera (string origen, string destino, int coste, string informacion)
{
    //------CON ARBOLES----------//

    //Buscar origen y destino en la tabla de dispersion y si no existe no se hace nada, 
    //en otro caso, llamar a insertarCarretera sobre el origen
    //Tampoco se inserta si el lugar de Origen es el mismo que el lugar de Destino

    Lugar *lugarOrigen = th.consulta(origen);
    Lugar *lugarDestino = th.consulta(destino);
    Carretera c;
    bool carreteraInsertada; 

    if (lugarOrigen != nullptr && lugarDestino != nullptr && origen!= destino) 
    {
        c.setCarretera(lugarDestino, coste, informacion);  
        carreteraInsertada = lugarOrigen->insertarCarretera(c);
        if (carreteraInsertada) {contador++;}
        if (informacion != "") 
        {
            cout << "Añadido: " << origen << "-" << destino << "." << " Total: " << nCarreteras() << " carreteras" << endl;
        }
        
    }    
}

Carretera * Mapa::consultarCarretera (string origen, string destino)
{
    //------CON ARBOLES----------//

    //Buscar el origen en la tabla de dispersión y si existe, consultar dentro de su árbol si existe el destino.

    Lugar *lugarOrigen;
    Carretera *c;
    if (th.consulta(origen) != nullptr)
    {
        lugarOrigen = th.consulta (origen);
        c = lugarOrigen->consultarCarretera (destino);
        
        if (c != nullptr) { return &*c;}
        else return nullptr;
    }
    else return nullptr; 
}


void Mapa::listarAdyacentes(string origen)
{
    //------CON ARBOLES----------//    

    //Dado un lugar listar las carreteras que tenga asociadas en el árbol, SI TIENE ALGUNA
    
    Lugar *lugarOrigen  = th.consulta(origen); 

    if (th.consulta (origen) != nullptr) 
    { 
         
        {
            cout << "Encontrado: " << origen << endl;
            cout << "Adyacentes: ";
            lugarOrigen->listarAdyacentes();
            cout << endl;
            
        }
    }

    else {cout << "No encontrado: " << origen << endl;}    
}

 