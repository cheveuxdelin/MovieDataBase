#include "Pelicula.h"


Pelicula::Pelicula()
{
}

//CONSTRUCTOR PELICULAS LLAMANDO A CONSTRUCTOR VIDEO
Pelicula::Pelicula(string id, string nombre, string duracion, string genero, string calificacion):Video(id, nombre, duracion, genero, calificacion)
{
	
}

string Pelicula::datos()
{
	return ("id: " + getID() + ", nombre: " + getNombre() + ", duracion: " + getDuracion() + ", genero: " + getGenero() + ", calificacion: " + getCalificacion() );
}

