/*
Autor: Santiago De La Riva Juárez
Se declara la clase serie para trabajar con episodios
*/

#ifndef SERIE_H
#define SERIE_H

#include "Episodio.h"
#include <vector>
#include <iostream>
#include <string>

class Serie
{
private:
    // Atributos
    string nombreS;
    vector<Episodio> Episodios; // Vector de Episodios de la Serie

public:
    // Constructor Serie
    Serie(vector<Episodio> Episodios);

    // Método para calcular promedio
    double caliPromedio();

    // Sobrecarga del operador <<
    friend ostream &operator<<(ostream &output, const Serie &s); // cout << Serie
};
#endif