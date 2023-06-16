
#include <iostream>
#include "Streaming.h"

using namespace std;


int main()
{
    Streaming Netflix; 
    int op; 
    bool cond = false; 
    string archivo; 

    do
    {
        cout << "\n*--------------MENÚ----------------*" << endl
             << "[1]. Cargar Archivo (.csv)" << endl
             << "[2]. Filtrar videos en general" << endl
             << "[3]. Mostrar Series" << endl
             << "[4]. Mostrar Peliculas (Por calificación)" << endl
             << "[5]. Calificar un Video" << endl
             << "[6]. Mostrar calificación promedio de una Serie" << endl
             << "[7]. Salir" << endl;
        cin >> op; 


        if(op == 1)
        {
            cout << "\n Nombre de tu archivo: " << endl; cin >> archivo; 
            Netflix.cargarCatalogo(archivo);
            cout << "\n Archivo cargado con Éxito." << endl; 
    
        } else if (op == 2)
        {
            cout << "\n*--------------FILTRAR VIDEOS----------------*" << endl
             << "[1]. Mostrar por calificacion mayor o igual" << endl
             << "[2]. Mostrar calificacion por genero" << endl; 

        } else if (op == 3)
        {
            cout << "Dime la serie que desees ver"
            
        } else if (op == 4)
        
        


        





    } while (true);
    
    return 0;
}
