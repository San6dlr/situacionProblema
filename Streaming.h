/*
Autor: Santiago De La Riva Juárez
Se declara la clase Streaming para el manejo del archivo, y los Videos
*/

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

using namespace std;

class Streaming
{
private:
    // Atributos (vectores de apuntadores de los Videos en general)
    vector<Video*> Videos; 
    vector<Pelicula*> Peliculas;
    vector<Episodio*> Episodios;

public:
    // Métodos para el manejo del archivo
    vector<string> separar(string linea);
    bool cargarCatalogo(string base);

    // Getters de los atributos
    vector<Video*> getVideos(); 
    vector<Pelicula*> getPeliculas();
    vector<Episodio*> getEpisodios(); 
};
#endif

