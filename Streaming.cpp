#include "Streaming.h"

vector<string> Streaming::separar(string linea)
{

    vector<string> tokens; // Componentes de la línea

    stringstream entrada(linea); // flujo de datos a partir de una cadena

    string dato; // token individual

    int numeroTokens = 0;

    while (getline(entrada, dato, ',')) // dependiendo de cuantos tokens click derecho formatear documento
    {

        if (dato != "" && dato != "\n" && dato != "\r")
        {
            // cout << dato << endl;
            tokens.push_back(dato); // GUARDA en el vector
            // numeroTokens++;
        }
    }
    // cout << "tokens: " << numeroTokens << endl << endl;
    return tokens;
}

bool Streaming::cargarCatalogo(string archivo)
{

    ifstream entrada;
    entrada.open(archivo + ".csv");

    if (entrada.fail())
    {
        return false; 
    }

    string linea;
    int numeroLinea = 1;

    while (getline(entrada, linea))
    {
        if (numeroLinea == 1)
        {
            numeroLinea++;
            continue;
        }

        vector<string> datos = separar(linea);
        // cout << (numeroLinea++);

        if (datos.size() == 6)
        {
            // cout << " Pelicula: ";
            Pelicula *peli = new Pelicula(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5]);
            Peliculas.push_back(peli);
            Videos.push_back(peli); 
        }
        else
        {
            // cout << " Episodio: " << datos[0];
            Episodio *ep = new Episodio(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5], datos[6], datos[7], stoi(datos[8]), stoi(datos[9]));
            Episodios.push_back(ep);
            Videos.push_back(ep); 
        }
        // cout << endl;
    }

    entrada.close();
    return true;
}

vector<Video *> Streaming::getVideos() {return Videos;}

vector<Pelicula *> Streaming::getPeliculas() { return Peliculas; }

vector<Episodio *> Streaming::getEpisodios() { return Episodios; }

