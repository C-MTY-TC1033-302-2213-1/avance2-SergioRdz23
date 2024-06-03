// Nombre: Sergio Rodríguez Pérez
// Matrícula: A00838856
// Carerra: ITC
// Fecha: 20-Mayo-2024
// Haciendo esta clase aprendí como funcionan las clases derivadas de otra clase

#ifndef Pelicula_h
#define Pelicula_h

#include <string>
#include <iostream>
#include "Video.h"
using namespace std;

//Clase Pelicula derivada de Video
class Pelicula : public Video{
    private:
    int oscares;

    public:
    // Métodos constructores
    Pelicula();
    Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    // Métodos modificadores
    void setOscares(int _oscares);

    // Métodos de acceso
    int getOscares();

    // Otros métodos
    string str();
};

#endif /* Pelicula_h */