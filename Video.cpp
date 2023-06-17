#include "Video.h"
#include <sstream>

Video::Video(string ID, string nombre, int duracion, string generos, double calificacion, string fecha)
{
    this->ID = ID;
    this->nombre = nombre;
    this->generos = generos;
    this->calificacion = calificacion;
    this->duracion = duracion;
    this->fecha = fecha;
}

string Video::getNombre() {return nombre;}

int Video::getCalificacion() {return calificacion;}

vector<string> Video::getGeneros()
{
    vector<string> generos_separados;
    stringstream entrada(generos);
    string dato;

    while (getline(entrada, dato, '&'))
    {
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            generos_separados.push_back(dato); 
        }
    }
    return;
}

void Video::setCalificacion(int calificacion)
{
    this->calificacion = calificacion;
}
