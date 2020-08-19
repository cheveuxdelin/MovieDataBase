#include "Interfaz.h"

//CONSTRUCTOR INTERFAZ
Interfaz::Interfaz()
{
	numPelis = 0;
	numSeries = 0;
	
	menu();
}

//CARGA PELICULAS DESDE ARCHIVO pelis.txt
void Interfaz::cargarPelis()
{
	
	ifstream datosPelis("peliculas.txt");
	string id, nombre, duracion, genero, calificacion;
	string line;
	while (getline(datosPelis, line)) {
		stringstream ss(line);
		getline(ss, id, ',');
		getline(ss, nombre, ',');
		getline(ss, duracion, ',');
		getline(ss, genero, ',');
		getline(ss, calificacion, ',');
		pelis.push_back(new Pelicula(id, nombre, duracion, genero, calificacion));
		numPelis++;
	}	
}

//CARGA SERIES DESDE ARCHIVO series.txt
void Interfaz::cargarSeries()
{
	ifstream datosSeries("series.txt");
	string id, nombre, genero, temporadas, calificacion;
	string line;
	while (getline(datosSeries, line)) {
		stringstream ss(line);
		getline(ss, id, ',');
		getline(ss, nombre, ',');
		getline(ss, genero, ',');
		getline(ss, temporadas, ',');
		getline(ss, calificacion, ',');
		series.push_back(new Serie(id, nombre, genero, temporadas, calificacion));
		numSeries++;
	}
	
}


int Interfaz::getNumPelis()
{
	return numPelis;
}

int Interfaz::getNumSeries()
{
	return numSeries;
}

void Interfaz::menu()
{
	cout << "BIENVENIDO :)" << endl;
	while (true) {
		cout << endl << endl;
		cout << "1. Cargar archivo de datos (SE DEBE HACER PRIMERO)" << endl;
		cout << "2. Mostrar los videos en general con una cierta calificacion o de un cierto genero" << endl;
		cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
		cout << "4. Mostrar las peliculas con cierta calificacion" << endl;
		cout << "5. Calificar un video" << endl;
		cout << "0. Salir" << endl;
		int opcion;
		cin >> opcion;
		if (opcion == 1) {
			//1. Cargar archivo de datos
			cargarPelis();
			cargarSeries();
			cout << "ARCHIVO CARGADOS" << endl;
			cout << "--------------------------------------------------------------------" << endl << endl;
		}
		else if (opcion == 2) {
			//2. Mostrar los videos en general con una cierta calificación o de un cierto género
			cout << "1 - Calificacion" << endl;
			cout << "2 - Genero"<<endl;
			int opcion_;
			cin >> opcion_;
			if (opcion_ == 1) {
				//CALIFICACION
				// //
				cout << "INGRESE LIMITE INFERIOR: " << endl;
				float limInferior;
				cin >> limInferior;
				cout << "INGRESE LIMITE SUPERIOR: " << endl;
				float limSuperior;
				cin >> limSuperior;
				// //

				//PELICULAS
				cout <<endl<< "PELICULAS: " << endl;
				for (int i = 0; i < numPelis; i++) {
					float calificacion = stof(pelis[i]->getCalificacion());
					if (calificacion <= limSuperior && calificacion >= limInferior)
					{
						cout << *pelis[i] << endl;
					}
				}
				//SERIES
				cout <<endl<<"SERIES: " << endl;
				for (int i = 0; i < numSeries; i++) {
					float calificacion = stof(series[i]->getCalificacion());
					if (calificacion <= limSuperior && calificacion >= limInferior)
					{
						cout << *series[i] << endl;
					}
				}

				cout << "--------------------------------------------------------------------" << endl << endl;
				
			}
			if (opcion_ == 2) {
				//GENERO

				//VECTOR CON TODOS LOS GENEROS CONTENIDOS EN SERIES Y PELICULAS
				vector <string> generos;
				for (int i = 0; i < numPelis; i++) {
					if (find(generos.begin(), generos.end(), pelis[i]->getGenero()) == generos.end()) {
						generos.push_back(pelis[i]->getGenero());
					}
				}
				for (int i = 0; i < numSeries; i++) {
					if (find(generos.begin(), generos.end(), series[i]->getGenero()) == generos.end()) {
						generos.push_back(series[i]->getGenero());
					}
				}
				
				cout <<endl<< "SELECCIONE GENERO: " << endl;

				//DESPLEGAMOS TODOS LOS GENEROS
				for (int i = 0; i < generos.size(); i++) {
					cout<<i<<" - " << generos[i] << endl;
				}
				
				int eleccion;
				cin >> eleccion;

				//DESPLEGAMOS VIDEOS CON GENERO SELECCIONADO
				for (int i = 0; i < numPelis; i++) {
					if (pelis[i]->getGenero() == generos[eleccion]) {
						cout << *pelis[i]<<endl;
					}
				}
				for (int i = 0; i < numSeries; i++) {
					if (series[i]->getGenero() == generos[eleccion]) {
						cout << *series[i]<<endl;
					}
				}
				cout << "--------------------------------------------------------------------" << endl << endl;
			}

		}
		else if (opcion == 3) {
			//3. Mostrar los episodios de una determinada serie con una calificacion determinada
			int eleccionSerie;
			for (int i = 0; i < numSeries; i++) {
				cout << i << " - " << series[i]->getNombre() << endl;
			}
			cin >> eleccionSerie;
			// //
			cout << "INGRESE LIMITE INFERIOR: " << endl;
			float limInferior;
			cin >> limInferior;
			cout << "INGRESE LIMITE SUPERIOR: " << endl;
			float limSuperior;
			cin >> limSuperior;
			// //
			for (int i = 0; i < series[eleccionSerie]->getNumCapitulos(); i++) {
				float calificacion = stof(series[eleccionSerie]->getCalificacionCapitulo(i));
				if (calificacion <= limSuperior && calificacion >= limInferior)
				{
					series[eleccionSerie]->desplegarCapitulo(i);
				}

			}

			cout << "--------------------------------------------------------------------" << endl << endl;
		}
		else if (opcion == 4) {
			//4. Mostrar las películas con cierta calificacion
			// //
			cout << "INGRESE LIMITE INFERIOR: " << endl;
			float limInferior;
			cin >> limInferior;
			cout << "INGRESE LIMITE SUPERIOR: " << endl;
			float limSuperior;
			cin >> limSuperior;
			// //
			for (int i = 0; i < numPelis; i++) {
				float calificacion = stof(pelis[i]->getCalificacion());
				if (calificacion <= limSuperior && calificacion >= limInferior)
				{
					cout << *pelis[i]<<endl;
				}
			}
			cout << "--------------------------------------------------------------------" << endl << endl;
		}
		else if (opcion == 5) {
			//5. Calificar un video
			cout << "1 - PELICULA" << endl << "2 - SERIE" << endl;
			int eleccionVideo;
			cin >> eleccionVideo;

			if (eleccionVideo == 1) {
				cout << "SELECCIONE TITULO A CALIFICAR"<<endl;
				int numTitulo;
				for (int i = 0; i < numPelis; i++){
					cout << i << " - " <<*pelis[i] << endl;
				}
				cin >> numTitulo;
				cout << "INGRESE PUNTAJE: ";
				string puntaje;
				cin >> puntaje;
				try {
					if(stof(puntaje) > 10 || stof(puntaje) < 0) {
						InvalidValueException abc;
						throw abc;

					}
				}
				catch (InvalidValueException& c) {
					cout << c.what() << ", Puntaje ingresado mayor a 10";
					break;
				}
				pelis[numTitulo]->setCalificacion(puntaje);
				cout <<"CAMBIO REALIZADO: "<< *pelis[numTitulo]<<endl;
			}
			if (eleccionVideo == 2) {
				cout << "SELECCIONE TITULO A CALIFICAR" << endl;
				int numTitulo;
				for (int i = 0; i < numSeries; i++) {
					cout << i << " - " << *series[i] << endl;
				}
				cin >> numTitulo;
				cout << "INGRESE PUNTAJE: ";
				string puntaje;
				cin >> puntaje;
				try {
					if (stof(puntaje) > 10 || stof(puntaje) < 0) {
						InvalidValueException abc;
						throw abc;

					}
				}
				catch (InvalidValueException& c) {
					cout << c.what() << ", Puntaje ingresado mayor a 10";
					break;
				}
				series[numTitulo]->setCalificacion(puntaje);
				cout << "CAMBIO REALIZADO: " << *series[numTitulo] << endl;

				cout << "--------------------------------------------------------------------" << endl << endl;
			}
			

		}
		else if (opcion == 0) {
			//0. Salir
			cout << "gracias " << endl;
			break;
		}
	}
}

