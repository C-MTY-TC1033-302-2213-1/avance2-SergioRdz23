// Nombre: Sergio Rodríguez Pérez
// Matrícula: A00838856
// Carerra: ITC
// Fecha: 20-Mayo-2024
// En esta clase aprendí sobre el uso de los atributos de tipo protected

#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>

using namespace std;

class Video{
    protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;
    
    public:
    //Métodos Constructores
    Video();
    Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    //Métodos modificadores
    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    //Métodos de acceso
    string getId();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    //Otros métodos
    virtual string str();
};

#endif /* Video_h */