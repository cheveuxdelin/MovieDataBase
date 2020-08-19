#pragma once
#include <vector>
#include "Pelicula.h"
#include "Serie.h"
#include <fstream>
#include <sstream>
#include "InvalidValueException.h"

class Interfaz
{
public:
	Interfaz();
	void cargarPelis();
	void cargarSeries();
	int getNumPelis();
	int getNumSeries();
	void menu();
private:
	vector <Pelicula*> pelis;
	int numPelis;
	vector <Serie*> series;
	int numSeries;
};

