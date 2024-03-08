#pragma once
using namespace std; 
#include <iostream>
#include <vector>
#include <memory.h>
#include "Cancion.h"
class Playlist
{
private:
    string nombre = "";
    string descripcion= " ";
    int duracion = 0;
    vector<Cancion*> canciones;

public:
    Playlist(string nombre, string descripcion);
    Playlist(); 
    ~Playlist();
    string getNombre() const;
    void setNombre(string nombre);
    string getDescripcion() const;
    void setDescripcion(string descripcion);
    int getDuracion() const;
    void calcularDuracion();
    void getcancionesplay(); 
    void agregarCancion(Cancion* cancion);
    void eliminarCancion(Cancion* cancion);
    void fusionarPlaylist(Playlist* otraPlaylist);
    string toString() const;
};



