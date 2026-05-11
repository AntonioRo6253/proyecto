#ifndef PAGINA_H
#define PAGINA_H

#include <string>
#include <vector>

class Pagina
{
public:
    Pagina() = default;
    std::string titulo;
    std::string autor;
    std::string fecha;
    std::string contenido;
    std::vector<std::string> tags;
    int calificacion = 0;

private:
    // Pagina actúa solo como contenedor de datos base.
};

#endif // PAGINA_H
