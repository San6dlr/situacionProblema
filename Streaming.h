#ifndef STREAMING_H
#define STREAMING_H

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define CAL_MAYOR 7
using namespace std;

class Streaming
{
private:
    vector<Pelicula*> Peliculas;
    vector<Episodio*> Episodios;
public:
    vector<string> separar(string linea);
    void cargarCatalogo(string base);

    vector<Pelicula*> getPeliculas();
    vector<Episodio*> getEpisodios(); 
};
#endif
