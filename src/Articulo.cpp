#include "Articulo.h"
#include <iostream>
#include <string>

void Articulo::guardar(std::istream& in)
{
    std::cout << "\nTitulo: ";
    std::getline(in >> std::ws, titulo);
    std::cout << "\nAutor: ";
    std::getline(in >> std::ws, autor);
    std::cout << "\nFecha:\nDia: ";
    in >> fecha[0];
    std::cout << "\nMes: ";
    in >> fecha[1];
    std::cout << "\nAño: ";
    in >> fecha[2];
    std::cout << "\nContenido: ";
    std::getline(in >> std::ws, contenido);

    tags.clear();

    int numTags = 0;
    std::cout << "\n¿Cuántos tags quieres agregar? ";
    in >> numTags;

    std::cout << "\nIntroduce los tags (uno por uno, presiona Enter tras cada uno):\n";
    for (int i = 0; i < numTags; ++i)
    {
        std::string tag;
        in >> tag;
        tags.push_back(tag);
    }

    std::cout << "\nTus tags son:\n";
    for (const std::string& tag : tags)
    {
        std::cout << "[" << tag << "] ";
    }
    std::cout << std::endl;
}

void Articulo::mostrar(std::ostream& out) const
{
    out << "\n-----------| Articulo |-----------\n"
        << "Titulo: " << titulo << std::endl
        << "Autor: " << autor << std::endl
        << "Fecha: " << fecha[0] << '/' << fecha[1] << '/' << fecha[2] << std::endl
        << "Contenido: " << contenido << std::endl
        << "Tags: ";

    for (size_t i = 0; i < tags.size(); ++i)
    {
        if (i) out << ", ";
        out << tags[i];
    }

    out << std::endl
        << "Calificacion: " << calificacion << std::endl;
}


