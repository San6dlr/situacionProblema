#include "Video.h"

Video::Video(string ID, string nombre, string generos, double calificacion, double minutos, string fecha)
{
    this->ID = ID;
    this->nombre = nombre;
    this->generos = generos; 
    this->calificacion = calificacion;
    this->minutos = minutos; 
    this->fecha = fecha;  
}


string Video::getNombre() {return nombre;}
string Video::getGeneros() {return generos;}
int Video::getCalificacion() {return calificacion;}

void Video::setCalificacion(int calificacion)
{
    this->calificacion = calificacion; 
}
