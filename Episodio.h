
#ifndef EPISODIO_H 
#define EPISODIO_H

#include "Video.h"

class Episodio : public Video
{

private: 
    int temporada; 
    int episodio; 

public: 
    // Constructor Episodio
    Episodio(string ID, string nombre, string generos, int calificacion, double minutos, string fecha, int temporada, int episodio);

    // Getters
    int getTemporada(); 
    int getEpisodio(); 

}; 
#endif