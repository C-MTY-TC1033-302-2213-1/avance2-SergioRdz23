// Nombre: Sergio Rodríguez Pérez
// Matrícula: A00838856
// Carerra: ITC
// Fecha: 23-Mayo-2024
// En esta clase aprendí acerca de la implementación del polimorfismo al utilizar apuntadores 
// mediante la creación de una clase base con métodos virtuales y derivando varias clases de ella

#ifndef Polimorfismo_h
#define Polimorfismo_h

#include "Video.h"
#include "Serie.h"
#include "Episodio.h"
#include "Pelicula.h"
#include <stdio.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int MAX_VIDEOS = 100;

class Polimorfismo{
    // Atributos
    private:
    Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;

    public:
    // Método constructor
    Polimorfismo();

    // Métodos modificadores
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    // Métodos de acceso
    Video* getPtrVideo(int index);
    int getCantidad();

    // Otros métodos
    void leerArchivo(string _nombre);
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();
};

#endif /* Polimorfismo_h */