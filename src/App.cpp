#include "App.h"
#include <iostream>
#include <stdexcept> // exception, invalid_argument, out_of_range
#include <windows.h>


void App::iniciar()
{
    menu();
}
void App::menu()
{
    do
    {
        limpiarTerminal();
        std::cout <<
                  R"(
──────────────────────────────────────
           Citas Farmacia
        Seleccione una opcion
             1. Buscar
             2. TopList
             3. añadir
             4. Salir
──────────────────────────────────────
Seleccionar: )";
        try
        {
            if(!(std::cin >> entrada))
                throw std::runtime_error("Fallo al obtener la seleccion, [ ");
        }
        catch (const std::exception& err)
        {
            std::string basura;
            std::cin.clear();     // Limpiar el estado de error
            std::getline(std::cin, basura); // descartar todo hasta el '\n'
            std::cerr << std::endl << "Error inesperado: " << err.what() << basura  << " ] No es un numero valido se esperaba uno de estos numeros [1, 2, 3, 4]" << std::endl;
            system("pause");
        }
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
        }
        limpiarTerminal();
    }
    while(entrada != 4);
}
void App::setEntrada(int entrada)
{
    this->entrada = entrada;
};
int App::getEntrada()
{
    return entrada;
};
void App::buscar() {};
void App::topList() {};
void App::anadir() {};
