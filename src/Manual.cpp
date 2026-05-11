#include "Manual.h"
#include <iostream>
#include <fstream>
#include <sstream>

Manual::Manual()
{
    //ctor
}

void Manual::guardarTXT() {

    std::ofstream archivo("datos.txt");

    if (archivo.is_open()) {
        archivo << 2 << std::endl; // 1 articulo 2 manual
        archivo << titulo << std::endl;
        archivo << autor  << std::endl;
        archivo << fecha  << std::endl;
        archivo << contenido  << std::endl;

        std::ostringstream tags_ss;
        for (size_t i = 0; i < tags.size(); ++i) {
            if (i) tags_ss << ",";
            tags_ss << tags[i];
        }
        archivo << tags_ss.str() << std::endl;

        std::ostringstream pasos_ss;
        for (size_t i = 0; i < pasos.size(); ++i) {
            if (i) pasos_ss << ",";
            pasos_ss << pasos[i];
        }
        archivo << pasos_ss.str() << std::endl;
        archivo << requisitos << std::endl << std::endl;

        archivo.close();
        std::cout << "Archivo guardado con exito." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }
}

Manual Manual::buscarTXT(const std::string& text) {
    std::ifstream archivoLectura("datos.txt");
    std::string linea;

    bool encontrado = false;
    Manual aux;

    if (archivoLectura.is_open()) {
        while (std::getline(archivoLectura, linea)) {
            if (linea.find(text) != std::string::npos) {
                std::getline(archivoLectura, aux.titulo);
                std::getline(archivoLectura, aux.autor);
                std::getline(archivoLectura, aux.fecha);
                std::getline(archivoLectura, aux.contenido);

                std::string tags_line;
                std::getline(archivoLectura, tags_line);
                aux.tags.clear();
                std::istringstream tss(tags_line);
                std::string tag;
                while (std::getline(tss, tag, ',')) {
                    if (!tag.empty()) aux.tags.push_back(tag);
                }

                std::string pasos_line;
                std::getline(archivoLectura, pasos_line);
                aux.pasos.clear();
                std::istringstream pss(pasos_line);
                std::string paso;
                while (std::getline(pss, paso, ',')) {
                    if (!paso.empty()) aux.pasos.push_back(paso);
                }

                std::getline(archivoLectura, aux.requisitos);
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            std::cout << "No se encontró el registro." << std::endl;
        }

        archivoLectura.close();
    } else {
        std::cerr << "Error: No se pudo abrir el archivo para lectura." << std::endl;
    }

    return aux;
}

