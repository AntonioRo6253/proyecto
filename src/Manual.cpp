#include "Manual.h"
#include <iostream>
#include <string>

Manual::Manual()
{
    requisitos = " ";
    dificultad = 0;
}

void Manual::guardar(std::istream& in)
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

    pasos.clear();
    int numPasos = 0;
    std::cout << "\n¿Cuantos pasos quieres agregar? ";
    in >> numPasos;
    std::cout << "\nIntroduce los pasos (uno por uno):\n";
    for (int i = 0; i < numPasos; ++i)
    {
        std::string paso;
        in >> paso;
        pasos.push_back(paso);
    }

    std::cout << "\nRequisitos: ";
    std::getline(in >> std::ws, requisitos);

    std::cout << "\nDificultad (numero): ";
    in >> dificultad;

    std::cout << "\nHerramienta recomendada: ";
    std::getline(in >> std::ws, herramienta);
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
