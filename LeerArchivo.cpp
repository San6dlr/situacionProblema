/*
Autor: Roberto
Leer el archivo de texto en c++
*/

#include <iostream>
#include <fstream> // input file-stream

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

#include <sstream> // Para string-stream
#include <vector>
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

    vector<Pelicula*> Peliculas; 

    while (getline(entrada, linea))
    {
        if(numeroLinea == 1)
        {
            numeroLinea++; 
            continue; 
        }

        // cout << (numeroLinea++) << ": " << linea << endl;

        vector<string> datos = separar(linea);
        cout << (numeroLinea++);

        if (datos.size() == 6)
        {
            //cout << linea;

            cout << " Pelicula: ";
            // new Pelicula(datos[i]);
        }
        else
        {
            cout << " Episodio: ";
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
