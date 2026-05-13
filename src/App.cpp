#include "App.h"
#include <iostream>
#include <vector> // Para std::vector
#include "Articulo.h"

void App::setEntrada(int entrada)
{
    this->entrada = entrada;
}

int App::getEntrada()
{
    return entrada;
}

void App::iniciar()
{
    do
    {
        limpiarTerminal();
        std::cout <<
                  R"(
──────────────────────────────────────
                wiki
        Seleccione una opcion
             1. Buscar
             2. TopList
             3. añadir
             4. eliminar
             5. Salir
──────────────────────────────────────
Seleccionar: )";
        entrada = solicitarNum();
        switch(entrada)
        {
        case 1:
            buscar();
            break;
        case 2:
            topList();
            break;
        case 3:
            anadir();
            break;
        case 4:
            eliminar();
            break;
        }
        limpiarTerminal();
    }
    while(entrada != 5);
}

void App::buscar()
{
    std::string text;
    mostrarTitulo("Buscar");
    std::cout << "\n\nBuscar: ";

    std::cin >> text;
    Articulo aux;
    std::cout << aux;
}
void App::topList()
{
    limpiarTerminal();

    system("pause");
}

void App::anadir()
{
    limpiarTerminal();
    mostrarTitulo("Añadir");
    std::cout << "Que quieres añadir?\n1 [Articulo]\n2 [Manual]\n";
    int num = solicitarNum();
    switch (num)
    {
    case 1:
    {
        Articulo registro;
        std::cin >> registro;
        datos_articulo.push_back(registro);
        break;
    }
    case 2:
    {
        Manual registro;
        // std::cin >> registro;
        // datos_manual.push_back(registro);
        break;
    }
    default:
        std::cout << "Opción no válida\n";
    }
    std::cout << "\nElemento añadido exitosamente!\n";
    system("pause");
}
void App::eliminar()
{
    limpiarTerminal();
    mostrarTitulo("Eliminar");
    std::cout << "Que quieres eliminar?\n1 [Articulo]\n2 [Manual]\n";
    int num = solicitarNum();
    switch (num)
    {
    case 1:
    {
        if (datos_articulo.empty())
        {
            std::cout << "No hay artículos.\n";
            break;
        }
        std::cout << "\nArtículos\n";
        for (size_t i = 0; i < datos_articulo.size(); ++i)
            std::cout << (i+1) << ". " << datos_articulo[i].titulo << "\n";
        std::cout << "Elige uno: ";
        int seleccion = solicitarNum();
        if (seleccion >= 1 && seleccion <= datos_articulo.size())
        {
            std::cout << "Seguro que quieres eliminar " << datos_articulo[seleccion - 1].titulo << " [y/n]: ";
            std::string confirm;
            std::cin >> confirm;
            if(confirm == "y")
                datos_articulo.erase(datos_articulo.begin() + (seleccion - 1));
            else
                break;
        }
        else
            std::cout << "Selección inválida\n";
        break;
    }
    case 2:
    {
        if (datos_manual.empty())
        {
            std::cout << "No hay manuales.\n";
            break;
        }
        std::cout << "\nManuales\n";
        for (size_t i = 0; i < datos_manual.size(); ++i)
            std::cout << (i+1) << ". " << datos_manual[i].titulo << "\n";
        std::cout << "Elige uno: ";
        int seleccion = solicitarNum();
        if (seleccion >= 1 && seleccion <= datos_manual.size())
        {
            std::cout << "Seguro que quieres eliminar " << datos_articulo[seleccion - 1].titulo << " [y/n]: ";
            std::string confirm;
            std::cin >> confirm;
            if(confirm == "y")
                datos_manual.erase(datos_manual.begin() + (seleccion - 1));
            else
                break;
        }
        else
            std::cout << "Selección inválida\n";
        break;
    }
    default:
        std::cout << "Opción no válida\n";
    }
    system("pause");
}
