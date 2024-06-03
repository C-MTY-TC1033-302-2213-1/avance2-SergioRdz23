// Nombre: Sergio Rodríguez Pérez
// Matrícula: A00838856
// Carerra: ITC
// Fecha: 20-Mayo-2024

#include "Video.h"

//Métodos constructores
Video::Video(){
    iD = "0000";
    titulo = "Sergio Rodríguez Pérez";
    duracion = 1000;
    genero ="Masculino";
    calificacion = 100;
}

Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

//Métodos modificadores
void Video::setId(string _iD){
    iD = _iD;
}

void Video::setTitulo(string _titulo){
    titulo = _titulo;
}

void Video::setDuracion(int _duracion){
    duracion = _duracion;
}

void Video::setGenero(string _genero){
    genero = _genero;
}

void Video::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}

//Métodos de acceso
string Video::getId(){
    return iD;
}
    
string Video::getTitulo(){
    return titulo;
}

int Video::getDuracion(){
    return duracion;
}

string Video::getGenero(){
    return genero;
}
    
double Video::getCalificacion(){
    return calificacion;
}

//Otros métodos
string Video::str(){
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacion);
}
