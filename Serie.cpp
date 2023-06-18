/*
Autor: Santiago De La Riva Juárez
Se implementa el constructor y el operador sobrecargado
*/

#include "Serie.h"

// Constructor Serie
Serie::Serie(vector<Episodio> Episodios)
{
    this->Episodios = Episodios; 
}

// Método para calcular el promedio
double Serie::caliPromedio()
{
    double promedio = 0;
    double total = Episodios.size(); 

    // Se itera sobre cada episodio para guardar su calificación individual en 'promedio'
    for(Episodio cap: Episodios) 
    {
        promedio += cap.getCalificacion();
    }
    return promedio / total;
}

// Sobrecarga del operador << para el output especial de serie
ostream &operator<<(ostream &output, const Serie &s)
{
    Episodio ep = s.Episodios[1]; 

    output << "\n--------------------------------------------------------" << endl
           << "\t\t   " + ep.getNombreESerie() << endl
           << "--------------------------------------------------------" << endl;

    for(Episodio cap : s.Episodios)
    {
        output << "| S" + to_string(cap.getTemporada()) + " E" + to_string(cap.getEpisodio()) + " - " + cap.getNombre() + "  (" + to_string(cap.getDuracion()) + " min)"  << endl;
    }

    output << "--------------------------------------------------------" << endl;

    return output; 
}
