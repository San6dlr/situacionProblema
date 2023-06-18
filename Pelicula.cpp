#include "Pelicula.h"

Pelicula::Pelicula(string ID, string nombre, int duracion, string generos, double calificacion, string fecha) : Video(ID, nombre, duracion, generos, calificacion, fecha)
{
}

void Pelicula::mostrarInfo()
{
    cout << "\n------------------------------------------------" << endl
         << "\t" + nombre + "  (" + to_string(duracion) + " min)" << endl
         << "------------------------------------------------" << endl
         << generos << endl
         << "Calificación: " + to_string(calificacion) + "\t\t" + fecha << endl
         << "\n------------------------------------------------\n"
         << endl
         << endl;
}
