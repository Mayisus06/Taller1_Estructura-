#include "Escenario.h"
#include <fstream>
#include <iostream>
#include <string>

void Escenario::cargarEscenarios(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file) {
        std::cerr << "Error al abrir el archivo de escenarios." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(file, linea)) {
        listaEscenarios.insertar(linea);
    }
    file.close();
}

void Escenario::mostrarEscenarios() {
    listaEscenarios.mostrar();
}
