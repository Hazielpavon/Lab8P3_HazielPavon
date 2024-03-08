#include "Cancion.h"
#include <string>
Cancion::Cancion()
{
}
Cancion::Cancion(string titulo, string artista, int duracion, string genero, int anio) {

	setartista(artista);
	settitulo(titulo); 
	setduracion(duracion);
	setgenero(genero); 
	setanio(anio); 
}
Cancion::~Cancion()
{
	titulo = " ";
	artista = " ";
	duracion = 0;
	genero = " ";
	anio = 0;
}
string Cancion::getartista() const
{
	return artista;
}
void Cancion::setartista(string artista)
{
	this->artista = artista;
}
string Cancion::gettitulo() const
{
	return titulo;
}
void Cancion::settitulo(string titulo)
{
	this->titulo = titulo;
}
int Cancion::getduracion() const
{
	return duracion;
}
void Cancion::setduracion(int duracion)
{
	this->duracion = duracion;
}
string Cancion::getgenero() const
{
	return genero;
}
void Cancion::setgenero(string genero)
{
	this->genero = genero;
}
int Cancion::getanio() const
{
	return anio;
}
void Cancion::setanio(int anio)
{
	this->anio = anio;
}
string Cancion::tostring()
{
	return "Titulo: " + titulo + "\nArtista: " + artista + "\nDuracion: " + to_string(duracion) + " segundos\nGenero: " + genero + "\nAno de lanzamiento: " + to_string(anio) + "\n";
}