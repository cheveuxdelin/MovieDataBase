#include "Video.h"

//CONSTRUCTOR DEFAULT
Video::Video()
{
    id = "";
    nombre = "";
    duracion = "";
    genero = "";
    calificacion = "";
}

//CONSTRUCTOR CON VALORES
Video::Video(string id, string nombre, string duracion, string genero, string calificacion)
{
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calificacion = calificacion;
}

//CONSTRUCTOR CON VALORES PARA SERIES
Video::Video(string id, string nombre, string genero, string calificacion)
{
    this->id = id;
    this->nombre = nombre;
    this->genero = genero;
    this->calificacion = calificacion;
    duracion = "";
}

//GET ID
const string Video::getID()
{
    return id;
}

//GET NOMBRE
const string Video::getNombre()
{
    return nombre;
}

//GET DURACION
const string Video::getDuracion()
{
    return duracion;
}

//GET GENERO
const string Video::getGenero()
{
    return genero;
}   

//GET CALIFICACION
const string Video::getCalificacion()
{
    return calificacion;
}

//SET CALIFICACION
void Video::setCalificacion(string calificacion)
{
    this->calificacion = calificacion;
}

ostream& operator<<(ostream& os, Video& video)
{
    os << video.datos(); 
    return os;
}
