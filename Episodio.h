// Nombre: Sergio Rodríguez Pérez
// Matrícula: A00838856
// Carerra: ITC
// Fecha: 20-Mayo-2024
// Haciendo esta clase aprendí sobre la creación de métodos constructores, modificadores y de acceso

#ifndef Episodio_h
#define Episodio_h
#include <stdio.h>
#include <string>

using namespace std;

class Episodio{
    private:
    string titulo;
    int temporada;
    int calificacion;

    public:
    //Métodos constructores
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);

    //Métodos modificadores
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);

    //Métodos de acceso
    string getTitulo();
    int getTemporada();
    int getCalificacion();

    //Otros métodos
    string str();
};

#endif /* Episodio_h */