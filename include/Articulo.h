#ifndef ARTICULO_H
#define ARTICULO_H
#include <iostream>
#include <string>
#include "Pagina.h"

class Articulo : public Pagina
{
public:
    Articulo();
    void mostrar(std::ostream& out) const override;
    void guardar(std::istream& in) override;
    int getVisitas();
    void setVisitas(int v);
    std::string getResumen();
    void setResumen(std::string r);
private:
    int visitas;
    std::string resumen;
};
#endif // ARTICULO_H
