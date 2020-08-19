#include "Capitulo.h"

Capitulo::Capitulo()
{
	id = "";
	id_episodio = "";
	nombre = "";
	duracion = "";
	calificacion = "";
	temporada = "";
}

//CONSTRUCTOR DE CAPITULOS
Capitulo::Capitulo(string id, string id_episodio, string nombre, string duracion, string calificacion, string temporada)
{
	this->id = id;
	this->id_episodio = id_episodio;
	this->nombre = nombre;
	this->duracion = duracion;
	this->calificacion = calificacion;
	this->temporada = temporada;
}

//GET ID
string Capitulo::getID()
{
	return id;
}

//GET ID DE EPISODIO
string Capitulo::getID_Episodio()
{
	return id_episodio;
}

//GET NOMBRE
string Capitulo::getNombre()
{
	return nombre;
}

//GET DURACION
string Capitulo::getDuracion()
{
	return duracion;
}

//GET CALIFICACION
string Capitulo::getCalificacion()
{
	return calificacion;
}

//GET TEMPORADA
string Capitulo::getTemporada()
{
	return temporada;
}

ostream& operator<<(ostream& os, Capitulo& capitulo)
{
	os << "id: " << capitulo.getID() <<", id episodio: " << capitulo.getID_Episodio() << ", nombre: " << capitulo.getNombre() << ", duracion: " << capitulo.getDuracion() << ", calificacion: " <<capitulo.getCalificacion()<<", temporada: " << capitulo.getTemporada() << endl;
	return os;
}
