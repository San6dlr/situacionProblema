
#ifndef EPISODIO_H 
#define EPISODIO_H

#include "Video.h"

class Episodio : public Video
{

private: 
    string IDE;
    string nombreE; 
    int temporada; 
    int episodio; 

public: 
    // Constructor Episodio
    //ID,Nombre Pelicula/Serie,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio

    Episodio(string ID, string nombre, int duracion, string generos, int calificacion, string fecha, string IDE, string nombreE, int temporada, int episodio);

    // Getters
    int getTemporada(); 
    int getEpisodio(); 

    void mostrarInfo(); 

}; 
#endif