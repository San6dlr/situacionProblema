/*
Autor: Santiago De la Riva
Leer el archivo de texto en c++


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

#define CAL_MAYOR 7

using namespace std;

vector<string> separar(string linea);

int main()
{
    // WHILE CHECAR
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");
    string linea;
    int numeroLinea = 1;

    vector<Pelicula *> Peliculas;
    vector<Episodio *> Episodios;

    while (getline(entrada, linea))
    {
        if (numeroLinea == 1)
        {
            numeroLinea++;
            continue;
        }

        vector<string> datos = separar(linea);
        cout << (numeroLinea++);

        if (datos.size() == 6)
        {
            //cout << " Pelicula: ";
            Pelicula *peli = new Pelicula(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5]);
            Peliculas.push_back(peli); 
        }
        else
        {
            //cout << " Episodio: " << datos[0];
            Episodio *ep = new Episodio(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5], datos[6], datos[7], stoi(datos[8]), stoi(datos[9])); 
            Episodios.push_back(ep); 
        }
        cout << endl;
    }

    entrada.close();
    return 0;
}

vector<string> separar(string linea)
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

*/