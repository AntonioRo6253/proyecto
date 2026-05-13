#ifndef MANUAL_H
#define MANUAL_H
#include "Pagina.h"
#include <vector>


class Manual : public Pagina
{
public:
    Manual();
    std::vector<std::string> pasos;
    std::string requisitos;
};

#endif // MANUAL_H
