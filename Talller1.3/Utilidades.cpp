#include "Utilidades.h"
#include <fstream>
#include <sstream>
#include <iostream>
// Lee fichas desde un archivo
std::vector<Ficha> leerFichas(const std::string& ruta) { //Vector para almacenar las fichas
    std::vector<Ficha> fichas; 
    std::ifstream archivo(ruta);// Abre el archivo en la ruta especificada
    std::string linea;

    if (archivo.is_open()) { //Verifica que el archivo se haya abierto correctamente
        while (std::getline(archivo, linea)) { // Lee línea por línea
            std::stringstream ss(linea);
            std::string tipo;
            int ataque, defensa, vida, rango;
            char coma;
            // Lee los valores separados por comas
            ss >> tipo >> coma >> ataque >> coma >> defensa >> coma >> vida >> coma >> rango;
            fichas.emplace_back(tipo, ataque, defensa, vida, rango);
        }
    }

    return fichas; // Retorna el vector de fichas
}
// Lee escenarios desde un archivo
std::vector<std::vector<std::string>> leerEscenarios(const std::string& ruta) {
    std::vector<std::vector<std::string>> escenarios; // Vector para almacenar los escenarios
    std::ifstream archivo(ruta);// Abre el archivo en la ruta especificada
    std::string linea;

    if (archivo.is_open()) { // Verifica que el archivo se haya abierto correctamente
        std::vector<std::string> escenarioActual;
        while (std::getline(archivo, linea)) { // Lee línea por línea
            if (linea.find("Escenario") != std::string::npos) {
                if (!escenarioActual.empty()) {
                    escenarios.push_back(escenarioActual);// Agrega el escenario actual al vector de escenarios
                    escenarioActual.clear();// Limpia el vector para el siguiente escenario
                }
                escenarioActual.push_back(linea);// Agrega la línea al nuevo escenario
            }
            else {
                escenarioActual.push_back(linea);// Agrega la línea al escenario actual
            }
        }
        // Agrega el último escenario si no está vacío
        if (!escenarioActual.empty()) {
            escenarios.push_back(escenarioActual);
        }
    }

    return escenarios; // Retorna el vector de escenarios
}

//#include "Utilidades.h" hace que incluya el contenido del tilidades.h
//#include <iostream> : nos facilita el uso de std::cout para imprimir en pantalla y std::cin para leer datos del usuario.
//#include <fstream> :  Incluye la librería para manejar archivos de entrada y salida
//#include <sstream> : cluye la librería para manipular cadenas de texto como flujos, útil para leer datos de las líneas de un archivo (ss)
//push_back : Agrega un nuevo elemento al final de un vector.
//pop_back : Elimina el último elemento de un vector.