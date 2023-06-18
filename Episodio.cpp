/*
Autor: Santiago De La Riva Juárez
Se implementa el constructor y los métodos para el manejo de episodios
*/

#include "Episodio.h"

// Constructor 
Episodio::Episodio(string ID, string nombre, int duracion, string generos, double calificacion, string fecha, string IDE, string nombreE, int temporada, int episodio) : Video(ID, nombre, duracion, generos, calificacion, fecha)
{
    this->IDE = IDE;
    this->nombreE = nombreE;
    this->temporada = temporada;
    this->episodio = episodio;
}

// Se sobreescribe el método getNombre() para regresar el nombre del capitulo
string Episodio::getNombre() { return nombreE; }

// Método para obtener el nombre de la serie del episodio
string Episodio::getNombreESerie() { return nombre; }

// Getters
int Episodio::getTemporada() { return temporada; }

int Episodio::getEpisodio() { return episodio; }

// Se sobreescribe el método para adaptarse a los episodios
void Episodio::mostrarInfo()
{
    cout << "\n------------------------------------------------" << endl
         << "\t    " + nombre << endl
         << "------------------------------------------------" << endl
         << to_string(episodio) + "." + nombreE + "  (" + to_string(duracion) + " min)" << endl
         << generos << endl
         << "Calificación: " + to_string(calificacion) + "\t\t" + fecha << endl
         << "\n------------------------------------------------\n"
         << endl
         << endl;
}
