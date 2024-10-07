#include "ListaNexoSimple.h"
#include <string>
#include <map>

class Ficha {
private:
    ListaNexoSimple<std::string> listaFichas;
    std::map<std::string, std::string> composiciones; // Para guardar composiciones

public:
    void cargarFichas(const std::string& archivo);
    void mostrarFichas();
    void cambiarFichaEquipo(const std::string& ficha, const std::string& nuevoEquipo);
    void cambiarPosicionFicha(const std::string& ficha, int nuevaFila, int nuevaColumna);
    void guardarComposicion(const std::string& nombre);
    void cargarComposicion(const std::string& nombre);
};
