/*
Autor: Santiago De La Riva Juárez
Se implementa el constructor y los métodos para el manejo de videos
*/

#include "Video.h"
#include <sstream>

// Constructor Video
Video::Video(string ID, string nombre, int duracion, string generos, double calificacion, string fecha)
{
    this->ID = ID;
    this->nombre = nombre;
    this->generos = generos;
    this->calificacion = calificacion;
    this->duracion = duracion;
    this->fecha = fecha;
}

// Getters
string Video::getNombre() {return nombre;}

double Video::getCalificacion() {return calificacion;}

int Video::getDuracion() {return duracion;}

// Se obtiene un vector de strings y cada posición representa un único género
vector<string> Video::getGeneros()
{
    vector<string> generos_separados;
    stringstream entrada(generos);
    string dato;

    // Se separa la string cuando llega a un '&'
    while (getline(entrada, dato, '&'))
    {
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            generos_separados.push_back(dato); 
        }
    }
    return generos_separados; 
}

// Setter para la calificación 
void Video::setCalificacion(double calificacion)
{
    this->calificacion = calificacion;
}
