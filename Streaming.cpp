/*
Autor: Santiago De La Riva Juárez
Se implementa el constructor y los métodos para el manejo del archivo y los getters
*/

#include "Streaming.h"

// Método para separar cada línea del archivo
vector<string> Streaming::separar(string linea)
{

    vector<string> tokens; // Componentes de la línea

    stringstream entrada(linea); // flujo de datos a partir de una cadena

    string dato; // token individual

    while (getline(entrada, dato, ','))
    {

        if (dato != "" && dato != "\n" && dato != "\r")
        {
            tokens.push_back(dato);
        }
    }
    return tokens;
}

// Genera los vectores de apuntadores de Videos, Peliculas y Episodios
bool Streaming::cargarCatalogo(string archivo)
{

    ifstream entrada;
    entrada.open(archivo + ".csv");

    // Se comprueba si el archivo se leyó con éxito
    if (entrada.fail())
    {
        // Regresa un bool para confirmarlo con main
        return false;
    }

    string linea;
    int numeroLinea = 1;

    while (getline(entrada, linea))
    {
        // Se saltá la primera línea de información
        if (numeroLinea == 1)
        {
            numeroLinea++;
            continue;
        }

        vector<string> datos = separar(linea);

        if (datos.size() == 6)
        {
            // Se crea una dirección de un objeto de tipo Pelicula
            Pelicula *peli = new Pelicula(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5]);
            Peliculas.push_back(peli);

            // Esta direccion también se agrega al vector Videos
            Videos.push_back(peli);
        }
        else
        {
            // Se crea una dirección de un objeto de tipo Episodio
            Episodio *ep = new Episodio(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5], datos[6], datos[7], stoi(datos[8]), stoi(datos[9]));
            Episodios.push_back(ep);

            // Esta direccion también se agrega al vector Videos
            Videos.push_back(ep);
        }
    }

    // Cerramos el archivo y regresamos true para confirmar que el catálogo se cargo con éxito
    entrada.close();
    return true;
}

// Getters de los vectores de apuntadores de Videos
vector<Video *> Streaming::getVideos() { return Videos; }

vector<Pelicula *> Streaming::getPeliculas() { return Peliculas; }

vector<Episodio *> Streaming::getEpisodios() { return Episodios; }
