/*
Autor: Santiago De La Riva Juárez
Main para la implementación del sistema de Streaming
*/

#include <iostream>
#include "Streaming.h"

using namespace std;
using std::cin;
using std::cout;
using std::vector;

// Se define una constante para la calificación mayor 
#define CAL_MAYOR 7

// Se declaran las funciones que harán de "Sub Menus" 

void subMenu1(Streaming &servicio); // Función para cargar un archivo
void subMenu2(Streaming &servicio); // Función para filtrar videos (genero / calificación)
void subMenu3(Streaming &servicio); // Función para mostrar episodios de una serie
void subMenu4(Streaming &servicio); // Función para mostrar peliculas por calificación
void subMenu5(Streaming &servicio); // Función para calificar un video
void subMenu6(Streaming &servicio); // Función para calcular promedio de una serie

int main()
{
    // Se declara un objeto de tipo Streaming para cargar una base de datos y trabajar con los videos
    Streaming Netflix;
    int op;
    
    // La primera vez se pide cargar un archivo antes de iniciar el menú
    subMenu1(Netflix);

    // Loop para el manejo del menú y errores de input del usuario
    while (true)
    {
        // Se muestra el Menú
        cout << "\n*------------------------MENÚ-------------------------*" << endl
             << "[1]. Cargar otro Archivo (.csv)" << endl
             << "[2]. Filtrar Videos en general (Género / Calificación)" << endl
             << "[3]. Mostrar Episodios de una Serie" << endl
             << "[4]. Mostrar Peliculas (Por calificación)" << endl
             << "[5]. Calificar un Episodio / Película" << endl
             << "[6]. Mostrar calificación promedio de una Serie" << endl
             << "[7]. Salir\n"
             << "*------------------------STREAMING---------------------*" << endl;

        cout << "\n¿Qué desea hacer el día de hoy? ";
        cin >> op;

        // Manejo de errores para el input del usuario
        if (cin.fail())
        {
            // EJEMPLO
            // Si el usuario ingresa una string, se pide volver a intentarlo
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Input inválido, ingresa un número entre el 1 - 7 \n"
                 << endl;
            continue;
        }

        // Se 'limpia´el input para el futuro manejo adecuado del método getline()
        cin.ignore();

        // Opciones
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
            cout << "¡Vuelva pronto! :)\n" << endl;
            break;
        }
        // Si hubo algún error, se vuelve a iterar el ciclo para preguntar la opción de nuevo
        else
        {
            // Menejo de error del input del usuario
            cout << "Error, input no válido" << endl
                 << "Por favor, vuelva a intentarlo" << endl;
            continue;
        }
    }

    return 0;
}

// Función para cargar un archivo
void subMenu1(Streaming &servicio)
{
    string archivo;
    bool confirmacion;

    // Loop para el manejo de errores de input del usuario
    while (true)
    {

        cout << "\nDame el nombre de tu archivo: ";
        getline(cin, archivo);

        confirmacion = servicio.cargarCatalogo(archivo);

        // Se confirma si el archivo se cargo correctamente
        if (confirmacion)
        {
            cout << "\nArchivo cargado con Éxito." << endl;
            break;
        }
        // Si no se cargo correctamente, se vuelve a iterar el ciclo para volver a cargar el archivo
        else
        {
            cout << "\nError, no puedo leer al archivo..." << endl
                 << "Recuerda teclear el nombre todo junto y sin '.csv'" << endl;
            continue;
        }
    }
}

// Función para filtrar videos (genero / calificación)
void subMenu2(Streaming &servicio)
{
    int op = 0;

    // Vector de apuntadores de video, se crea la variable para que el codigo se vea limpio
    vector<Video *> video = servicio.getVideos();

    // Loop para el manejo de errores de input del usuario y manejo del 'Sub Menú'
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

        // Manejo de errores para el input del usuario
        if (cin.fail())
        {
            // EJEMPLO
            // Si el usuario ingresa una string, se pide volver a intentarlo
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

            // Loop para continuidad del programa y manejo de errores de input del usuario
            while (true)
            {
                cout << "\nCalificación deseada: ";
                cin >> cal;

                // Manejo de errores para el input del usuario
                if (cin.fail() || cal < 0 || cal > CAL_MAYOR)
                {
                    // EJEMPLO.- La calificación ingresada es negativa
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

            // Se itera sobre cada video del catálogo
            for (Video *current : video)
            {
                // Se guarda la calificacion del video iterado en ese momento
                double cc = (*current).getCalificacion();

                // Se compara la calificacion del video actual con la que pidió el usuario
                if (cc >= cal)
                {
                    // Si es mayor o igual a la calificación ingresada se muestra el Video
                    (*current).mostrarInfo(); // Polimorfismo
                }
            }
        }

        // Filtrar por género 
        else if (op == 2)
        {

            // Loop para continuidad del programa y manejo de errores de input del usuario
            while (true)
            {
                // Género que escribio el usuario
                string generou;

                // Se crea otro vector que guardará los videos que cumplan con el género que desee ver el usuario
                vector<Video *> vg;

                cout << "Dame un genero: ";
                getline(cin, generou);

                // Se itera sobre cada video del catálogo        
                for (Video *current : video)
                {
                    // Se obtiene un vector con los géneros del video separados (cada elemento es un género)
                    vector<string> generoCurrent = (*current).getGeneros();

                    // Se itera cada género de un video
                    for (string genero : generoCurrent)
                    {
                        // Compara si algún género del video actual cumple con el género que pidió el usuario
                        if (genero == generou)
                        {
                            vg.push_back(current);
                        }
                    }
                }

                // Si el vector con apuntadores de videos que cumplen con el género es distinto de cero
                // Quiere decir que se encontraron los videos (input del usuario correcto)
                if (vg.size() != 0)
                {
                    for (Video *vid : vg)
                    {
                        (*vid).mostrarInfo();
                    }
                    break;
                }

                // No se encontró el género que pidió el usuario
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

        // Regresar al menú principal
        else if (op == 3)
        {
            return;
        }

        // Error de input 
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
        string nombreSerie;
        vector<Episodio *> episodios = servicio.getEpisodios();
        vector<Episodio> eSerie;

        cout << "Nombre de la serie: ";

        getline(cin, nombreSerie);

        for (Episodio *current : episodios)
        {
            if (current->getNombreESerie() == nombreSerie)
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

        cout << "\nNo se encontró dicho Episodio / Pelicula, vuelva a intentarlo." << endl
             << "Recuerde utilizar máyusculas y espacios." << endl
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

        cout << "Nombre de la serie: ";

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