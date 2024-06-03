// Nombre: Sergio Rodríguez Pérez
// Matrícula: A00838856
// Carerra: ITC
// Fecha: 20-Mayo-2024

#include "Episodio.h"

//Métodos constructores
Episodio::Episodio(){
    titulo = "El ascenso de las tortugas ninja";
    temporada = 1;
    calificacion = 78;
}

Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

//Métodos modificadores
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}

void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}

void Episodio::setCalificacion(int _calificacion){
    calificacion = _calificacion;
}

//Métodos de acceso
string Episodio::getTitulo(){
    return titulo;
}

int Episodio::getTemporada(){
    return temporada;
}
    
int Episodio::getCalificacion(){
    return calificacion;
}

//Otros métodos
string Episodio::str(){
    return titulo + ' ' + to_string(temporada) + ' ' + to_string(calificacion);
}
