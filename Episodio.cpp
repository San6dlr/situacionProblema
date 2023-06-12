#include "Episodio.h"

Episodio::Episodio(string ID, string nombre, string generos, int calificacion, double minutos, string fecha, int temporada, int episodio) : Video(ID, nombre, generos, calificacion, minutos, fecha) 
{
    this->temporada = temporada; 
    this->episodio = episodio; 
}

int Episodio::getTemporada() {return temporada;}

int Episodio::getEpisodio() {return episodio;}
