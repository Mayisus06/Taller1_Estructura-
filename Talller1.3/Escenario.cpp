#include "Escenario.h"
#include <iostream>
#include <fstream>
#include <sstream>


// Constructor 
//(Inicializa el objeto con el n�mero de filas y columnas especificadas) 
Escenario::Escenario(int filas, int columnas) : filas(filas), columnas(columnas) {
    //el vector tablero para tener filas filas, donde cada fila es un vector de columnas
    tablero.resize(filas, std::vector<Ficha*>(columnas, nullptr));
}

// Destructor
//(Se ejecuta cuando un objeto de esta clase es destruido.)
Escenario::~Escenario() {
    for (auto& fila : tablero) {
        for (auto& ficha : fila) {
            // delete : Libera la memoria ocupada por cada Ficha
            delete ficha;
        }
    }
}

// funcion de Colocar una ficha en una posici�n espec�fica
void Escenario::colocarFicha(Ficha* ficha, int fila, int columna) {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        if (tablero[fila][columna] != nullptr) {
            delete tablero[fila][columna]; // Elimina cualquier ficha existente antes de colocar una nueva
        }
        tablero[fila][columna] = ficha;
    }
    else {
        std::cerr << "Error: Posici�n fuera del rango (" << fila << ", " << columna << ")" << std::endl;
    }
}

// Obtener ficha de una posici�n espec�fica
Ficha* Escenario::obtenerFicha(int fila, int columna) const { //Devuelve un puntero a la ficha en la posici�n especificada.
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        return tablero[fila][columna];
    }
    //Retorna nullptr si la posici�n est� fuera de rango.
    return nullptr;
}

// Remover ficha de una posici�n espec�fica
void Escenario::removerFicha(int fila, int columna) { //Elimina la ficha en la posici�n especificada.
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        delete tablero[fila][columna]; //Libera la memoria de la ficha en la posici�n
        tablero[fila][columna] = nullptr; //Establece la posici�n a nullptr, indicando que ya no hay ficha.
    }
}

// Muestra el escenario en consola
void Escenario::mostrarEscenario() const {
    for (const auto& fila : tablero) {
        for (const auto& ficha : fila) {
            if (ficha) {
                std::cout << ficha->getTipo() << " "; //Muestra el tipo de ficha si existe; de lo contrario, muestra un punto (.) para indicar que la posici�n est� vac�a.
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

// Funci�n para leer fichas desde un archivo
std::vector<Ficha> Escenario::leerFichas(const std::string& nombreArchivo) { // Lee las fichas desde un archivo y devuelve un vector de objetos Ficha
    std::vector<Ficha> fichas; 
    std::ifstream archivo(nombreArchivo); //Abre el archivo para lectura.
    std::string linea;

    if (archivo.is_open()) {
        while (std::getline(archivo, linea)) { //Lee cada l�nea del archivo
            std::stringstream ss(linea);
            std::string tipo;
            int vida, ataque, defensa, nivel;

            if (std::getline(ss, tipo, ',') &&
                ss >> vida && ss.ignore() &&
                ss >> ataque && ss.ignore() &&
                ss >> defensa && ss.ignore() &&
                ss >> nivel) {

                fichas.push_back(Ficha(tipo, vida, ataque, defensa, nivel)); //Crea un nuevo objeto Ficha y lo agrega al vector
            }
        }
        archivo.close(); //cierre de archivo
    }
    else {
        std::cerr << "Error: No se pudo abrir el archivo de fichas" << std::endl;
    }

    return fichas;
}

// Funci�n para leer escenarios desde un archivo
std::vector<std::vector<std::string>> Escenario::leerEscenarios(const std::string& nombreArchivo) {
    std::vector<std::vector<std::string>> escenarios;
    std::ifstream archivo(nombreArchivo); //Abre el archivo para lectura.
    std::string linea;

    if (archivo.is_open()) {
        std::vector<std::string> actualEscenario; //Almacena el escenario actual que se est� leyendo.

        while (std::getline(archivo, linea)) {
            if (linea.find("Escenario") != std::string::npos) {
                if (!actualEscenario.empty()) {
                    escenarios.push_back(actualEscenario); //Si se ha le�do un nuevo escenario, se agrega el anterior al vector de escenarios
                    actualEscenario.clear(); //Limpia el vector para comenzar a almacenar el nuevo escenario.
                }
                actualEscenario.push_back(linea); 
            }
            else {
                actualEscenario.push_back(linea);
            }
        }

        if (!actualEscenario.empty()) {
            escenarios.push_back(actualEscenario);
        }

        archivo.close(); //cierre de archivo
    }
    else {
        std::cerr << "Error: No se pudo abrir el archivo de escenarios" << std::endl;
    }

    return escenarios; //retorna escenario
}


//#include "Escenario.h" : hace que incluya el contenido del Escenario.h
//#include <iostream> :  Incluye la librer�a est�ndar para operaciones de entrada y salida
//#include <fstream> :  Incluye la librer�a para manejar archivos de entrada y salida
//#include <sstream> : cluye la librer�a para manipular cadenas de texto como flujos, �til para leer datos de las l�neas de un archivo (ss)
//push_back : Agrega un nuevo elemento al final de un vector.
//pop_back : Elimina el �ltimo elemento de un vector.