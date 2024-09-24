#include "Juego.h"
#include <fstream>
#include <sstream>
#include <iostream>

Juego::Juego() {
    jugador = new Tablero(4, 3);
    enemigo = new Tablero(4, 3);
}

Juego::~Juego() {
    delete jugador;
    delete enemigo;
    for (auto& par : fichas) {
        delete par.second;
    }
}

void Juego::cargarFichas(const std::string& archivo) {
    std::ifstream file(archivo);
    std::string linea;
    while (std::getline(file, linea)) {
        std::stringstream ss(linea);
        std::string tipo;
        int hp, atk, def, rango;
        char coma;
        ss >> tipo >> coma >> hp >> coma >> atk >> coma >> def >> coma >> rango;
        fichas[tipo] = new Ficha(tipo, hp, atk, def, rango);
    }
}

void Juego::cargarEscenario(const std::string& archivo, Tablero* tablero) {
    std::ifstream file(archivo);
    std::string linea;
    while (std::getline(file, linea)) {
        if (linea.find("Escenario") != std::string::npos) continue;
        std::stringstream ss(linea);
        std::string tipo;
        int fila, columna;
        char coma;
        ss >> tipo >> coma >> fila >> coma >> columna;
        Ficha* ficha = fichas[tipo];
        tablero->colocarFicha(new Ficha(*ficha), fila - 1, columna - 1);
    }
}

void Juego::iniciarCombate() {
    std::cout << "Tablero del jugador:" << std::endl;
    jugador->mostrarTablero();
    std::cout << "Tablero del enemigo:" << std::endl;
    enemigo->mostrarTablero();
    // Lógica del combate...
}

// Getters
Tablero* Juego::getJugador() const {
    return jugador;
}

Tablero* Juego::getEnemigo() const {
    return enemigo;
}
