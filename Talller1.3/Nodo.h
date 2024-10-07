#pragma once

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};
