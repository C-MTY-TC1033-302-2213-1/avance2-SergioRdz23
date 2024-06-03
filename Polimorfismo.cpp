// Nombre: Sergio Rodríguez Pérez
// Matrícula: A00838856
// Carerra: ITC
// Fecha: 23-Mayo-2024

#include "Polimorfismo.h"

using namespace std;

// Constructor default
Polimorfismo::Polimorfismo(){
    for (int index = 0;index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }

    // Se inicializa la cantidad de videos
    cantidad = 0;
}

// Métodos modificadores
void Polimorfismo::setPtrVideo(int index, Video *video){
    // Validar que index sea >=0 && < cantidad
    if (index >= 0 && index < cantidad){
        // Se modifica el apuntador
        arrPtrVideos[index] = video;
    }
}

// Modifica el valor de cantidad
// Cantidad debe estar entre 0 y MAX_VIDEOS -1 , de lo contrario NO se modifica el valor del atributo
void Polimorfismo::setCantidad(int _cantidad){
    // Validar valor de _cantidad
    if (_cantidad >= 0 && _cantidad <= MAX_VIDEOS){
        cantidad = _cantidad;
    }
}

// Métodos de acceso
Video* Polimorfismo::getPtrVideo(int index){
    // Validar que exista el index
    if (index >= 0 && index < cantidad){
        return arrPtrVideos[index];
    }
    
    // Si no existe un return regresa nullptr
    return nullptr;
}

int Polimorfismo::getCantidad(){
    // Retorna el atributo de cantidad
    return cantidad;
}

void Polimorfismo::leerArchivo(string nombre){
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7];
    string line, word;
    int cantidadPeliculas = 0;
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    // Se abre el archivo de entrada
    entrada.open(nombre,ios::in);

    // Lee una línea del archivo y la almacena en linea, utilizando split() para separar las palabras
    while (getline(entrada,line)){
        stringstream s(line);
        iR = 0;

        //Ciclo que extrae caracteres de s y los almacena en word hasta encontrar ','
        while (getline(s,word,',')){
            row[iR++] = word;
        }

        // Determina si la línea es P-Película, S-Serie o E-Episodio
        if (row[0] == "P"){
            // Se crea un apuntador utilizando new y el constructor con parámetros, se guarda en el arrPtrPeliculas
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            cantidadPeliculas++;
        }
        else if (row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            cantidadSeries++;
        }
        else if (row[0] == "E"){
            // Cálcula a que Serie pertenece el episodio
            index = stoi(row[1]) - 500;
            // Se agrega el episodio empleando el método agregaEpisodio
            // Se crea el apuntador y se convierte a objeto usando el operador de indirección
            arrPtrSeries[index]->agregaEpisodio(*(new Episodio(row[2],stoi(row[3]),stoi(row[4]))));
        }
    }

    // El archivo se termino de leer, ahora se guardan los apuntadores de Pelicula y Serie en el arrPtrVideo
    // Se copian todos los apuntadores del arreglo de Series al arreglo de apuntadores de Video calculando su calificacionPromedio

    for (int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index]->calculaPromedio(); // Se calcula la calificación de la serie
        arrPtrSeries[index]->setCalificacion(promedio); // Cambia la calificacion de la serie
        arrPtrSeries[index]->calculaDuracion(); // Calcula la duración de la serie
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

    // Se copian los apuntadores del arreglo de Peliculas al arreglo de Video
    for (int index = 0; index < cantidadPeliculas; index++){
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }
    
    /*Se despliega el contenido del arreglo de apuntadores de la clase Video
    Ejecutando el método str() que corresponde al tipo de apuntador almacenado, no el correspondiente al tipo de arreglo
    for (int index = 0; index < cantidad; index++){
        cout << index << " " << arrPtrVideos[index]->str() << endl;
    }*/

    // Se cierra el archivo
    entrada.close();
}

/* Despliega la información de todas las series y peliculas del arreglo usando el método str() 
correspondiente al tipo del apuntador, al final despliega:
Peliculas = ##
Series = ## */
void Polimorfismo::reporteInventario(){
    //Declaración de contadores
    int contadorPeliculas, contadorSeries;

    // Inicializar los contadores
    contadorPeliculas = 0;
    contadorSeries = 0;

    // Recorrer todos los arreglos de ptr usando un for
    for (int index = 0; index < cantidad; index++){
        cout << arrPtrVideos[index]->str() << endl;
        // Indirección (ptr) revisa que el objeto sea del mismo tipo
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            contadorPeliculas++;
        }
        else if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            contadorSeries++;
        }
    }
    // Fuera del for se despliega la cantidad de Peliculas y Series
    cout << "Peliculas = " << contadorPeliculas << endl;
    cout << "Series = " << contadorSeries << endl;
}

/*Despliega la información de todas las Series y Peliculas que tienen la calificación indicada en el parámetro de entrada,
al final despliega la cantidad con el siguiente mensaje.
Total = ## */
void Polimorfismo::reporteCalificacion(double _calificacion){
    // Se crea una variable para utilizarse como contador
    int contadorTotal;

    // Inicializar el contador
    contadorTotal = 0;

    for (int index = 0; index < cantidad; index++){
        // Verificar si la calificacion == _calificacion
        // Si es un apuntador se usa la notación ->
        if (arrPtrVideos[index]->getCalificacion() == _calificacion){
            cout << arrPtrVideos[index]->str() << endl;
            contadorTotal++;
        }
    }
    
    // Desplegar el total fuera del for
    cout << "Total = " << contadorTotal << endl; 

}

/*Despliega la información de todas las Series y Peliculas que tienen el genero indicado en el parámetro de entrada, 
al final despliega la cantidad que cumplio.
Total = ## */
void Polimorfismo::reporteGenero(string _genero){
    // Se crea una variable para utilizarse como contador
    int contadorTotal;

    // Inicializar el contador
    contadorTotal = 0;

    // Verificar si el genero == _genero
    for (int index = 0; index < cantidad; index++){
        if (arrPtrVideos[index]->getGenero() == _genero){
            cout << arrPtrVideos[index]->str() << endl;
            contadorTotal++;
        }
    }

    // Se despliega el contador total fuera del for
    cout << "Total = " << contadorTotal << endl;

}

/*Despliega la información de todas las Peliculas que existan en el arreglo, al final despliega la cantidad en existencia.
Total Peliculas = ##
en caso de que no existan peliculas debe desplegar No peliculas con salto de línea al final */
void Polimorfismo::reportePeliculas(){
    // Se crea una variable para utilizarse como contador
    int contadorTotal;

    // Inicializar el contador
    contadorTotal = 0;

    for (int index = 0; index < cantidad; index++){
        // Se verifica que se trate de una pelicula
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cout << arrPtrVideos[index]->str() << endl;
            contadorTotal++;
    }
    }
    // En caso que no existan peliculas se despliega No peliculas
    if (contadorTotal > 0){
        cout <<"Total Peliculas = " << contadorTotal << endl;
    }
    else{
        cout << "No peliculas\n" << endl;
    }
}

/* Despliega todos las Series que existan en el arreglo, al final despliega la cantidad en existencia.
Total Series = ##
en caso de que no existan Series debe desplegar No series con salto de línea al final */
void Polimorfismo::reporteSeries(){
    // Se crea una variable para utilizarse como contador
    int contadorTotal;

    // Inicializar el contador
    contadorTotal = 0;

    for (int index = 0; index < cantidad; index++){
        // Se verifica que se trate de una serie
        if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cout << arrPtrVideos[index]->str() << endl;
            contadorTotal++;
    }
    }

    // En caso que no existan series se despliega No series
    if (contadorTotal > 0){
        cout <<"Total Series = " << contadorTotal << endl;
    }
    else{
        cout << "No series\n" << endl;
    }
}