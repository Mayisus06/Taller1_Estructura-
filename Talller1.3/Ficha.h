#include "ListaNexoSimple.h"
#include <string>
#include <map>

class Ficha {
private:
    ListaNexoSimple<std::string> listaFichas;
    

public:
    void cargarFichas(const std::string& archivo);
    void mostrarFichas();
    void cambiarFichaEquipo(const std::string& ficha, const std::string& nuevoEquipo);
    void cambiarPosicionFicha(const std::string& ficha, int nuevaFila, int nuevaColumna);
    
};
