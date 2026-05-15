#include "Manual.h"
#include "Utilidades.h"
#include <iostream>
#include <string>

Manual::Manual()
{
    requisitos = " ";
    dificultad = 0;
}

void Manual::guardar(std::istream& in)
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
    do
    {
        std::cout << "\nDia [12]: ";
        valor = solicitarNum();
    }
    while (valor == -1);
    fecha[0] = valor;
    do
    {
        std::cout << "\nMes [02]: ";
        valor = solicitarNum();
    }
    while (valor == -1);
    fecha[1] = valor;
    do
    {
        std::cout << "\nAño [2026]: ";
        valor = solicitarNum();
    }
    while (valor == -1);
    fecha[2] = valor;
    std::cout << "\nContenido [texto]: ";
    std::getline(in >> std::ws, contenido);

    pasos.clear();
    int numPasos = 0;
    do
    {
        std::cout << "\n¿Cuantos pasos quieres agregar? [numero]: ";
        numPasos = solicitarNum();
    }
    while (numPasos == -1);
    std::cout << "\nIntroduce un paso y presiona enter [texto]:\n";
    for (int i = 0; i < numPasos; ++i)
    {
        std::string paso;
        std::getline(in >> std::ws, paso);
        pasos.push_back(paso);
    }

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

    std::cout << "\nRequisitos [texto]: ";
    std::getline(in >> std::ws, requisitos);

    do
    {
        std::cout << "\nDificultad [numero]: ";
        valor = solicitarNum();
    }
    while (valor == -1);
    dificultad = valor;

    std::cout << "\nHerramienta recomendada [texto]: ";
    std::getline(in >> std::ws, herramienta);
    do
    {
        std::cout << "\nCalificacion [0-10]: ";
        valor = solicitarNum();
    }
    while (valor == -1);
    calificacion = valor;
}

void Manual::mostrar(std::ostream& out) const
{
    out << "\n-----------| Manual |-----------\n"
        << "Titulo: " << titulo << std::endl
        << "Autor: " << autor << std::endl
        << "Fecha: " << fecha[0] << '/' << fecha[1] << '/' << fecha[2] << std::endl
        << "Contenido: " << contenido << std::endl
        << "Requisitos: " << requisitos << std::endl
        << "Pasos: ";

    for (size_t i = 0; i < pasos.size(); ++i)
    {
        if (i) out << ", ";
        out << pasos[i];
    }

    out << "\nTags: ";

    for (size_t i = 0; i < tags.size(); ++i)
    {
        if (i) out << ", ";
        out << tags[i];
    }

    out << std::endl
        << "\nDificultad: " << dificultad << std::endl
        << "Herramienta: " << herramienta << std::endl
        << "Calificacion: " << calificacion << std::endl;
}

int Manual::getDificultad()
{
    return dificultad;
}
void Manual::setDificultad(int d)
{
    dificultad = d;
}
std::string Manual::getHerramienta()
{
    return herramienta;
}
void Manual::setHerramienta(std::string h)
{
    herramienta = h;
}

std::vector<std::string> Manual::getPasos()
{
    return pasos;
}
void Manual::setPasos(std::vector<std::string> p)
{
    pasos = p;
}
std::string Manual::getRequisitos()
{
    return requisitos;
}
void Manual::setRequisitos(std::string r)
{
    requisitos = r;
}
