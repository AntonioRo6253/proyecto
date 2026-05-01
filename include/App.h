#ifndef APP_H
#define APP_H
#include "Console.h"
#include "Utilidades.h"


class App : private Console, Utilidades
{
public:
    App() = default;
    void iniciar();
    void setEntrada(int entrada);
    int getEntrada();

private:
    int entrada;
    bool ventana_ocupada;
    void menu();
    void buscar();
    void topList();
    void anadir();
};

#endif // MENU_H
