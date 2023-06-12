#include "Video.h"

Video::Video(string ID, string nombre, string generos, int calificacion, double minutos, string fecha)
{
    this->ID = ID;
    this->nombre = nombre;
    this->generos = generos; 
    this->calificacion = calificacion;
    this->minutos = minutos; 
    this->fecha = fecha;  
}