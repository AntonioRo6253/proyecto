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
"──────────────────────────────────────────────"
"\033[34m"
                  R"(

            ╷ ╷╷╷╭ ╷   ╶┬╴╭─╴╭─╮╭┬╮
            │╷││├┴╮│╶─╴ │ ├╴ ├┬╯│││
            ╰┴╯╵╵ ╵╵    ╵ ╰─╴╵╰╴╵ ╵)"
"\033[0m"
                  R"(
            -----------------------
            Seleccione una opcion
                 1. Buscar
                 2. TopList
                 3. Añadir
                 4. Eliminar
                 5. Todos los registros
                 6. Salir

──────────────────────────────────────────────
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

    std::cout << "\n\033[36m        Buscar:\033[0m ";
    std::getline(std::cin >> std::ws, busqueda);
    std::cout << "\nQue tipo de registro?\n     1 \033[31m[Articulo]\033[0m\n     2 \033[32m[Manual]\033[0m\n└─────────> ";
    int num = solicitarNum();

    switch (num)
    {
    case 1:
    {
        if (datos_articulo.empty())
        {
            std::cout << "\033[33mNo hay Articulos.\033[0m\n";
            break;
        }
        for(Articulo a : datos_articulo)
        {
            if(a == busqueda) // Sobrecarga de operador == para comparar con string
            {
                std::cout << "\033[32mRegistro encontrado\033[0m" << a;
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
            std::cout << "\033[33mNo hay Manuales.\033[0m\n";
            break;
        }
        for(Manual m : datos_manual)
        {
            if(m == busqueda) // Sobrecarga de operador == para comparar con string
            {
                std::cout << "\033[32mRegistro encontrado\033[0m" << m;
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
        std::cout << "\033[31mOpcion no valida\033[0m\n";
    }

    if (!encontrado) std::cout << "\033[33mNo se ha encontrado ninguna coincidencia\033[0m\n";
    pausarTerminal();
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

────────────────────────────────────────────
Seleccionar: )";
    int num = solicitarNum();
    switch(num)
    {
    case 1:
        if (mejor)
            std::cout << "\033[36mMas alta calificacion:\033[0m\n" << *mejor;
        else
            std::cout << "\033[33mNo hay registros.\033[0m\n";
        break;
    case 2:
        if (peor)
            std::cout << "\033[36mMas baja calificacion:\033[0m\n" << *peor;
        else
            std::cout << "\033[33mNo hay registros.\033[0m\n";
        break;
    default:
        std::cout << "\033[36mSaliendo...\033[0m\n";
        break;
    }

    if (mejor && peor && *mejor != *peor) // Sobrecarga de operador != para comparar Paginas
        std::cout << "\n\033[36mHay registros distintos de mayor y peor calificacion.\033[0m\n";
    pausarTerminal();
}

void App::anadir()
{
    limpiarTerminal();
    mostrarTitulo("Añadir");
    bool agregado = false;

    std::cout << "\nQue quieres añadir?\n     1 \033[31m[Articulo]\033[0m\n     2 \033[32m[Manual]\033[0m\n└─────────> ";
    int num = solicitarNum();
    switch (num)
    {
    case 1:
    {
        Articulo registro;
        std::cin >> registro;
        registro += "Articulo"; // Sobrecarga de operador += para añadir el tag "Articulo"
        datos_articulo.push_back(registro);
        agregado = true;
        break;
    }
    case 2:
    {
        Manual registro;
        std::cin >> registro;
        registro += "Manual"; // Sobrecarga de operador += para añadir el tag "Manual"
        datos_manual.push_back(registro);
        agregado = true;
        break;
    }
    default:
        std::cout << "\033[31mOpción no valida\033[0m\n";
    }
    if (agregado)
        std::cout << "\n\033[32mElemento añadido exitosamente!\033[0m\n";
    pausarTerminal();
}
void App::eliminar()
{
    limpiarTerminal();
    mostrarTitulo("Eliminar");

    std::cout << "\nQue quieres eliminar?\n     1 \033[31m[Articulo]\033[0m\n     2 \033[32m[Manual]\033[0m\n└─────────> ";
    int num = solicitarNum();
    switch (num)
    {
    case 1:
    {
        if (datos_articulo.empty())
        {
            std::cout << "\033[33mNo hay articulos.\033[0m\n";
            break;
        }
        std::cout << "\n\033[36mArticulos\033[0m\n";
        for (size_t i = 0; i < datos_articulo.size(); ++i)
            std::cout << "\033[36m" << (i+1) << ".\033[0m " << datos_articulo[i].titulo << "\n";

        std::cout << "\033[36mElige uno: \033[0m";
        int seleccion = solicitarNum();
        if (seleccion >= 1 && seleccion <= datos_articulo.size())
        {
            std::cout << "\033[31mSeguro que quieres eliminar \033[0m" << datos_articulo[seleccion - 1].titulo << " \033[31m[y/n]: \033[0m";
            std::string confirm;
            std::cin >> confirm;
            if(confirm == "y") {
                datos_articulo.erase(datos_articulo.begin() + (seleccion - 1));
                std::cout << "\n\033[32mElemento Eliminado exitosamente!\033[0m\n";
            }
        }
        else
            std::cout << "\033[31mOpcion no valida\033[0m\n";
        break;
    }
    case 2:
    {
        if (datos_manual.empty())
        {
            std::cout << "\033[33mNo hay manuales.\033[0m\n";
            break;
        }
        std::cout << "\n\033[36mManuales\033[0m\n";
        for (size_t i = 0; i < datos_manual.size(); ++i)
            std::cout << "\033[36m" << (i+1) << ".\033[0m " << datos_manual[i].titulo << "\n";

        std::cout << "\033[36mElige uno: \033[0m";
        int seleccion = solicitarNum();
        if (seleccion >= 1 && static_cast<size_t>(seleccion) <= datos_manual.size())
        {
            std::cout << "\033[31mSeguro que quieres eliminar \033[0m" << datos_manual[seleccion - 1].titulo << " \033[31m[y/n]: \033[0m";
            std::string confirm;
            std::cin >> confirm;
            if(confirm == "y"){
                datos_manual.erase(datos_manual.begin() + (seleccion - 1));
                 std::cout << "\n\033[32mElemento Eliminado exitosamente!\033[0m\n";
            }
        }
        else
            std::cout << "\033[31mOpcion no valida\033[0m\n";
        break;
    }
    default:
        std::cout << "\033[31mOpcion no valida\033[0m\n";
    }
    pausarTerminal();
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
        std::cout << "\033[33mNo hay registros.\033[0m\n\n";
        pausarTerminal();
        return;
    }

    for (size_t i = 0; i < combinado.size(); i++)
    {
        std::cout << "\033[36m" << i + 1 << ".\033[0m \n" << *registros[i];
    }

    pausarTerminal();
}
