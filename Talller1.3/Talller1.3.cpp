#include "Juego.h"
#include <iostream>

void mostrarMenu() {
    std::cout << "===== Menu Principal =====" << std::endl;
    std::cout << "1. Cargar fichas" << std::endl;
    std::cout << "2. Cargar escenario" << std::endl;
    std::cout << "3. Iniciar combate" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

int main() {
    Juego juego;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            juego.cargarFichas("fichas.txt");
            std::cout << "Fichas cargadas exitosamente." << std::endl;
            break;
        }
        case 2: {
            juego.cargarEscenario("escenarios.txt", juego.getJugador());
            juego.cargarEscenario("escenarios.txt", juego.getEnemigo());
            std::cout << "Escenario cargado exitosamente." << std::endl;
            break;
        }
        case 3: {
            juego.iniciarCombate();
            break;
        }
        case 4: {
            std::cout << "Saliendo del juego..." << std::endl;
            break;
        }
        default: {
            std::cout << "Opcion no valida, intente de nuevo." << std::endl;
            break;
        }
        }
    } while (opcion != 4);

    return 0;
}
