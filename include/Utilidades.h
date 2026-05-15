#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <string>


class Utilidades
{
protected:
    bool isTexto(std::string texto);
    void limpiarTerminal();
    void pausarTerminal();
    void mostrarTitulo(std::string texto);
    int solicitarNum();
};

#endif // UTILIDADES_H
