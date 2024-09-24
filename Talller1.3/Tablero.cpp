#include "Tablero.h"
#include <iostream>

Tablero::Tablero(int filas, int columnas)
    : filas(filas), columnas(columnas) {
    matriz.resize(filas, std::vector<Ficha*>(columnas, nullptr));
}

Tablero::~Tablero() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            delete matriz[i][j];
        }
    }
}

void Tablero::colocarFicha(Ficha* ficha, int fila, int columna) {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        matriz[fila][columna] = ficha;
    }
}

Ficha* Tablero::obtenerFicha(int fila, int columna) const {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        return matriz[fila][columna];
    }
    return nullptr;
}

void Tablero::mostrarTablero() const {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j]) {
                std::cout << matriz[i][j]->getTipo()[0] << " ";
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}
