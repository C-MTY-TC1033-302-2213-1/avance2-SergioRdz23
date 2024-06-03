// Nombre: Sergio Rodríguez Pérez
// Matrícula: A00838856
// Carerra: ITC
// Fecha: 20-Mayo-2024

#include "Serie.h"

// Métodos constructores
Serie::Serie():Video(){
    // Solo iniciaremos cantidad
    cantidad = 0;
}

Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion):Video(_iD,_titulo, _duracion, _genero,_calificacion){}

// Métodos modificadores
void Serie::setEpisodio(int posicion,Episodio episodio){
    // Validar que exista el episodio solicitado (posicion)
    if (posicion>= 0 && posicion < cantidad){
        episodios[posicion] = episodio;
    }
}

void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}

// Métodos de acceso
Episodio Serie::getEpisodio(int posicion){
    //Crea un objeto del tipo Episodio y lo inicializa con el constructor default
    Episodio epi;
    // Validar que exista el episodio socilitado (posición)
    if (posicion >= 0 && posicion < cantidad){
        return episodios[posicion];
    }
    // Se retorna un Episodio default si no existe
    return epi;
}

// Retorna el valor de cantidad
int Serie::getCantidad(){
    return cantidad;
}

// Otros métodos
double Serie::calculaPromedio(){
    double acum = 0;
    for (int index = 0; index < cantidad; index++){
        acum = acum + episodios[index].getCalificacion();
    }
    //Validar que tenga episodios
    if (cantidad > 0){
        return acum / cantidad;
    }
    else{
        return 0;
    }
}

// Overriding del método str() de la clase base
string Serie::str(){
    string resultado = iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacion) + ' ' + to_string(cantidad) + '\n';
    if (cantidad > 0){
        for (int index = 0; index < cantidad; index ++){
            resultado += episodios[index].Episodio::str() + '\n';
        }
    }
    // Retorna la información de cada episodio
    return resultado;
}

// Agrega un episodio solo si existe espacio
void Serie::agregaEpisodio(Episodio episodio){
    if (cantidad < 5){
        episodios[cantidad++] = episodio;
    }
}

// Calcula la duración de la serie
void Serie::calculaDuracion(){
    // Evita que duración tenga algún valor antes de llevar a cabo cualquier operación
    duracion = 0;
    if (cantidad > 0){
        for (int index = 0; index < cantidad; index ++){
            duracion = duracion + episodios[index].Episodio::getTemporada();
        }
    }
}