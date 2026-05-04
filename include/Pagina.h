#ifndef PAGINA_H
#define PAGINA_H


class Pagina
{
    public:
        Pagina();
        std::string titulo;
        std::string autor;
        std::string fecha;
        std::string contenido;
        std::string tags;

    private:
    // Contar elementos
    virtual int contarElementos() = 0;
    // Article: contar palabras
    // Manual: contar pasos

    // Obtener resumen
    virtual string obtenerResumen() = 0;
    // Article: primeras líneas
    // Manual: lista de pasos
};

#endif // PAGINA_H
