#include "Tablero.h"
#include <string>
#include <map>

class Juego {
private:
    Tablero* jugador;
    Tablero* enemigo;
    std::map<std::string, Ficha*> fichas;

public:
    Juego();
    ~Juego();
    void cargarFichas(const std::string& archivo);
    void cargarEscenario(const std::string& archivo, Tablero* tablero);
    void iniciarCombate();

    // Getters
    Tablero* getJugador() const;
    Tablero* getEnemigo() const;
};
