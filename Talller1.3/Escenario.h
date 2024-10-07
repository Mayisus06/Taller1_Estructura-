#include "ListaNexoSimple.h"
#include <string>

class Escenario {
private:
    ListaNexoSimple<std::string> listaEscenarios;

public:
    void cargarEscenarios(const std::string& archivo);
    void mostrarEscenarios();
};
