#pragma once
#include "Video.h"
#include "Capitulo.h"
#include <vector>
#include <fstream>
#include <sstream>

class Serie :
    public Video
{
public:
    Serie();
    Serie(string id, string nombre, string genero, string temporadas, string calificacion);

    //CAPITULOS
    /////////////////////
    string getIDCapitulo(int i);
    string getID_EpisodioCapitulo(int i);
    string getNombreCapitulo(int i);
    string getDuracionCapitulo(int i);
    string getTemporadaCapitulo(int i);
    string getNumTemporadas();
    string getCalificacionCapitulo(int i);
    void cargarCapitulos();
    void desplegarCapitulo(int i);  
    int getNumCapitulos();
    /////////////////////
    string datos();
    
private:
    string temporadas;
    vector <Capitulo*> capitulos;
    int numCapitulos;
};

