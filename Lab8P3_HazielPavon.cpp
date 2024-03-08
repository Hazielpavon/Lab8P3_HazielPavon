using namespace std;
#include <iostream>
#include <vector>
#include <memory.h>
#include "Cancion.h"
#include <string>
#include "Playlist.h"
void ejercicio1(vector<Cancion*>& canciones, vector<Playlist*>& playlist) {
	bool seguir = true;
	while (seguir) {
		cout << "=== MENU PRINCIPAL ===" << endl;
		cout << "1. Agregar Cancion" << endl;
		cout << "2. Crear Playlist" << endl;
		cout << "3. Agregar Cancion a Playlist" << endl;
		cout << "4. Eliminar Cancion de Playlist" << endl;
		cout << "5. Fusionar Playslit" << endl;
		cout << "6. Comparar Duracion de Playlist" << endl;
		cout << "7. Salir" << endl;
		cout << "Ingrese una opcion: ";
		int opcion = 0;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			int duracion = 0;
			int anio = 0;
			string genero = " ";
			string titulo = " ";
			string artista = " ";
			cout << "Agregar una nueva cancion: " << endl;
			cout << "Ingrese el titulo de la cancion: ";
			cin.ignore();
			getline(cin, titulo);
			cout << "Ingrese el artista: ";
			cin.ignore();
			getline(cin, artista);
			cout << "Ingrese la duracion de la cancion(en segundos): ";
			cin >> duracion;
			cout << "Ingrese el genero: ";
			cin.ignore();
			getline(cin, genero);
			cout << "Ingrese el anio de lanzamiento: ";
			cin >> anio;
			canciones.push_back(new Cancion(titulo, artista, duracion, genero, anio));
			cout << "Cancion " << "'" << titulo << "'" << "agregada exitosamente." << endl;
			break;
		}
		case 2: {
			string nombre, descripcion;
			cout << "Ingrese el nombre de la playlist: ";
			cin.ignore();
			getline(cin, nombre);
			cout << "Ingrese la descripción de la playlist: ";
			cin.ignore();
			getline(cin, descripcion);
			playlist.push_back(new Playlist(nombre, descripcion));
			cout << "Playlist agregada correctamente.\n";
			break;
		}
		case 3: {
			int listaIndex, cancionIndex;
			Playlist p;
			cout << "Playlists disponibles y Canciones dentro de la playlist : " << endl;

			for (int i = 0; i < playlist.size(); i++)
			{
				cout << playlist[i]->toString();
			}
			p.getcancionesplay();

			cout << "Ingrese el numero de la playlist a la que desea agregar la cancian: ";
			cin >> listaIndex;
			cout << "Canciones disponibles:\n";
			for (int i = 0; i < canciones.size(); i++)
			{
				cout << canciones[i]->tostring();
			}
			cout << "Ingrese el numero de la cancion que desea agregar: ";
			cin >> cancionIndex;
			if (listaIndex > 0 && listaIndex <= playlist.size() && cancionIndex > 0 && cancionIndex <= canciones.size())  {
				playlist[listaIndex - 1]->agregarCancion(canciones[cancionIndex - 1]);
				cout << "Canción agregada a la playlist correctamente.\n";
			}
			else {
				cout << "Indices incorrectos.\n";
			}
			break;
		}
		case 4: {

			break;
		}
		case 5: {

			break;
		}
		case 6: {

			break;
		}
		case 7: {
			cout << "Saliendo..." << endl;
			seguir = false;
			break;
		}
		default: {
			cout << "Ingrese una opcion Correcta" << endl;
			break;
		}
		}
	}
}
int main()
{
	vector<Cancion*> canciones;
	vector<Playlist*> playlist;
	ejercicio1(canciones, playlist);
}
//int opcion;
//do {
//	cout << "\nMenú:\n";
//	cout << "1. Agregar canciones\n";
//	cout << "2. Agregar Playlist\n";
//	cout << "3. Agregar canciones a Playlist\n";
//	cout << "4. Eliminar canciones de Playlist\n";
//	cout << "5. Fusionar Playlist\n";
//	cout << "6. Comparar duraciones de Playlist\n";
//	cout << "7. Salir\n";
//	cout << "Ingrese su opción: ";
//	cin >> opcion;
//
//	switch (opcion) {
//	case 1: {
//		string titulo, artista, genero;
//		int duracion, anoLanzamiento;
//		cout << "Ingrese el título de la canción: ";
//		cin >> titulo;
//		cout << "Ingrese el artista de la canción: ";
//		cin >> artista;
//		cout << "Ingrese la duración de la canción en segundos: ";
//		cin >> duracion;
//		cout << "Ingrese el género de la canción: ";
//		cin >> genero;
//		cout << "Ingrese el año de lanzamiento de la canción: ";
//		cin >> anoLanzamiento;
//		c
//		cout << "Canción agregada correctamente.\n";
//		break;
//	}
//	case 2: {
//		string nombre, descripcion;
//		cout << "Ingrese el nombre de la playlist: ";
//		cin >> nombre;
//		cout << "Ingrese la descripción de la playlist: ";
//		cin >> descripcion;
//		listas.push_back(new Playlist(nombre, descripcion));
//		cout << "Playlist agregada correctamente.\n";
//		break;
//	}
//	case 3: {
//		mostrarListas(listas);
//		int listaIndex, cancionIndex;
//		cout << "Ingrese el número de la playlist a la que desea agregar la canción: ";
//		cin >> listaIndex;
//		cout << "Canciones disponibles:\n";
//		mostrarCanciones(canciones);
//		cout << "Ingrese el número de la canción que desea agregar: ";
//		cin >> cancionIndex;
//		if (listaIndex > 0 && listaIndex <= listas.size() && cancionIndex > 0 && cancionIndex <= canciones.size()) {
//			listas[listaIndex - 1]->agregarCancion(canciones[cancionIndex - 1]);
//			cout << "Canción agregada a la playlist correctamente.\n";
//		}
//		else {
//			cout << "Índices incorrectos.\n";
//		}
//		break;