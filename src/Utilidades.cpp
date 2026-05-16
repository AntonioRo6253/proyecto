#include "Utilidades.h"
#include <iostream>
#include <string>
#include <cctype> // isalpha()
#include <stdlib.h> // system()
#include <stdexcept> // exception, invalid_argument, out_of_range
#include <limits> // numeric_limits


bool Utilidades::isTexto(std::string texto)
{
    for (size_t i = 0; i < texto.length(); i++)
        if (!isalpha(texto[i])) return false;
    return true;
}

void Utilidades::limpiarTerminal()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux y MacOs
#endif
}

void Utilidades::pausarTerminal()
{
#ifdef _WIN32
    system("pause"); // Windows
#else
    std::cout << "\033[36mPresione ENTER para continuar...\033[0m";
    std::cin.clear(); // limpiar el estado de error
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // eliminar resto de la línea anterior
    std::string tmp;
    std::getline(std::cin, tmp); // espera el ENTER del usuario
#endif
}

void Utilidades::mostrarTitulo(std::string texto)
{
    int margen = 18;
    std::string linea(texto.length() + (margen * 2), '-'); // Crear borde del titulo
    std::cout << "\033[34m" << linea << "\033[0m\n"
              << std::string(margen, ' ') << "\033[36m" << texto << "\033[0m\n"
              << "\033[34m" << linea << "\033[0m\n";
}

int Utilidades::solicitarNum()
{
    try
    {
        int num;
        if(!(std::cin >> num))
            throw std::runtime_error("Fallo al obtener la seleccion,");
        return num;
    }
    catch (const std::exception& err)
    {
#ifdef _WIN32
        std::string tmp;
        std::cin.clear();     // Limpiar el estado de error
        std::getline(std::cin, tmp); // descartar todo hasta el '\n'
#endif
        std::cerr << std::endl << "\033[31mError inesperado: " << err.what() << "\033[0m"
              << " " << "\033[33mNo es un numero valido. Se esperaba uno de estos numeros [1, 2, 3, 4]\033[0m" << std::endl;
        pausarTerminal();
        return -1;
    }
}


