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
    std::cout << "Presione ENTER para continuar...";
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
    std::cout << linea << "\n" << std::string(margen, ' ') << texto << "\n" << linea << "\n";
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
        std::cerr << std::endl << "Error inesperado: " << err.what() << " No es un numero valido se esperaba uno de estos numeros [1, 2, 3, 4]" << std::endl;
        pausarTerminal();
        return -1;
    }
}


