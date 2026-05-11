#ifndef ARTICULO_H
#define ARTICULO_H

#include "Pagina.h"
#include <string>
#include <vector>
#include <ostream>

class Articulo : public Pagina
{
public:
    Articulo();
    void guardarTXT();
    Articulo buscarTXT(const std::string& text);

    // Operador de salida como función amiga
    friend std::ostream& operator<<(std::ostream& out, const Articulo& obj);
};

#endif // ARTICULO_H
