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
		cout << "5. Fusionar Playlist" << endl;
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
			cout << "Playlists disponibles y Canciones dentro de la playlist : " << endl;
			for (int i = 0; i < playlist.size(); i++)
			{
				cout << playlist[i]->toString();
				playlist[i]->getcancionesplay(); 
			}
			cout << "Ingrese el numero de la playlist a la que desea agregar la cancion: ";
			cin >> listaIndex;
			cout << "Canciones disponibles:\n";
			for (int i = 0; i < canciones.size(); i++)
			{
				cout << canciones[i]->tostring();
			}
			cout << "Ingrese el numero de la cancion que desea agregar: ";
			cin >> cancionIndex;
			if (listaIndex > 0 && listaIndex <= playlist.size() && cancionIndex > 0 && cancionIndex <= canciones.size())  {
				*playlist[listaIndex - 1] + canciones[cancionIndex - 1];
				cout << "Cancion agregada a la playlist correctamente.\n";
			}
			else {
				cout << "Indices incorrectos.\n";
			}
			break;
		}
		case 4: {
			int listaIndex, cancionIndex;
			cout << "Playlists disponibles y Canciones dentro de la playlist : " << endl;
			for (int i = 0; i < playlist.size(); i++)
			{
				cout << playlist[i]->toString();
				playlist[i]->getcancionesplay();
			}
			cout << "Ingrese el numero de la playlist a la que desea eliminar la cancion: ";
			cin >> listaIndex;
			cout << "Canciones Dentro de la playlist:\n";
			playlist[listaIndex - 1]->getcancionesplay();
			cout << "Ingrese el numero de la cancion que desea eliminar: ";
			cin >> cancionIndex;
			if (listaIndex > 0 && listaIndex <= playlist.size() && cancionIndex > 0 && cancionIndex <= canciones.size()) {
				*playlist[listaIndex - 1] - canciones[cancionIndex - 1];
				cout << "Cancion agregada a la playlist correctamente.\n";
			}
			else {
				cout << "Indices incorrectos.\n";
			}
			break;
		}
		case 5: {
			cout << "Playlists disponibles para fusionar:" << endl;
			for (int i = 0; i < playlist.size(); i++) {
				cout << i + 1 << ". " << playlist[i]->toString();
			}

			int indicePlaylist1, indicePlaylist2;
			cout << "Ingrese el numero de la primera playlist: ";
			cin >> indicePlaylist1;
			cout << "Ingrese el numero de la segunda playlist: ";
			cin >> indicePlaylist2;

			if (indicePlaylist1 > 0 && indicePlaylist1 <= playlist.size() &&
				indicePlaylist2 > 0 && indicePlaylist2 <= playlist.size()) {
				Playlist* fusionada = *playlist[indicePlaylist1 - 1] + playlist[indicePlaylist2 - 1];
				if (fusionada != nullptr) {
					cout << "Playlist fusionada creada correctamente." << endl;
					playlist.push_back(fusionada);
				}
				else {
					cout << "Error al fusionar las playlists." << endl;
				}
			}
			else {
				cout << "Indices incorrectos." << endl;
			}
			break;
		}

		case 6: {
			cout << "Playlists disponibles para comparar duración:" << endl;
			for (int i = 0; i < playlist.size(); ++i) {
				cout << i + 1 << ". " << playlist[i]->getNombre() << endl;
			}

			int indicePlaylist1, indicePlaylist2;
			cout << "Ingrese el numero de la primera playlist: ";
			cin >> indicePlaylist1;
			cout << "Ingrese el numero de la segunda playlist: ";
			cin >> indicePlaylist2;

			if (indicePlaylist1 > 0 && indicePlaylist1 <= playlist.size() &&
				indicePlaylist2 > 0 && indicePlaylist2 <= playlist.size()) {
				if (*playlist[indicePlaylist1 - 1] > playlist[indicePlaylist2 - 1]) {
					cout << "La primera playlist tiene una duración mayor." << endl;
				}
				else {
					cout << "La segunda playlist tiene una duración mayor." << endl;
				}
			}
			else {
				cout << "Indices incorrectos." << endl;
			}
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
