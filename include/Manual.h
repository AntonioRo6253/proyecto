#ifndef MANUAL_H
#define MANUAL_H
#include "Pagina.h"
#include <vector>


class Manual : public Pagina
{
public:
    Manual() = default;
    std::vector<std::string> pasos;
    std::string requisitos;
    void guardar(std::istream& in) override;
    void mostrar(std::ostream& out) const override;
};

#endif // MANUAL_H
