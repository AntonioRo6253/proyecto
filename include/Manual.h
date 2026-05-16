#ifndef MANUAL_H
#define MANUAL_H
#include "Pagina.h"
#include <vector>
#include <string>


class Manual : public Pagina
{
public:
    Manual();
    void guardar(std::istream& in) override;
    void mostrar(std::ostream& out) const override;
    int getDificultad();
    void setDificultad(int d);
    std::string getHerramienta();
    void setHerramienta(std::string h);
    std::vector<std::string> getPasos();
    void setPasos(std::vector<std::string> p);
    std::string getRequisitos();
    void setRequisitos(std::string r);
private:
    std::vector<std::string> pasos;
    std::string requisitos;
    int dificultad;
    std::string herramienta;
};

#endif // MANUAL_H
