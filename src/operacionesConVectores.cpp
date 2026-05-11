#include "operacionesConVectores.h"

#include <cctype>

namespace
{
	std::vector<int> separarPartesFecha(const std::string& fecha)
	{
		std::vector<int> partes;
		std::string numeroActual;

		for (char caracter : fecha) {
			if (std::isdigit(static_cast<unsigned char>(caracter))) {
				numeroActual.push_back(caracter);
			} else if (!numeroActual.empty()) {
				partes.push_back(std::stoi(numeroActual));
				numeroActual.clear();
			}
		}

		if (!numeroActual.empty()) {
			partes.push_back(std::stoi(numeroActual));
		}

		return partes;
	}

	int extraerAnio(const std::string& fecha)
	{
		const std::vector<int> partes = separarPartesFecha(fecha);

		if (partes.empty()) {
			return 0;
		}

		if (partes.size() >= 3) {
			if (partes[0] > 31) {
				return partes[0];
			}

			return partes[2];
		}

		return partes.back();
	}

	long long fechaComparable(const std::string& fecha)
	{
		const std::vector<int> partes = separarPartesFecha(fecha);

		if (partes.empty()) {
			return 0;
		}

		int anio = 0;
		int mes = 0;
		int dia = 0;

		if (partes.size() >= 3) {
			if (partes[0] > 31) {
				anio = partes[0];
				mes = partes[1];
				dia = partes[2];
			} else {
				dia = partes[0];
				mes = partes[1];
				anio = partes[2];
			}
		} else if (partes.size() == 2) {
			anio = partes[0];
			mes = partes[1];
		} else {
			anio = partes[0];
		}

		return static_cast<long long>(anio) * 10000LL + static_cast<long long>(mes) * 100LL + dia;
	}
}

std::vector<Articulo> operator==(const std::vector<Articulo>& listObj, int anio)
{
	std::vector<Articulo> resultado;

	for (const Articulo& articulo : listObj) {
		if (extraerAnio(articulo.fecha) == anio) {
			resultado.push_back(articulo);
		}
	}

	return resultado;
}

std::vector<Articulo> operator>(const std::vector<Articulo>& listObj, int anio)
{
	std::vector<Articulo> resultado;

	for (const Articulo& articulo : listObj) {
		if (extraerAnio(articulo.fecha) > anio) {
			resultado.push_back(articulo);
		}
	}

	return resultado;
}

std::vector<Articulo> operator<(const std::vector<Articulo>& listObj, int anio)
{
	std::vector<Articulo> resultado;

	for (const Articulo& articulo : listObj) {
		if (extraerAnio(articulo.fecha) < anio) {
			resultado.push_back(articulo);
		}
	}

	return resultado;
}

Articulo articuloMasReciente(const std::vector<Articulo>& listObj, const std::string& text)
{
	(void)text;

	if (listObj.empty()) {
		return Articulo();
	}

	Articulo masReciente = listObj.front();

	for (const Articulo& articulo : listObj) {
		if (fechaComparable(articulo.fecha) > fechaComparable(masReciente.fecha)) {
			masReciente = articulo;
		}
	}

	return masReciente;
}
