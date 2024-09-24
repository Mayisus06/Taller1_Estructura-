#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Ficha.h"

class Tablero {
private:
    std::vector<std::vector<Ficha*>> matriz;
    int filas;
    int columnas;

public:
    Tablero(int filas, int columnas);
    ~Tablero();
    void colocarFicha(Ficha* ficha, int fila, int columna);
    Ficha* obtenerFicha(int fila, int columna) const;
    void mostrarTablero() const;
};

#endif
