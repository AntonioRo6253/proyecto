#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include "App.h"

int main()
{

#ifdef _WIN32  // Configurar la consola para usar: UTF-8 [ CP_UTF8 ] | Windows-1252 [ 1253 ]
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    App programa;
    programa.iniciar();

    return 0;
}
