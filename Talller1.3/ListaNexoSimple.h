#pragma once
#include "Nodo.h"
#include <iostream>

template <typename T>
class ListaNexoSimple {
public:
    Nodo<T>* cabeza;

    ListaNexoSimple() : cabeza(nullptr) {}

    void insertar(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void mostrar() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        std::cout << "NULL" << std::endl;
    }
};
