#ifndef APP_H
#define APP_H
#include <vector>
#include "Utilidades.h"
#include "Pagina.h"
#include "Articulo.h"
#include "Manual.h"


class App : private Utilidades
{
public:
    App();
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
    void mostrarTodoRegistro();
};

#endif // MENU_H
