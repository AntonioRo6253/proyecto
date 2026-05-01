#include <iostream>
#include "App.h"
#include <windows.h>

int main()
{
    // Configurar la consola para usar: UTF-8 [ CP_UTF8 ] | Windows-1252 [ 1253 ]
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    App programa;
    programa.iniciar();

    return 0;
}
