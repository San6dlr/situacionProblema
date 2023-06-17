
#ifndef VIDEO_H
#define VIDEO_H
#include<string>
#include<iostream>
using namespace std; 

class Video
{
protected: 
    // ID,Nombre Pelicula/Serie,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio
    string ID; 
    string nombre; 
    int duracion;
    string generos;
    double calificacion; // ¿Que pasa si se pasa una mayor a 7?  
    string fecha; 

public: 
    // Constructor Video
    Video(string ID, string nombre, int duracion, string generos, double calificacion, string fecha);

    // getters 
    virtual string getNombre(); 
    double getCalificacion();
    vector<string> getGeneros();

    // setter
    void setCalificacion(double calificacion); 

    virtual void mostrarInfo() = 0; 
}; 
#endif