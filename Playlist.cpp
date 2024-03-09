#include "Playlist.h"
#include <string>

Playlist::Playlist(string nombre, string descripcion) :

	nombre(nombre), descripcion(descripcion)
{}

Playlist::Playlist()
{
}

Playlist::~Playlist()
{
	for (auto playlist : canciones) {
		delete playlist;
	}
	descripcion = " ";
	nombre = "";
}

string Playlist::getNombre() const
{
	return nombre;
}

void Playlist::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Playlist::getDescripcion() const
{
	return descripcion;
}

void Playlist::setDescripcion(string descripcion)
{
	this->descripcion = descripcion;
}

int Playlist::getDuracion() const
{
	return duracion;
}

void Playlist::calcularDuracion()
{
	duracion = 0;
	for (const auto& cancion : canciones) {
		duracion += cancion->getduracion();
	}
}

void Playlist::getcancionesplay()
{
	cout << "Canciones: " << endl;
	for (int i = 0; i < canciones.size(); i++)
	{
		cout << canciones[i]->tostring();
	}
	cout << endl;
}

Playlist* Playlist::operator+(Cancion* cancion)
{
	canciones.push_back(cancion);
	calcularDuracion();
	return this;
}

Playlist* Playlist::operator-(Cancion* cancion) {

	string titulo = cancion->gettitulo();
	int contador = 0;
	int indice = 0;
	while (contador > canciones.size()) {
		if (titulo == canciones[contador]->gettitulo()) {
			indice = contador;
			break;
		}
	}

	canciones.erase(canciones.begin() + indice);
	calcularDuracion();
	return this;
}

Playlist* Playlist::operator+(Playlist* otraPlaylist) {
	string nuevoNombre = nombre + "_" + otraPlaylist->getNombre();
	string nuevaDescripcion = descripcion + "_" + otraPlaylist->getDescripcion();
	Playlist* nuevaPlaylist = new Playlist(nuevoNombre, nuevaDescripcion);
	nuevaPlaylist->canciones = canciones; 
	for (auto cancion : otraPlaylist->canciones) {
		nuevaPlaylist->canciones.push_back(cancion); 
	}
	nuevaPlaylist->calcularDuracion();
	return nuevaPlaylist;
}

bool Playlist::operator>(Playlist* playlist) 
{
	return this->getDuracion() > playlist->getDuracion();
}

string Playlist::toString() const
{
	return "Nombre: " + nombre + "\nDescripcion: " + descripcion + "\nDuracion: " + to_string(duracion) + "\n";
}
