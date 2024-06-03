// Nombre: Sergio Rodríguez Pérez
// Matrícula: A00838856
// Carerra: ITC
// Fecha: 20-Mayo-2024
// En esta clase aprendí a cómo indicar que se trataba de una clase derivada, a usar la composición y 
// a trabajar con arreglos en los atributos de episodios

#ifndef Serie_h
#define Serie_h
// Herencia
#include "Video.h"
//Composición
#include "Episodio.h"
#include <string>

using namespace std;

class Serie : public Video{
    private:
    Episodio episodios[5];
    int cantidad;
    
    public:
    // Métodos constructores
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    // Métodos modificadores
    void setEpisodio(int posicion,Episodio episodio);
    void setCantidad(int _cantidad);

    // Métodos de acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();

    // Otros métodos
    double calculaPromedio();
    string str();
    void agregaEpisodio(Episodio episodio);
    void calculaDuracion();
};

#endif /* Serie_h */