#include "Console.h"
#include <stdlib.h> // system()

void Console::limpiarTerminal()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux y MacOs
#endif
};
