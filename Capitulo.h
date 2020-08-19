#pragma once
#include <string>
#include <iostream>
using namespace std;

class Capitulo
{
public:
	Capitulo();
	Capitulo(string id, string id_episodio, string nombre, string duracion, string calificacion, string temporada);
	string getID();
	string getID_Episodio();
	string getNombre();
	string getDuracion();
	string getCalificacion();
	string getTemporada();
	friend ostream& operator<<(ostream& os, Capitulo& peli);
private:
	string id;
	string id_episodio;
	string nombre;
	string duracion;
	string calificacion;
	string temporada;
};

