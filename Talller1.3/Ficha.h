#ifndef FICHA_H
#define FICHA_H

#include <string>

class Ficha {
private:
    std::string tipo;
    int hp;
    int atk;
    int def;
    int rango;

public:
    Ficha(const std::string& tipo, int hp, int atk, int def, int rango);
    std::string getTipo() const;
    int getHP() const;
    int getAtk() const;
    int getDef() const;
    int getRango() const;
    void recibirDano(int dano);
    bool estaDesmayada() const;
};

#endif
