
#include <iostream>
#include "Streaming.h"

using namespace std;

void subMenu();
void subMenu2();
void subMenu3();
void subMenu4();
void subMen5();
void subMenu6();

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

        if (op == 1)
        {
            cout << "\n Nombre de tu archivo: " << endl;
            cin >> archivo;
            Netflix.cargarCatalogo(archivo);
            cout << "\n Archivo cargado con Éxito." << endl;
        }
        else if (op == 2)
        {
            cout << "\n*--------------FILTRAR VIDEOS----------------*" << endl
                 << "[1]. Mostrar por calificacion mayor o igual" << endl
                 << "[2]. Mostrar calificacion por genero" << endl;
        }
        else if (op == 3)
        {
            cout << "Dime la serie que desees ver";
        }

    } while (true);

    return 0;
}

void subMenu2(Streaming &servicio)
{
    vector<Video *> video = servicio.getVideos();

    int calificacion;
    cout << "Dame una calificacion: ";
    cin >> calificacion;
    for (Video *current : video)
    {
        int cc = (*current).getCalificacion();
        if (cc >= calificacion)
        {
            (*current).mostrarInfo();
        }
    }

    string generou;
    cout << "Dame un genero: ";
    cin >> generou;
    for (Video *current : video)
    {
        vector<string> gc = (*current).getGeneros();
        for (string genero : gc)
        {
            if (genero == generou)
            {
                (*current).mostrarInfo();
            }
        }
    }
}

void subMenu3(Streaming &servicio)
{
    string nSerie;
    cout << "Name de la serie: ";
    cin >> nSerie;
    vector<Episodio *> episodios = servicio.getEpisodios();
    vector<Episodio> eSerie;
    // Lo que puedo hacer para errores es al final preguntar si length == 0

    for (Episodio *current : episodios)
    {
        if (current->getNombre() == nSerie)
        {
            eSerie.push_back(*current);
        }
    }

    if (eSerie.size() != 0)
    {
        Serie *serie = new Serie(eSerie); // checar lo de apuntador y ver si puedo pasarlo a serie
        cout << *serie;
    }
    else
    {
        cout << "error";
        return;
    }
}

void subMenu4(Streaming &servicio)
{
    vector<Pelicula *> peliculas = servicio.getPeliculas();

    int calificacion;
    cout << "Dame una calificacion: ";
    cin >> calificacion;
    for (Pelicula *current : peliculas)
    {
        int cc = (*current).getCalificacion();
        if (cc >= calificacion)
        {
            (*current).mostrarInfo();
        }
    }
}

void subMenu5(Streaming &servicio)
{
    int c = 0;
    string nVideo;
    cout << "Name del video a calificar: ";
    cin >> nVideo;
    vector<Video *> videos = servicio.getVideos();

    for (Video *current : videos)
    {
        if (current->getNombre() == nVideo)
        {
            cout << "Dame la calificacion para: " + current->getNombre();
            cin >> c;
            cout << "Se asigno un " << c << "a la serie: " << current->getNombre() << endl;
            return current->setCalificacion(c);
        }
    }

    cout << "Error no se encontro  la serie, volver a ingresar un dato";
}

void subMenu6(Streaming &servicio)
{
    string nSerie;
    cout << "Name de la serie: ";
    cin >> nSerie;
    vector<Episodio *> episodios = servicio.getEpisodios();
    vector<Episodio> eSerie;
    // Lo que puedo hacer para errores es al final preguntar si length == 0

    for (Episodio *current : episodios)
    {
        if (current->getNombre() == nSerie)
        {
            eSerie.push_back(*current);
        }
    }

    if (eSerie.size() != 0)
    {
        Serie *serie = new Serie(eSerie); // checar lo de apuntador y ver si puedo pasarlo a serie
        cout << (*serie).caliPromedio();
    }
    else
    {
        cout << "error";
        return;
    }
}