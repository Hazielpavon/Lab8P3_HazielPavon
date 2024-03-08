#pragma once
#include <iostream>
using namespace std;
class Cancion
{
private:
	string titulo;
	string artista;
	int duracion;
	string genero;
	int anio; 
public:
	Cancion(); 
	Cancion(string titulo, string artista, int duracion, string genero, int anio); 
	~Cancion(); 
	string getartista() const; 
	void setartista(string artista); 
	string gettitulo() const;
	void settitulo(string titulo);
	int getduracion() const;
	void setduracion(int duracion);
	string getgenero() const;
	void setgenero(string genero);
	int getanio() const;
	void setanio(int anio);
	string tostring(); 
};
// ejemplo de getters y setters, siempre se me olvida 
//double gettasa() const;
//void settasa(int Numerodecuenta);