#include <iostream>
#include "Escenario.h"
#include "Ficha.h"

int main() {
    Escenario escenario;
    Ficha ficha;

    int opcion;
    do {
        std::cout << "\n=== MENU DEL JUEGO ===" << std::endl;
        std::cout << "1. Cargar Escenarios" << std::endl;
        std::cout << "2. Mostrar Escenarios" << std::endl;
        std::cout << "3. Cargar Fichas" << std::endl;
        std::cout << "4. Mostrar Fichas" << std::endl;
        std::cout << "5. Cambiar Ficha de Equipo" << std::endl;
        std::cout << "6. Cambiar Posicion de Ficha" << std::endl;
        std::cout << "7. Cerrar Juego y Mostrar Estadisticas" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Cargando escenarios desde archivo..." << std::endl;
            escenario.cargarEscenarios("escenarios.txt");
            std::cout << "Escenarios cargados con exito." << std::endl;
            break;

        case 2:
            std::cout << "Mostrando escenarios:" << std::endl;
            escenario.mostrarEscenarios();
            break;

        case 3:
            std::cout << "Cargando fichas desde archivo..." << std::endl;
            ficha.cargarFichas("fichas.txt");
            std::cout << "Fichas cargadas con exito." << std::endl;
            break;

        case 4:
            std::cout << "Mostrando fichas:" << std::endl;
            ficha.mostrarFichas();
            break;

        case 5: {
            std::string fichaNombre, nuevoEquipo;
            std::cout << "Ingrese el nombre de la ficha: ";
            std::cin >> fichaNombre;
            std::cout << "Ingrese el nuevo equipo: ";
            std::cin >> nuevoEquipo;
            ficha.cambiarFichaEquipo(fichaNombre, nuevoEquipo);
            break;
        }

        case 6: {
            std::string fichaNombre;
            int nuevaFila, nuevaColumna;
            std::cout << "Ingrese la ficha: ";
            std::cin >> fichaNombre;
            std::cout << "Ingrese la nueva fila y columna: ";
            std::cin >> nuevaFila >> nuevaColumna;
            ficha.cambiarPosicionFicha(fichaNombre, nuevaFila, nuevaColumna);
            break;
        }

        case 7:
            std::cout << "Cerrando juego y mostrando estadisticas..." << std::endl;
            break;

        default:
            std::cout << "Opción no valida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 9);

    return 0;
}
