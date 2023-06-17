#include "Serie.h"

Serie::Serie(vector<Episodio> Episodios)
{
    this->Episodios = Episodios; 
}

/*void Serie::mostrarEpisodios()
{
    cout << "\t" + nombreS << endl; 

    //int tam = Episodios.size();
    for(Episodio cap : Episodios)
    {
        cout << endl << "S" + to_string(cap.getTemporada()) + " E" + to_string(cap.getEpisodio()) + " - " + cap.getNombre() << endl;
    }
}
*/

double Serie::caliPromedio()
{
    double promedio = 0;
    double total = Episodios.size(); 
    for(Episodio cap: Episodios) 
    {
        promedio += cap.getCalificacion();
    }
    return promedio / total;
}

ostream &operator<<(ostream &output, const Serie &s)
{
    for(Episodio cap : s.Episodios)
    {
        output << endl << "S" + to_string(cap.getTemporada()) + " E" + to_string(cap.getEpisodio()) + " - " + cap.getNombre() << endl;
    }
    return output; 
}
