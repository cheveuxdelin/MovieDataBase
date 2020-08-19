#include "Serie.h"

Serie::Serie()
{
	temporadas = "";
	numCapitulos = 0;
	cargarCapitulos();
}

//CONSTRUCTOR SERIE LLAMANDO A CONSTRUCTOR VIDEO
Serie::Serie(string id, string nombre, string genero, string temporadas, string calificacion):Video(id, nombre, genero, calificacion)
{
	this->temporadas = temporadas;
	numCapitulos = 0;
	cargarCapitulos();
}

//GET ID DE CAPITULO
string Serie::getIDCapitulo(int i)
{
	return capitulos[i]->getID();
}

//GET ID_EPISODIO DE CAPITULO
string Serie::getID_EpisodioCapitulo(int i)
{
	return capitulos[i]->getID_Episodio();
}

//GET NOMBRE DE CAPITULO
string Serie::getNombreCapitulo(int i)
{
	return capitulos[i]->getNombre();
}

//GET DURACION DE CAPITULO
string Serie::getDuracionCapitulo(int i)
{
	return capitulos[i]->getDuracion();
}

// GET CALIFICACION DE CAPITULO
string Serie::getCalificacionCapitulo(int i)
{
	return capitulos[i]->getCalificacion();
}

//GET TEMPORADA DE CAPITULO
string Serie::getTemporadaCapitulo(int i)
{
	return capitulos[i]->getTemporada();
}

//GET NUMERO DE TEMPORADAS
string Serie::getNumTemporadas()
{
	return temporadas;
}

//CARGA CAPITULOS DESDE ARCHIVO capitulo.txt
void Serie::cargarCapitulos()
{
	ifstream datosCapitulos("capitulos.txt");
	string id, id_episodio, nombre, duracion, calificacion, temporada;
	string line;
	while (getline(datosCapitulos, line)) {
		stringstream ss(line);
		getline(ss, id, ',');
		getline(ss, id_episodio, ',');
		getline(ss, nombre, ',');
		getline(ss, duracion, ',');
		getline(ss, calificacion, ',');
		getline(ss, temporada, ',');
		if (getID() == id) {
			capitulos.push_back(new Capitulo(id, id_episodio, nombre, duracion, calificacion, temporada));
			numCapitulos++;
		}
		
	}
}

//DESPIECA CAPITULOS DE LA SERIE
void Serie::desplegarCapitulo(int i)
{
	cout << *capitulos[i]<<endl;
}

//GET NUMERO DE CAPITULOS
int Serie::getNumCapitulos()
{
	return numCapitulos;
}

string Serie::datos()
{
	return ("id: " + getID() + ", nombre: " + getNombre() + ", genero: " + getGenero()  +  ", temporadas: "  + getNumTemporadas() + ", calificacion: " + getCalificacion() );
}

