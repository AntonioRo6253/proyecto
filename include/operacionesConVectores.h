#ifndef OPERACIONESCONVECTORES_H
#define OPERACIONESCONVECTORES_H
#include <string>
#include <vector>

#include "Articulo.h"

std::vector<Articulo> operator==(const std::vector<Articulo>& listObj, int anio);
std::vector<Articulo> operator>(const std::vector<Articulo>& listObj, int anio);
std::vector<Articulo> operator<(const std::vector<Articulo>& listObj, int anio);
Articulo articuloMasReciente(const std::vector<Articulo>& listObj, const std::string& text);


#endif // OPERACIONESCONVECTORES_H
