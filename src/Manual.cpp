#include "Manual.h"
#include <iostream>

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
    std::cout << "\n¿Cuántos pasos quieres agregar? ";
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
        << "Calificacion: " << calificacion << std::endl;
}
