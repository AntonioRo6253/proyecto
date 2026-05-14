#ifndef ARTICULO_H
#define ARTICULO_H
#include <iostream>
#include "Pagina.h"

class Articulo : public Pagina
{
public:
    Articulo() = default;
    void mostrar(std::ostream& out) const override;
    void guardar(std::istream& in) override;
};

#endif // ARTICULO_H
