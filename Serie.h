
#ifndef SERIE_H
#define SERIE_H

#include "Episodio.h"
#include<vector>
#include<iostream>
#include<string>


class Serie
{
private:
    string nombreS; 
    vector<Episodio> Episodios; 

public: 
    Serie(vector<Episodio> Episodios); 

    void mostrarEpisodios();
    double caliPromedio(); 

};
#endif