#include <list>
#include "TablaHash.h"


TablaHash::TablaHash() 
{
    nElem = 0; 
}

unsigned TablaHash::dispersionHash (string nombre) 
{
    int sumaAcumul = 0;

    //obtener caracter a caracter los códigos ascii del nombre
    //para pasar un caracter a su valor ascii hacer char letra = 'c'; int(letra); 
    for (int i = 0; i < nombre.length(); i++) {
        int valor = (int) nombre[i];
        sumaAcumul = sumaAcumul*31 + valor;
    }
    //pero con suma acumulativa -> acum = acum*31 + cad[i] (siendo cad[i] el valor ascii);
    //finalmente hacemos modulo tamaño de la tabla
    //abs (acum) % TAM

    int resultado = abs(sumaAcumul) % TAM; 
    return resultado; 
}

void TablaHash::inserta(Lugar l)
{
    //obtenemos el nombre del lugar para poder sacar la clave
    string nombre = l.getNombre();
    int clave = dispersionHash (nombre);
   list<Lugar>::iterator it = tablaLugares[clave].begin();

    while (it != tablaLugares[clave].end() && it->getNombre() < nombre) {it++;}

    //si se ha llegado al final de la lista sin encontrarlo, se inserta y +1 contador 
    if (it == tablaLugares[clave].end() || it->getNombre() != nombre) 
    { 
        tablaLugares[clave].insert(it, l);
        nElem++;  
    }
    //si llegamos a un lugar de nombre idéntico actualizamos el lugar pero NO lo contamos como nuevo lugar
    else {it->setLugar(l.getNombre(), l.getInfo());}
    
} 

Lugar * TablaHash::consulta (string nombre)
{
    int clave = dispersionHash (nombre);
    
    list<Lugar>::iterator it = tablaLugares[clave].begin();


    while (it != tablaLugares[clave].end() && it->getNombre() != nombre) {it++;}

    //si llegamos al final de lista sin encontrarlo devuelvo nullptr
    if (it == tablaLugares[clave].end() || it->getNombre() != nombre) {return nullptr;}

    else {return &*it;}

}

void TablaHash::vacia (void)
{
    for (int i = 0; i < TAM; i++) {
        tablaLugares[i].clear(); 
    }

    nElem = 0; 
}
