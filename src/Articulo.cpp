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
    std::cout << "\n\033[36mTitulo [texto]: \033[0m";
    /*
    El std::ws asegura que se ignoren los espacios en blanco antes de leer la línea
    evita que si escribimos un titulo con espacios, solo se lea la primera palabra y el resto se quede en el buffer
    */
    std::getline(in >> std::ws, titulo);
    std::cout << "\n\033[36mAutor [texto]: \033[0m";
    std::getline(in >> std::ws, autor);
    int valor;
    // Fecha: dia
    do {
        std::cout << "\n\033[36mDia [12]: \033[0m";
        valor = solicitarNum();
    } while (valor == -1);
    fecha[0] = valor;
    // mes
    do {
        std::cout << "\n\033[36mMes [02]: \033[0m";
        valor = solicitarNum();
    } while (valor == -1);
    fecha[1] = valor;
    // año
    do {
        std::cout << "\n\033[36mAño [2026]: \033[0m";
        valor = solicitarNum();
    } while (valor == -1);
    fecha[2] = valor;
    std::cout << "\n\033[36mContenido [texto]: \033[0m";
    std::getline(in >> std::ws, contenido);

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

    std::cout << "\n\033[35mTus tags son:\033[0m\n";
    for (std::string tag : tags)
    {
        std::cout << "\033[36m[" << tag << "]\033[0m ";
    }
    std::cout << std::endl;

    std::cout << "\n\033[36mResumen [texto]: \033[0m";
    std::getline(in >> std::ws, resumen);

    do {
        std::cout << "\n\033[36mVisitas [numero]: \033[0m";
        valor = solicitarNum();
    } while (valor == -1);
    visitas = valor;
    do {
        std::cout << "\n\033[36mCalificacion [0-10]: \033[0m";
        valor = solicitarNum();
    } while (valor == -1);
    calificacion = valor;
}

void Articulo::mostrar(std::ostream& out) const
{
    out << "\033[36m\n-----------| Articulo |-----------\033[0m\n"
        << "\033[36mTitulo:\033[0m " << titulo << std::endl
        << "\033[36mAutor:\033[0m " << autor << std::endl
        << "\033[36mFecha:\033[0m " << fecha[0] << '/' << fecha[1] << '/' << fecha[2] << std::endl
        << "\033[36mContenido:\033[0m " << contenido << std::endl
        << "\033[36mTags:\033[0m ";

    for (size_t i = 0; i < tags.size(); ++i)
    {
        if (i) out << ", ";
        out << tags[i];
    }

    out << std::endl
        << "\n\033[36mResumen:\033[0m " << resumen << std::endl
        << "\033[36mVisitas:\033[0m " << visitas << std::endl
        << "\033[36mCalificacion:\033[0m " << calificacion << std::endl;
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


