#include "Ficha.h"
#include <fstream>
#include <iostream>
#include <string>

void Ficha::cargarFichas(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file) {
        std::cerr << "Error al abrir el archivo de fichas." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(file, linea)) {
        listaFichas.insertar(linea);
    }
    file.close();
}

void Ficha::mostrarFichas() {
    listaFichas.mostrar();
}

void Ficha::cambiarFichaEquipo(const std::string& ficha, const std::string& nuevoEquipo) {
    Nodo<std::string>* actual = listaFichas.cabeza;
    while (actual != nullptr) {
        // Extraer el nombre de la ficha antes de la coma
        std::string nombreFicha = actual->dato.substr(0, actual->dato.find(','));

        // Comparar solo el nombre
        if (nombreFicha == ficha) {
            
            std::string nuevaFicha = nombreFicha + "," + nuevoEquipo;  
            actual->dato = nuevaFicha;
            std::cout << "Ficha " << ficha << " cambiada al equipo " << nuevoEquipo << std::endl;
            return;
        }
        actual = actual->siguiente;
    }
    std::cout << "Ficha no encontrada" << std::endl;
}

void Ficha::cambiarPosicionFicha(const std::string& ficha, int nuevaFila, int nuevaColumna) {
    Nodo<std::string>* actual = listaFichas.cabeza;
    while (actual != nullptr) {
        // Extraer el nombre de la ficha antes de la coma
        std::string nombreFicha = actual->dato.substr(0, actual->dato.find(','));

        // Comparar solo el nombre
        if (nombreFicha == ficha) {
            
            std::cout << "Ficha " << ficha << " movida a Fila: " << nuevaFila << ", Columna: " << nuevaColumna << std::endl;
            return;
        }
        actual = actual->siguiente;
    }
    std::cout << "Ficha no encontrada" << std::endl;
}


