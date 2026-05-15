#include "Pagina.h"

Pagina::Pagina()
{
    titulo = " ";
    autor = " ";
    fecha[0] = 0;
    fecha[1] = 0;
    fecha[2] = 0;
    contenido = " ";
    calificacion = 0;
}

bool Pagina::operator==(std::string busqueda)
{
    return titulo == busqueda;
}

bool Pagina::operator!=(std::string busqueda)
{
    return !(*this == busqueda);
}

bool Pagina::operator==(Pagina otra)
{
    return titulo == otra.titulo && calificacion == otra.calificacion;
}

bool Pagina::operator!=(Pagina otra)
{
    return !(*this == otra);
}

bool Pagina::operator<(Pagina otra)
{
    if (calificacion != otra.calificacion)
        return calificacion < otra.calificacion;
    return titulo < otra.titulo;
}

bool Pagina::operator>(Pagina otra)
{
    return otra < *this;
}

Pagina& Pagina::operator+=(std::string tag)
{
    if (!tag.empty())
        tags.push_back(tag);
    return *this;
}

Pagina& Pagina::operator++()
{
    ++calificacion;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Pagina& p)
{
    p.mostrar(out);
    return out;
}

std::istream& operator>>(std::istream& in, Pagina& p)
{
    p.guardar(in);
    return in;
}

void Pagina::mostrar(std::ostream& out) const
{
    out << "\n-----------| Advertencia estas usando class Pagina inadecuadamente |-----------\n"
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

void Pagina::guardar(std::istream& in)
{
    std::cout << "\n-----------| Advertencia estas usando class Pagina inadecuadamente |-----------\n";
    in >> titulo;
    in >> autor;
    in >> fecha[0] >> fecha[1] >> fecha[2];
    in >> contenido;
}


