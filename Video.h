#pragma once
#include <string>
#include <iostream>
using namespace std;

class Video
{
	friend ostream& operator<<(ostream& os, Video& video);
public:
	Video();
	Video(string id, string nombre, string duracion, string genero, string calificacion);
	Video(string id, string nombre, string genero, string calificacion);
	const string getID();
	const string getNombre();
	const string getDuracion();
	const string getGenero();
	const string getCalificacion();
	void setCalificacion(string calificacion);
	virtual string datos() = 0;
private:
	string id;
	string nombre;
	string duracion;
	string genero;
	string calificacion;
};

