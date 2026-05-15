#include "App.h"
#include <iostream>
#include <vector>
#include <string>
#include "Articulo.h"

App::App()
{
    entrada = 0;
}

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
             3. Añadir
             4. Eliminar
             5. Todos los registros
             6. Salir
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
        case 5:
            mostrarTodoRegistro();
            break;
        }
        limpiarTerminal();
    }
    while(entrada != 6);
}

void App::buscar()
{
    std::string busqueda;
    bool encontrado = false;

    limpiarTerminal();
    mostrarTitulo("Buscar");

    std::cout << "\n\nBuscar: ";
    std::getline(std::cin >> std::ws, busqueda);
    std::cout << "Que tipo de registro?\n1 [Articulo]\n2 [Manual]\n";
    int num = solicitarNum();

    switch (num)
    {
    case 1:
    {
        if (datos_articulo.empty())
        {
            std::cout << "No hay Articulos.\n";
            break;
        }
        for(Articulo a : datos_articulo)
        {
            if(a == busqueda) // Sobrecarga de operador == para comparar con string
            {
                std::cout << "Registro encontrado" << a;
                encontrado = true;
            }
            else if (a != busqueda) // Sobrecarga de operador != para comparar con string
            {
                continue;
            }
        }
        break;
    }
    case 2:
    {
        if (datos_manual.empty())
        {
            std::cout << "No hay Manuales.\n";
            break;
        }
        for(Manual m : datos_manual)
        {
            if(m == busqueda) // Sobrecarga de operador == para comparar con string
            {
                std::cout << "Registro encontrado" << m;
                encontrado = true;
            }
            else if (m != busqueda) // Sobrecarga de operador != para comparar con string
            {
                continue;
            }
        }
        break;
    }
    default:
        std::cout << "Opcion no valida\n";
    }

    if (!encontrado) std::cout << "No se ha encontrado ninuna coincidencia\n";
    system("pause");
}
void App::topList()
{
    Pagina* mejor = nullptr;
    Pagina* peor = nullptr;


    for (Articulo& a : datos_articulo)
    {
        if (!mejor || a > *mejor)
            mejor = &a;
        if (!peor || a < *peor)
            peor = &a;
    }

    for (Manual& m : datos_manual)
    {
        if (!mejor || m > *mejor)
            mejor = &m;
        if (!peor || m < *peor)
            peor = &m;
    }

    limpiarTerminal();
    mostrarTitulo("Top List");

    std::cout <<
              R"(
        Seleccione una opcion
             1. popular
             2. menos popular
             3. Salir
──────────────────────────────────────
Seleccionar: )";
    int num = solicitarNum();
    switch(num)
    {
    case 1:
        if (mejor)
            std::cout << "Mas alta calificacion:\n" << *mejor;
        else
            std::cout << "No hay registros.\n";
        break;
    case 2:
        if (peor)
            std::cout << "Mas baja calificacion:\n" << *peor;
        else
            std::cout << "No hay registros.\n";
        break;
    default:
        std::cout << "Saliendo... .\n";
        break;
    }

    if (mejor && peor && *mejor != *peor) // Sobrecarga de operador != para comparar Paginas
        std::cout << "\nHay registros distintos de mayor y peor calificacion.\n";
    system("pause");
}

void App::anadir()
{
    limpiarTerminal();
    mostrarTitulo("Añadir");
    bool agregado = false;

    std::cout << "Que quieres añadir?\n1 [Articulo]\n2 [Manual]\n";
    int num = solicitarNum();
    switch (num)
    {
    case 1:
    {
        Articulo registro;
        std::cin >> registro;
        registro += "Articulo"; // Sobrecarga de operador += para añadir el tag "Articulo"
        ++registro; // Sobrecarga de operador ++ para incrementar la calificacion
        datos_articulo.push_back(registro);
        agregado = true;
        break;
    }
    case 2:
    {
        Manual registro;
        std::cin >> registro;
        registro += "Manual"; // Sobrecarga de operador += para añadir el tag "Manual"
        ++registro; // Sobrecarga de operador ++ para incrementar la calificacion
        datos_manual.push_back(registro);
        agregado = true;
        break;
    }
    default:
        std::cout << "Opción no valida\n";
    }
    if (agregado)
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
            std::cout << "No hay articulos.\n";
            break;
        }
        std::cout << "\nArticulos\n";
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
        }
        else
            std::cout << "Opcion no valida\n";
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
        if (seleccion >= 1 && static_cast<size_t>(seleccion) <= datos_manual.size())
        {
            std::cout << "Seguro que quieres eliminar " << datos_manual[seleccion - 1].titulo << " [y/n]: ";
            std::string confirm;
            std::cin >> confirm;
            if(confirm == "y")
                datos_manual.erase(datos_manual.begin() + (seleccion - 1));
        }
        else
            std::cout << "Opcion no valida\n";
        break;
    }
    default:
        std::cout << "Opcion no valida\n";
    }
    system("pause");
}
void App::mostrarTodoRegistro()
{
    limpiarTerminal();
    mostrarTitulo("Todos los registros");

    std::vector<Pagina*> combinado;
    combinado.reserve(datos_articulo.size() + datos_manual.size()); // Reservar espacio para evitar reallocations

    for (Articulo& a : datos_articulo) combinado.push_back(&a);
    for (Manual& m : datos_manual)   combinado.push_back(&m);
    Pagina** registros = combinado.data();  // crear ptr** para tener apuntador de punteros a clase 

    if (combinado.empty())
    {
        std::cout << "No hay registros.\n\n";
        system("pause");
        return;
    }

    for (size_t i = 0; i < combinado.size(); i++)
    {
        std::cout << i + 1 << ". \n" << *registros[i];
    }

    system("pause");
}
