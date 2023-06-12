
#ifndef VIDEO_H
#define VIDEO_H
#include<string>
using namespace std; 

class Video
{
protected: 

    string ID; 
    string nombre; 
    string generos; 
    int calificacion; // ¿Que pasa si se pasa una mayor a 7? 
    double minutos; 
    string fecha; 

public: 
    // Constructor Video
    Video(string ID, string nombre, string generos, int calificacion, double minutos, string fecha);

    // getters 
     
    string getNombre(); 
    string getGeneros();
    int getCalificacion();

    // setters

    void setCalificacion(int calificacion); 

}; 







#endif