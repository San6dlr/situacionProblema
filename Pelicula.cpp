#include "Pelicula.h"

Pelicula::Pelicula(string ID, string nombre, int duracion, string generos, double calificacion, string fecha) : Video(ID, nombre, duracion, generos, calificacion, fecha)
{
}

void Pelicula::mostrarInfo()
{
    cout << "\n ------" + nombre + "--------" << endl; 

}
