
#include "Ficha.h"
#include <vector>
#include <string>
//Definimos la clase Escenario 
class Escenario {
//Especifica que los siguientes miembros son privados
private:
    int filas;
    int columnas;
    std::vector<std::vector<Ficha*>> tablero;
//Especifica que los siguientes miembros son publicos
public:
    Escenario(int filas, int columnas);
    ~Escenario();
    //Método que coloca una ficha en una posición específica del tablero. (Recibe un puntero a un objeto)
    void colocarFicha(Ficha* ficha, int fila, int columna);
    //Método que muestra el estado actual del escenario en la consola
    void mostrarEscenario() const;
    //Método que devuelve un puntero a la ficha ubicada en las coordenadas especificadas
    Ficha* obtenerFicha(int fila, int columna) const;
    //Método que elimina la ficha ubicada en las coordenadas especificadas del tablero ( puede eliminar memoria de la ficha)
    void removerFicha(int fila, int columna);
    //Método estático que lee fichas desde un archivo y devuelve un vector de objetos
    static std::vector<Ficha> leerFichas(const std::string& nombreArchivo);
    //Método estático que lee los datos del escenario desde un archivo y devuelve un vector 
    static std::vector<std::vector<std::string>> leerEscenarios(const std::string& nombreArchivo);
};
//#include "Ficha.h" : hace que incluya el contenido del Ficha.h
//#include <vector> : estructura de datos dinámica similar a un arreglo, pero con la capacidad de cambiar su tamaño 
//#include <string> : nos permite la utilizacion para manejar cadenas de texto.

