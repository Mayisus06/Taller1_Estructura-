#include <string>

//Definimos la clase Ficha
class Ficha {
 //Especifica que los siguientes miembros son privados
private:
    std::string tipo;  // Tipo de la ficha (por ejemplo, 'Arquero', 'Mago', etc.)
    int vida;          // Puntos de vida de la ficha
    int ataque;        // Puntos de ataque de la ficha
    int defensa;       // Puntos de defensa de la ficha
    int nivel;         // Nivel de la ficha
 //Especifica que los siguientes miembros son publico
public:
    // Constructor de la clase Ficha
    Ficha(const std::string& tipo, int vida, int ataque, int defensa, int nivel);
    // M�todo para obtener el tipo de la ficha
    std::string getTipo() const;
    // M�todo para obtener los puntos de vida de la ficha
    int getVida() const;
    // M�todo para obtener los puntos de ataque de la ficha
    int getAtaque() const;
    // M�todo para obtener los puntos de defensa de la ficha
    int getDefensa() const;
    // M�todo para obtener el nivel de la ficha
    int getNivel() const;
    
  
    // M�todo para establecer el tipo de la ficha

    void setTipo(const std::string& tipo);
};


//#include <string> : nos permite la utilizacion para manejar cadenas de texto.
