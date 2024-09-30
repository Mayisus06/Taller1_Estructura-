#include "Ficha.h"


// Constructor de la clase Ficha
Ficha::Ficha(const std::string& tipo, int vida, int ataque, int defensa, int nivel)
    : tipo(tipo), vida(vida), ataque(ataque), defensa(defensa), nivel(nivel) {}


// M�todo para obtener el tipo de la ficha
std::string Ficha::getTipo() const {
    return tipo;
}
// M�todo para obtener los puntos de vida de la ficha
int Ficha::getVida() const {
    return vida;
}
// M�todo para obtener los puntos de ataque de la ficha
int Ficha::getAtaque() const {
    return ataque;
}
// M�todo para obtener los puntos de defensa de la ficha
int Ficha::getDefensa() const {
    return defensa;
}
// M�todo para obtener el nivel de la ficha
int Ficha::getNivel() const {
    return nivel;
}
// Funcion para establecer el tipo de la ficha
void Ficha::setTipo(const std::string& tipo) {
    this->tipo = tipo;
}



//#include "Ficha.h" : hace que incluya el contenido del Ficha.h