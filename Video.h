/*
Autor: Santiago De La Riva Juárez
Se declara la clase abstracta video (la base del sistema)
*/


#ifndef VIDEO_H
#define VIDEO_H
#include<string>
#include<iostream>

using namespace std; 

class Video
{
protected: 
    // Declaración de Atributos
    // ID, Nombre Pelicula/Serie, Duración, Género, Calificación, Fecha Estreno, ID Episodio, Nombre Episodio, Temporada, Num Episodio
    string ID; 
    string nombre; 
    int duracion;
    string generos;
    double calificacion;  
    string fecha; 

public: 
    // Constructor Video
    Video(string ID, string nombre, int duracion, string generos, double calificacion, string fecha);

    // getters 
    virtual string getNombre();  // Funcion virtual para sobreescribir 

    double getCalificacion();
    int getDuracion();
    vector<string> getGeneros();
    

    // setter
    void setCalificacion(double calificacion); 

    // Funcion virtual pura
    virtual void mostrarInfo() = 0; 
}; 
#endif