#ifndef APP_H
#define APP_H
#include "Utilidades.h"
#include <vector>
#include "Pagina.h"
#include "Articulo.h"
#include "Manual.h"


class App : private Utilidades
{
public:
    App() = default;
    void setEntrada(int entrada);
    int getEntrada();
    void iniciar();


private:
    std::vector<Articulo> datos_articulo;
    std::vector<Manual> datos_manual;
    int entrada;
    void buscar();
    void topList();
    void anadir();
    void eliminar();
};

#endif // MENU_H
