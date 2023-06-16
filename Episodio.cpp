#include "Episodio.h"

Episodio::Episodio(string ID, string nombre, int duracion, string generos, int calificacion, string fecha, string IDE, string nombreE, int temporada, int episodio) : Video(ID, nombre, duracion, generos, calificacion, fecha) 
{
    this->IDE = IDE; 
    this->nombreE = nombreE;
    this->temporada = temporada; 
    this->episodio = episodio; 
}

int Episodio::getTemporada() {return temporada;}

int Episodio::getEpisodio() {return episodio;}

void Episodio::mostrarInfo()
{
     cout << "\n ------" + nombre + "--------" << endl; 
}
