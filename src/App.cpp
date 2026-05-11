#include "App.h"
#include <iostream>
#include <stdexcept> // exception, invalid_argument, out_of_range
#include <windows.h>
#include <fstream> // Para lectura/escritura de archivos
#include <vector> // Para std::vector
#include <algorithm> // Para std::sort
#include <sstream> // Para std::istringstream
#include "Articulo.h"


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
                wiki
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
void App::buscar() {
    std::string text;
    std::cout << R"(
----------------------------------------
		SEARCH
----------------------------------------

      Buscar:
)";

std::cin >> text;
Articulo aux;
    aux = aux.buscarTXT(text);
    std::cout << aux;
};
void App::topList() {
    limpiarTerminal();
    std::vector<Articulo> top_list;
    std::ifstream archivo("datos.txt");
    
    if (archivo.is_open()) {
        std::string tipo;
        while (std::getline(archivo, tipo)) {
            if (tipo == "1") { // 1 = Articulo
                Articulo art;
                std::getline(archivo, art.titulo);
                std::getline(archivo, art.autor);
                std::getline(archivo, art.fecha);
                std::getline(archivo, art.contenido);
                std::string tags_str;
                std::getline(archivo, tags_str);
                archivo >> art.calificacion;
                archivo.ignore(); // Limpiar el buffer
                
                top_list.push_back(art);
            }
        }
        archivo.close();
    }
    
    // Ordenar por calificación (mayor a menor)
    std::sort(top_list.begin(), top_list.end(), 
        [](const Articulo& a, const Articulo& b) {
            return a.calificacion > b.calificacion;
        });
    
    std::cout << R"(
----------------------------------------
           TOP ARTÍCULOS
----------------------------------------
)";
    
    if (top_list.empty()) {
        std::cout << "No hay articulos disponibles." << std::endl;
    } else {
        for (size_t i = 0; i < top_list.size() && i < 10; ++i) {
            std::cout << (i + 1) << ". " << top_list[i].titulo 
                      << " - Calificacion: " << top_list[i].calificacion << std::endl;
        }
    }
    
    std::cout << "\nPresione enter para continuar...";
    std::cin.ignore();
    system("pause");
};

void App::anadir() {
    limpiarTerminal();
    std::cout << R"(
----------------------------------------
           AÑADIR ARTÍCULO
----------------------------------------
)";
    
    Articulo nuevo;
    std::cout << "\nTitulo: ";
    std::cin.ignore();
    std::getline(std::cin, nuevo.titulo);
    
    std::cout << "Autor: ";
    std::getline(std::cin, nuevo.autor);
    
    std::cout << "Fecha (DD/MM/YYYY): ";
    std::getline(std::cin, nuevo.fecha);
    
    std::cout << "Contenido: ";
    std::getline(std::cin, nuevo.contenido);
    
    std::cout << "Calificacion (1-5): ";
    std::cin >> nuevo.calificacion;
    
    std::cout << "Tags (separados por coma, deje en blanco para omitir): ";
    std::cin.ignore();
    std::string tags_input;
    std::getline(std::cin, tags_input);
    
    // Procesar tags si los hay
    if (!tags_input.empty()) {
        std::istringstream ss(tags_input);
        std::string tag;
        while (std::getline(ss, tag, ',')) {
            // Limpiar espacios en blanco
            tag.erase(0, tag.find_first_not_of(" "));
            tag.erase(tag.find_last_not_of(" ") + 1);
            if (!tag.empty()) {
                nuevo.tags.push_back(tag);
            }
        }
    }
    
    // Guardar el artículo
    nuevo.guardarTXT();
    
    std::cout << "\nArticulo añadido exitosamente!" << std::endl;
    system("pause");
};
