
#include <iostream>
#include "Streaming.h"

using namespace std;
using std::cin;
using std::cout;
using std::vector;

#define CAL_MAYOR 7

void subMenu();
void subMenu2(Streaming &servicio);
void subMenu3(Streaming &servicio);
void subMenu4(Streaming &servicio);
void subMen5(Streaming &servicio);
void subMenu6(Streaming &servicio);

int main()
{
    Streaming Netflix;
    int op;
    bool cond = false;
    string archivo;

    while (true)
    {
        cout << "\n*--------------MENÚ----------------*" << endl
             << "[1]. Cargar Archivo (.csv)" << endl
             << "[2]. Filtrar videos en general" << endl
             << "[3]. Mostrar Series" << endl
             << "[4]. Mostrar Peliculas (Por calificación)" << endl
             << "[5]. Calificar un Video" << endl
             << "[6]. Mostrar calificación promedio de una Serie" << endl
             << "[7]. Salir\n"
             << endl;
        cin >> op;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input inválido, ingresa un número entre el 1 - 7 \n"
                 << endl;
            continue;
        }

        if (op == 1)
        {
            cout << "\n Nombre de tu archivo: " << endl;
            cin >> archivo;
            Netflix.cargarCatalogo(archivo);
            cout << "\n Archivo cargado con Éxito." << endl;
        }
        else if (op == 2)
        {
            subMenu2(Netflix);
        }
        else if (op == 3)
        {
            subMenu3(Netflix); 
        }
        else if (op == 4)
        {
            subMenu4(Netflix); 
        }
        else if (op == 5)
        {
            cout << "5";
        }
        else if (op == 6)
        {
            cout << "6";
        }
        else if (op == 7)
        {
            cout << "¡Vuelva pronto! :)" << endl;
            break;
        }
        else
        {
            cout << "Error, input no válido" << endl
                 << "Por favor, vuelva a intentarlo" << endl;
            continue;
        }
    }

    return 0;
}

void subMenu2(Streaming &servicio)
{
    int op = 0;
    vector<Video *> video = servicio.getVideos();

    while (true)
    {
        cout << "\n*--------------FILTRAR VIDEOS----------------*" << endl
             << "[1]. Mostrar por calificacion mayor o igual" << endl
             << "[2]. Mostrar PEL por genero" << endl
             << "[3]. Regresar al menú principal\n"
             << endl;
        cin >> op;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input inválido, ingresa un número entre el 1 - 3 \n"
                 << endl;
            continue;
        }

        if (op == 1)
        {
            double cal;
            while (true)
            {
                cout << "\nCalificación deseada: " << endl;
                cin >> cal;
                if (cin.fail() || cal < 0 || cal > CAL_MAYOR)
                {
                    cout << "Input inválido, ingresa una calificación del 1 -" + to_string(CAL_MAYOR) << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    continue;
                }
                else
                {
                    break;
                }
            }

            for (Video *current : video)
            {
                double cc = (*current).getCalificacion();

                if (cc >= cal)
                {
                    (*current).mostrarInfo();
                }
            }
        }
        else if (op == 2)
        {
            while (true)
            {
                string generou;
                vector<Video *> vg;
                cout << "Dame un genero: ";
                cin >> generou;

                for (Video *current : video)
                {
                    vector<string> gc = (*current).getGeneros();

                    for (string genero : gc)
                    {
                        if (genero == generou)
                        {
                            vg.push_back(current);
                            //(*current).mostrarInfo();
                        }
                    }
                }
                if (vg.size() != 0)
                {
                    for (Video *vid : vg)
                    {
                        (*vid).mostrarInfo();
                    }
                    break;
                }
                else
                {
                    cout << "\nNo se encontró dicho género, vuelva a intentarlo." << endl
                         << "Recuerde utilizar máyusculas \n" << endl;
                    continue;
                }
            }
        }

        else if (op == 3)
        {
            return;
        }
        else
        {
            cout << "Error, input no válido" << endl
                 << "Por favor, vuelva a intentarlo" << endl;
            continue;
        }
    }
}

void subMenu3(Streaming &servicio)
{
    string nSerie;
    vector<Episodio *> episodios = servicio.getEpisodios();
    vector<Episodio> eSerie;
    // Lo que puedo hacer para errores es al final preguntar si length == 0
    cout << "Name de la serie: " << endl;
    cin.clear();
    cin.ignore(256, '\n');
    getline(cin, nSerie);
   
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

    double calificacion;
    cout << "Dame una calificacion: ";
    cin >> calificacion;
    for (Pelicula *current : peliculas)
    {
        double cc = (*current).getCalificacion();
        if (cc >= calificacion)
        {
            (*current).mostrarInfo();
        }
    }
}

void subMenu5(Streaming &servicio)
{
    double c = 0;
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