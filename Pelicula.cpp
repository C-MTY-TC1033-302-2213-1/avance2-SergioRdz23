// Nombre: Sergio Rodríguez Pérez
// Matrícula: A00838856
// Carerra: ITC
// Fecha: 20-Mayo-2024

#include "Pelicula.h"

// Métodos constructores
Pelicula::Pelicula():Video(){
    oscares = 100;
}

Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares):Video(_iD,_titulo,_duracion,_genero,_calificacion){
    oscares = _oscares;
}

// Métodos modificadores
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
}

// Métodos de acceso
int Pelicula::getOscares(){
    return oscares;
}

// Otros métodos
string Pelicula::str(){
    // Tenemos acceso directo a los atributos de la clase Padre porque son Protected
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacion) + ' ' + to_string(oscares);
}
