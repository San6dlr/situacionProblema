/*
Autor: Santiago De La Riva Juárez
Se declara la clase Episodio que hereda de Video 
*/

#ifndef EPISODIO_H 
#define EPISODIO_H

#include "Video.h"

class Episodio : public Video
{

private:
    // Atributos
    string IDE;
    string nombreE; 
    int temporada; 
    int episodio; 

public: 
    // Constructor Episodio
    Episodio(string ID, string nombre, int duracion, string generos, double calificacion, string fecha, string IDE, string nombreE, int temporada, int episodio);

    // Getters
    string getNombre();
    string getNombreESerie(); // Se crea un nuevo getter para el nombre de la serie del episodio
    int getTemporada(); 
    int getEpisodio(); 

    // Se redefine para mostrar el episodio
    void mostrarInfo(); 
}; 
#endif