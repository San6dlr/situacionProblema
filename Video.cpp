#include "Video.h"

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
string Video::getGeneros() {return generos;}
int Video::getCalificacion() {return calificacion;}

void Video::setCalificacion(int calificacion)
{
    this->calificacion = calificacion; 
}
