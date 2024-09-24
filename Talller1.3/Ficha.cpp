#include "Ficha.h"

Ficha::Ficha(const std::string& tipo, int hp, int atk, int def, int rango)
    : tipo(tipo), hp(hp), atk(atk), def(def), rango(rango) {}

std::string Ficha::getTipo() const {
    return tipo;
}

int Ficha::getHP() const {
    return hp;
}

int Ficha::getAtk() const {
    return atk;
}

int Ficha::getDef() const {
    return def;
}

int Ficha::getRango() const {
    return rango;
}

void Ficha::recibirDano(int dano) {
    hp -= dano;
}

bool Ficha::estaDesmayada() const {
    return hp <= 0;
}
