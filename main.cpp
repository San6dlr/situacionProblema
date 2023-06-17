
#include <iostream>
#include "Streaming.h"

using namespace std;
using std::cin;
using std::cout;
using std::vector;

#define CAL_MAYOR 7

void subMenu1(Streaming &servicio);
void subMenu2(Streaming &servicio);
void subMenu3(Streaming &servicio);
void subMenu4(Streaming &servicio);
void subMenu5(Streaming &servicio);
void subMenu6(Streaming &servicio);

int main()
{

    Streaming Netflix;
    int op;
    
    subMenu1(Netflix);

    while (true)
    {
        cout << "\n*--------------MENÚ----------------*" << endl
             << "[1]. Cargar otro Archivo (.csv)" << endl
             << "[2]. Filtrar Videos en general" << endl
             << "[3]. Mostrar Series" << endl
             << "[4]. Mostrar Peliculas (Por calificación)" << endl
             << "[5]. Calificar un Episodio / Película" << endl
             << "[6]. Mostrar calificación promedio de una Serie" << endl
             << "[7]. Salir\n"
             << endl;

        cout << "¿Qué desea hacer el día de hoy? ";
        cin >> op;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input inválido, ingresa un número entre el 1 - 7 \n"
                 << endl;
            continue;
        }

        cin.ignore();
        if (op == 1)
        {
            subMenu1(Netflix);
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
            subMenu5(Netflix);
        }
        else if (op == 6)
        {
            subMenu6(Netflix);
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

void subMenu1(Streaming &servicio)
{
    string archivo;
    bool confirmacion;

    while (true)
    {

        cout << "\nDame el nombre de tu archivo: ";
        getline(cin, archivo);

        confirmacion = servicio.cargarCatalogo(archivo);

        if (confirmacion)
        {
            cout << "\nArchivo cargado con Éxito." << endl;
            break;
        }
        else
        {
            cout << "\nError, no puedo leer al archivo..." << endl
                 << "Recuerda teclear el nombre todo junto y sin '.csv'" << endl;
            continue;
        }
    }
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

        cout << "¿Qué desea hacer el día de hoy? ";
        cin >> op;
        cout << endl; 

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input inválido, ingresa un número entre el 1 - 3 \n"
                 << endl;
            continue;
        }

        cin.ignore();
        if (op == 1)
        {
            double cal;
            while (true)
            {
                cout << "\nCalificación deseada: ";
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

            cin.ignore();
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

                getline(cin, generou);

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
                         << "Recuerde utilizar máyusculas" << endl
                         << "Ejemplo: Animacion \n"
                         << endl;
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
    while (true)
    {
        string nSerie;
        vector<Episodio *> episodios = servicio.getEpisodios();
        vector<Episodio> eSerie;

        cout << "Name de la serie: ";

        getline(cin, nSerie);

        for (Episodio *current : episodios)
        {
            if (current->getNombreESerie() == nSerie)
            {
                eSerie.push_back(*current);
            }
        }

        if (eSerie.size() != 0)
        {
            Serie *serie = new Serie(eSerie); // checar lo de apuntador y ver si puedo pasarlo a serie
            cout << *serie;
            break;
        }
        else
        {
            cout << "\nNo se encontró dicha serie, vuelva a intentarlo." << endl
                 << "Recuerde utilizar máyusculas" << endl
                 << "Ejemplo: Game Of Thrones\n"
                 << endl;
            continue;
        }
    }
}

void subMenu4(Streaming &servicio)
{
    double cal;
    vector<Pelicula *> peliculas = servicio.getPeliculas();

    while (true)
    {
        cout << "\nCalificación deseada: ";
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

    cin.ignore();
    for (Pelicula *current : peliculas)
    {
        double currentCal = (*current).getCalificacion();
        if (currentCal >= cal)
        {
            (*current).mostrarInfo();
        }
    }
}

void subMenu5(Streaming &servicio)
{
    while (true)
    {
        double c = 0;
        string nVideo;
        vector<Video *> videos = servicio.getVideos();

        cout << "Nombre del Episodio o Película a calificar: ";

        getline(cin, nVideo);

        for (Video *current : videos)
        {
            if (current->getNombre() == nVideo)
            {
                 
                while (true)
                {
                    cout << "¿Cuánto le pones a " + current->getNombre() + " : ";
                    cin >> c;

                    if (cin.fail() || c < 0 || c > CAL_MAYOR)
                    {
                        cout << "\nInput inválido, ingresa una calificación del 1 -" + to_string(CAL_MAYOR) << endl;
                        cin.clear();
                        cin.ignore(256, '\n');
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }

                cout << "\nSe asigno un " + to_string(c) + " a: " + current->getNombre() << endl;
                current->setCalificacion(c);
                cin.ignore();
                return;
            }
        
        }

        cout << "\nNo se encontró dicho video, vuelva a intentarlo." << endl
             << "Recuerde utilizar máyusculas" << endl
             << endl;
    }
}

void subMenu6(Streaming &servicio)
{
    while (true)
    {
        string nSerie;
        vector<Episodio *> episodios = servicio.getEpisodios();
        vector<Episodio> eSerie;

        cout << "Name de la serie: ";

        getline(cin, nSerie);

        for (Episodio *current : episodios)
        {
            if (current->getNombreESerie() == nSerie)
            {
                eSerie.push_back(*current);
            }
        }

        if (eSerie.size() != 0)
        {
            Serie *serie = new Serie(eSerie); // checar lo de apuntador y ver si puedo pasarlo a serie
            cout << "\nCalificación promedio: " + to_string((*serie).caliPromedio()) << endl;
            break;
        }
        else
        {
            cout << "\nNo se encontró dicha serie, vuelva a intentarlo." << endl
                 << "Recuerde utilizar máyusculas" << endl
                 << "Ejemplo: Game Of Thrones\n"
                 << endl;
            continue;
        }
    }
}