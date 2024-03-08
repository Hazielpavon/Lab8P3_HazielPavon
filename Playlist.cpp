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
	/*duracion = 0;*/
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

void Playlist::agregarCancion(Cancion* cancion)
{
	canciones.push_back(cancion); 
	calcularDuracion(); 
}

void Playlist::eliminarCancion(Cancion* cancion)
{
}

void Playlist::fusionarPlaylist(Playlist* otraPlaylist)
{
}

string Playlist::toString() const
{
	return "Nombre: " + nombre + "\nDescripcion: " + descripcion + "\nDuracion: " + to_string(duracion) + "\n";
}
