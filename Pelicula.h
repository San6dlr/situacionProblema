
#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video
{

public: 
    Pelicula(string ID, string nombre, int duracion, string generos, double calificacion, string fecha);
    void mostrarInfo(); 
};
#endif 