#include "Pagina.h"
#include "Utilidades.h"

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

Pagina& Pagina::operator+=(int value)
{
    calificacion = value;
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
    out << "\033[31m\n-----------| Advertencia: uso de Pagina (inadecuado) |-----------\033[0m\n"
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
        << "\033[36mCalificacion:\033[0m " << calificacion << std::endl;
}

void Pagina::guardar(std::istream& in)
{
    std::cout << "\n\033[31m-----------| Advertencia: uso de Pagina (inadecuado) |-----------\033[0m\n";
    std::cout << "\033[36mTitulo [texto]: \033[0m";
    std::getline(in >> std::ws, titulo);
    std::cout << "\033[36mAutor [texto]: \033[0m";
    std::getline(in >> std::ws, autor);

    int valor;
    // Leer dia
    do
    {
        std::cout << "\n\033[36mDia: \033[0m";
        valor = solicitarNum();
    }
    while (valor == -1);
    fecha[0] = valor;
    // Leer mes
    do
    {
        std::cout << "\n\033[36mMes: \033[0m";
        valor = solicitarNum();
    }
    while (valor == -1);
    fecha[1] = valor;
    // Leer año
    do
    {
        std::cout << "\n\033[36mAño: \033[0m";
        valor = solicitarNum();
    }
    while (valor == -1);
    fecha[2] = valor;

    std::cout << "\n\033[36mContenido [texto]: \033[0m";
    std::getline(in >> std::ws, contenido);
}


