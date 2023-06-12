
#ifndef SERIE_H
#define SERIE_H

#include "Episodio.h"
#include<vector>


class Serie
{
private: 
    vector<Episodio> Episodios; 

public: 
    Serie(vector<Episodio> Episodios); 

};
#endif