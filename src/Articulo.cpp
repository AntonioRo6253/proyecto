#include "Articulo.h"
    #include <iostream>
#include <fstream> // Librería necesaria para manejo de archivos
#include <string>
#include <sstream>
#include <algorithm>
#include "Articulo.h"

Articulo::Articulo()
{
    //ctor
}
void Articulo::guardarTXT() {

    // 1. Crear el objeto de flujo de salida (ofstream)
    std::ofstream archivo("datos.txt");

    // 2. Verificar si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // 3. Escribir texto en el archivo
        archivo << 1 << std::endl; // 1 articulo 2 manual
        archivo << titulo << std::endl;
        archivo << autor  << std::endl;
        archivo << fecha  << std::endl;
        archivo << contenido  << std::endl;
        // Serializar tags como lista separada por comas
        std::ostringstream tags_ss;
        for (size_t i = 0; i < tags.size(); ++i) {
            if (i) tags_ss << ",";
            tags_ss << tags[i];
        }
        archivo << tags_ss.str() << std::endl;
        archivo << calificacion << std::endl << std::endl;

        // 4. Cerrar el archivo (buena práctica)
        archivo.close();
        std::cout << "Archivo guardado con exito." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }
}
Articulo Articulo::buscarTXT(const std::string& text) {
    std::ifstream archivoLectura("datos.txt");
    Articulo aux;

    if (!archivoLectura.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para lectura." << std::endl;
        return aux;
    }

    std::string tipo;
    bool encontrado = false;

    while (std::getline(archivoLectura, tipo)) {
        if (tipo != "1") {
            continue;
        }

        Articulo actual;
        std::getline(archivoLectura, actual.titulo);
        std::getline(archivoLectura, actual.autor);
        std::getline(archivoLectura, actual.fecha);
        std::getline(archivoLectura, actual.contenido);

        std::string tags_line;
        std::getline(archivoLectura, tags_line);
        actual.tags.clear();
        std::istringstream tss(tags_line);
        std::string tag;
        while (std::getline(tss, tag, ',')) {
            if (!tag.empty()) {
                actual.tags.push_back(tag);
            }
        }

        std::string calif_line;
        if (std::getline(archivoLectura, calif_line)) {
            try {
                actual.calificacion = std::stoi(calif_line);
            } catch (...) {
                actual.calificacion = 0;
            }
        }

        std::string separador;
        std::getline(archivoLectura, separador);

        if (actual.titulo.find(text) != std::string::npos ||
            actual.autor.find(text) != std::string::npos ||
            actual.fecha.find(text) != std::string::npos ||
            actual.contenido.find(text) != std::string::npos) {
            aux = actual;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontró el registro." << std::endl;
    }

    return aux;
}

// Operador de salida global
std::ostream& operator<<(std::ostream& out, const Articulo& obj){
    out << "\n-----------| Articulo |-----------\n"
        << "Titulo: " << obj.titulo << std::endl
        << "Autor: " << obj.autor << std::endl
        << "Fecha: " << obj.fecha << std::endl
        << "Contenido: " << obj.contenido << std::endl
        << "Tags: ";

    for (size_t i = 0; i < obj.tags.size(); ++i) {
        if (i) out << ", ";
        out << obj.tags[i];
    }

    out << std::endl
        << "Calificacion: " << obj.calificacion << std::endl;
    return out;
}
