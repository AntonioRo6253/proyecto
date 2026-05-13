#ifndef ARTICULO_H
#define ARTICULO_H
#include "Pagina.h"
#include <string>
#include <vector>
#include <iostream>

class Articulo : public Pagina
{
public:
    Articulo();
    friend std::istream& operator>>(std::istream& in, Articulo& art);
    friend std::ostream& operator<<(std::ostream& out, const Articulo& art);
};

#endif // ARTICULO_H
