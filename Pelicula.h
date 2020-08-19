#pragma once
#include "Video.h"
class Pelicula :
    public Video
{
public:
    Pelicula();
    Pelicula(string id, string nombre, string duracion, string genero, string calificacion);
    string datos();
};