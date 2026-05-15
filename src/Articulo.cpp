#include "Articulo.h"
#include <iostream>
#include <string>

Articulo::Articulo()
{
    visitas = 0;
    resumen = " ";
}

void Articulo::guardar(std::istream& in)
{
    std::cout << "\nTitulo [texto]: ";
    /*
    El std::ws asegura que se ignoren los espacios en blanco antes de leer la línea
    evita que si escribimos un titulo con espacios, solo se lea la primera palabra y el resto se quede en el buffer
    */
    std::getline(in >> std::ws, titulo);
    std::cout << "\nAutor [texto]: ";
    std::getline(in >> std::ws, autor);
    int valor;
    // Fecha: dia
    do {
        std::cout << "\nDia [12]: ";
        valor = solicitarNum();
    } while (valor == -1);
    fecha[0] = valor;
    // mes
    do {
        std::cout << "\nMes [02]: ";
        valor = solicitarNum();
    } while (valor == -1);
    fecha[1] = valor;
    // año
    do {
        std::cout << "\nAño [2026]: ";
        valor = solicitarNum();
    } while (valor == -1);
    fecha[2] = valor;
    std::cout << "\nContenido [texto]: ";
    std::getline(in >> std::ws, contenido);

    tags.clear();

    int numTags = 0;
    do
    {
        std::cout << "\n¿Cuantos tags quieres agregar? [numero]: ";
        numTags = solicitarNum();
    }
    while (numTags == -1);

    std::cout << "\nIntroduce un tag y presiona enter [texto]:\n";
    for (int i = 0; i < numTags; ++i)
    {
        std::string tag;
        in >> tag;
        tags.push_back(tag);
    }

    std::cout << "\nTus tags son:\n";
    for (std::string tag : tags)
    {
        std::cout << "[" << tag << "] ";
    }
    std::cout << std::endl;

    std::cout << "\nResumen [texto]: ";
    std::getline(in >> std::ws, resumen);

    do {
        std::cout << "\nVisitas [numero]: ";
        valor = solicitarNum();
    } while (valor == -1);
    visitas = valor;
    do {
        std::cout << "\nCalificacion [0-10]: ";
        valor = solicitarNum();
    } while (valor == -1);
    calificacion = valor;
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
        << "\nResumen: " << resumen << std::endl
        << "Visitas: " << visitas << std::endl
        << "Calificacion: " << calificacion << std::endl;
}

int Articulo::getVisitas()
{
    return visitas;
}
void Articulo::setVisitas(int v)
{
    visitas = v;
}
std::string Articulo::getResumen()
{
    return resumen;
}
void Articulo::setResumen(std::string r)
{
    resumen = r;
}


