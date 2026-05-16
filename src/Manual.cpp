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
    std::cout << "\n\033[36mTitulo [texto]: \033[0m";
    /*
    El std::ws asegura que se ignoren los espacios en blanco antes de leer la línea
    evita que si escribimos un titulo con espacios, solo se lea la primera palabra y el resto se quede en el buffer
    */
    std::getline(in >> std::ws, titulo);
    std::cout << "\n\033[36mAutor [texto]: \033[0m";
    std::getline(in >> std::ws, autor);
    int valor;
    do
    {
        std::cout << "\n\033[36mDia [12]: \033[0m";
        valor = solicitarNum();
    }
    while (valor == -1);
    fecha[0] = valor;
    do
    {
        std::cout << "\n\033[36mMes [02]: \033[0m";
        valor = solicitarNum();
    }
    while (valor == -1);
    fecha[1] = valor;
    do
    {
        std::cout << "\n\033[36mAño [2026]: \033[0m";
        valor = solicitarNum();
    }
    while (valor == -1);
    fecha[2] = valor;
    std::cout << "\n\033[36mContenido [texto]: \033[0m";
    std::getline(in >> std::ws, contenido);

    pasos.clear();
    int numPasos = 0;
    do
    {
        std::cout << "\n\033[36m¿Cuantos pasos quieres agregar? [numero]: \033[0m";
        numPasos = solicitarNum();
    }
    while (numPasos == -1);
    std::cout << "\n\033[36mIntroduce un paso y presiona enter [texto]:\033[0m\n";
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
        std::cout << "\n\033[36m¿Cuantos tags quieres agregar? [numero]: \033[0m";
        numTags = solicitarNum();
    }
    while (numTags == -1);
    std::cout << "\n\033[36mIntroduce un tag y presiona enter [texto]:\033[0m\n";
    for (int i = 0; i < numTags; ++i)
    {
        std::string tag;
        in >> tag;
        tags.push_back(tag);
    }

    std::cout << "\n\033[36mRequisitos [texto]: \033[0m";
    std::getline(in >> std::ws, requisitos);

    do
    {
        std::cout << "\n\033[36mDificultad [numero]: \033[0m";
        valor = solicitarNum();
    }
    while (valor == -1);
    dificultad = valor;

    std::cout << "\n\033[36mHerramienta recomendada [texto]: \033[0m";
    std::getline(in >> std::ws, herramienta);
    do
    {
        std::cout << "\n\033[36mCalificacion [0-10]: \033[0m";
        valor = solicitarNum();
    }
    while (valor == -1);
    calificacion = valor;
}

void Manual::mostrar(std::ostream& out) const
{
    out << "\033[36m\n-----------| Manual |-----------\033[0m\n"
        << "\033[36mTitulo:\033[0m " << titulo << std::endl
        << "\033[36mAutor:\033[0m " << autor << std::endl
        << "\033[36mFecha:\033[0m " << fecha[0] << '/' << fecha[1] << '/' << fecha[2] << std::endl
        << "\033[36mContenido:\033[0m " << contenido << std::endl
        << "\033[36mRequisitos:\033[0m " << requisitos << std::endl
        << "\033[36mPasos:\033[0m ";

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
        << "\n\033[36mDificultad:\033[0m " << dificultad << std::endl
        << "\033[36mHerramienta:\033[0m " << herramienta << std::endl
        << "\033[36mCalificacion:\033[0m " << calificacion << std::endl;
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
