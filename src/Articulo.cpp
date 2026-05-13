#include "Articulo.h"
#include <iostream>
#include <fstream> // Librería necesaria para manejo de archivos
#include <string>
#include <sstream>
#include <algorithm>
#include "Articulo.h"

Articulo::Articulo()
{
    //ctor
}

std::istream& operator>>(std::istream& in, Articulo& art)
{
    std::cout << "\nTitulo: ";
    in >> art.titulo;
    std::cout << "\nAutor: ";
    in >> art.autor;
    std::cout << "\nFecha:\nDia: ";
    in >> art.fecha[0];
    std::cout << "\nMes: ";
    in >> art.fecha[1];
    std::cout << "\nAño: ";
    in >> art.fecha[2];
    std::cout << "\nContenido: ";
    in >> art.contenido;

    art.tags.clear();

    int numTags = 0;
    std::cout << "\n¿Cuántos tags quieres agregar? ";
    in >> numTags;

    std::cout << "\nIntroduce los tags (uno por uno, presiona Enter tras cada uno):\n";
    for (int i = 0; i < numTags; ++i)
    {
        std::string tag;
        in >> tag;
        art.tags.push_back(tag); // Agrega el tag al final del vector
    }

    std::cout << "\nTus tags son:\n";
    for (const std::string& tag : art.tags)
    {
        std::cout << "[" << tag << "] ";
    }
    std::cout << std::endl;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Articulo& art)
{
    out << "\n-----------| Articulo |-----------\n"
        << "Titulo: " << art.titulo << std::endl
        << "Autor: " << art.autor << std::endl
        << "Fecha: " << art.fecha[0] << '/' << art.fecha[1] << '/' << art.fecha[2] << std::endl
        << "Contenido: " << art.contenido << std::endl
        << "Tags: ";

    for (size_t i = 0; i < art.tags.size(); ++i)
    {
        if (i) out << ", ";
        out << art.tags[i];
    }

    out << std::endl
        << "Calificacion: " << art.calificacion << std::endl;
    return out;
}


