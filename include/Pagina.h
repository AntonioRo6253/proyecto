#ifndef PAGINA_H
#define PAGINA_H
#include <iostream>
#include <string>
#include <vector>


class Pagina
{
public:
    Pagina();
    std::string titulo;
    std::string autor;
    int calificacion;
    int fecha[3];
    std::string contenido;
    std::vector<std::string> tags;
    friend std::ostream& operator<<(std::ostream& out, const Pagina& p);
    friend std::istream& operator>>(std::istream& in, Pagina& p);
    bool operator==(const std::string& busqueda) const;
    bool operator!=(const std::string& busqueda) const;
    bool operator==(const Pagina& otra) const;
    bool operator!=(const Pagina& otra) const;
    bool operator<(const Pagina& otra) const;
    bool operator>(const Pagina& otra) const;
    Pagina& operator+=(const std::string& tag);
    Pagina& operator++();
    virtual void mostrar(std::ostream& out) const;
    virtual void guardar(std::istream& in);
};

std::ostream& operator<<(std::ostream& out, const Pagina& p);
std::istream& operator>>(std::istream& in, Pagina& p);

#endif // PAGINA_H
