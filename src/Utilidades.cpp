#include "Utilidades.h"
#include <cctype> // isalpha()

bool Utilidades::isTexto(std::string texto)
{
    for (size_t i = 0; i < texto.length(); i++)
        if (!isalpha(texto[i])) return false;
    return true;
}
