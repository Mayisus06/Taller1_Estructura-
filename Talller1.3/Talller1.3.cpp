#include "Escenario.h"
#include "Ficha.h"
#include <iostream>
#include <vector>
// Menu inicial con su 4 caracteriticas 
void mostrarMenu() {
    std::cout << "\n--- Menú Principal ---\n";
    std::cout << "1) Comenzar combate\n";
    std::cout << "2) Cambiar ficha del equipo\n";
    std::cout << "3) Cambiar posicion de las fichas\n";
    std::cout << "4) Cerrar juego y mostrar estadisticas\n";
    std::cout << "Seleccione una opcion: ";
}
// funcion para cambiar la posicion 
void cambiarPosicionDeFicha(Escenario& escenario) {
    std::cout << "\n[Cambiar Posición de Ficha]\n";
    int filaOrigen, columnaOrigen, filaDestino, columnaDestino;

    std::cout << "Ingrese la fila de la ficha que desea mover: ";
    std::cin >> filaOrigen;
    std::cout << "Ingrese la columna de la ficha que desea mover: ";
    std::cin >> columnaOrigen;

    std::cout << "Ingrese la nueva fila destino: ";
    std::cin >> filaDestino;
    std::cout << "Ingrese la nueva columna destino: ";
    std::cin >> columnaDestino;

    Ficha* fichaAMover = escenario.obtenerFicha(filaOrigen, columnaOrigen);

    if (fichaAMover != nullptr) {
        escenario.colocarFicha(fichaAMover, filaDestino, columnaDestino);
        escenario.removerFicha(filaOrigen, columnaOrigen);
        std::cout << "Ficha movida exitosamente.\n";
    }
    else {
        std::cout << "No hay ficha en la posición especificada.\n";
    }
}
// mostrar estadistica pedida despues de salir 
void mostrarEstadisticas() {
    std::cout << "\n--- Estadísticas del Juego ---\n";
    std::cout << "1. Tipo de ficha con mayores bajas: [A completar]\n";
    std::cout << "2. Tipo de ficha con mayor cantidad de daño: [A completar]\n";
    std::cout << "3. Partidas totales y porcentaje de victoria: [A completar]\n";
}
// funcion para el combate
void comenzarCombate(Escenario& escenario) {
    std::cout << "\n[Comenzar Combate]\n";
    // Aquí progamar la lógica para simular el combate
    std::cout << "El combate ha comenzado...\n";
}
// funcion para cambiar ficha del equipo
void cambiarFichaDelEquipo(Escenario& escenario) {
    std::cout << "\n[Cambiar Ficha del Equipo]\n";
    int fila, columna;
    std::string nuevoTipo;
    int nuevaVida, nuevoAtaque, nuevaDefensa, nuevoNivel;

    std::cout << "Ingrese la fila de la ficha que desea cambiar: ";
    std::cin >> fila;
    std::cout << "Ingrese la columna de la ficha que desea cambiar: ";
    std::cin >> columna;

    Ficha* fichaActual = escenario.obtenerFicha(fila, columna);

    if (fichaActual != nullptr) {
        std::cout << "Ingrese el nuevo tipo de ficha: ";
        std::cin >> nuevoTipo;
        std::cout << "Ingrese la nueva vida de la ficha: ";
        std::cin >> nuevaVida;
        std::cout << "Ingrese el nuevo ataque de la ficha: ";
        std::cin >> nuevoAtaque;
        std::cout << "Ingrese la nueva defensa de la ficha: ";
        std::cin >> nuevaDefensa;
        std::cout << "Ingrese el nuevo nivel de la ficha: ";
        std::cin >> nuevoNivel;

        // Cambiar los atributos de la ficha
        *fichaActual = Ficha(nuevoTipo, nuevaVida, nuevoAtaque, nuevaDefensa, nuevoNivel);
        std::cout << "Ficha actualizada exitosamente.\n";
    }
    else {
        std::cout << "No hay ficha en la posición especificada.\n";
    }
}
//main
int main() {
    // Cargar las fichas desde el archivo
    std::vector<Ficha> fichas = Escenario::leerFichas("fichas.txt");
    std::cout << "Fichas cargadas: " << fichas.size() << std::endl;

    // Cargar escenarios desde el archivo
    std::vector<std::vector<std::string>> escenarios = Escenario::leerEscenarios("escenarios.txt");
    std::cout << "Escenarios cargados: " << escenarios.size() << std::endl;

    // Verificar que al menos hay un escenario
    if (escenarios.empty()) {
        std::cerr << "Error: No se encontraron escenarios." << std::endl;
        return 1;
    }

    // Crear un escenario basado en el primer escenario leído
    int filas = 5;
    int columnas = 5;
    Escenario escenario(filas, columnas);

    // Colocar algunas fichas de ejemplo en el escenario
    for (int i = 0; i < fichas.size() && i < filas * columnas; ++i) {
        int fila = i / columnas;
        int columna = i % columnas;
        Ficha* nuevaFicha = new Ficha(fichas[i]);  // Copia la ficha leída
        escenario.colocarFicha(nuevaFicha, fila, columna);
    }

    int opcion;
    bool salir = false;
    // funcion de menu
    while (!salir) {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            comenzarCombate(escenario);
            break;
        case 2:
            cambiarFichaDelEquipo(escenario);
            break;
        case 3:
            cambiarPosicionDeFicha(escenario);
            break;
        case 4:
            mostrarEstadisticas();
            salir = true;
            break;
        default:
            std::cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }
    }

    std::cout << "Juego cerrado.\n";
    return 0;
}




//#include "Escenario.h" : hace que incluya el contenido del archivo Escenario.h
//#include "Ficha.h" : hace que incluya el contenido del Ficha.h
//#include <iostream> : nos facilita el uso de std::cout para imprimir en pantalla y std::cin para leer datos del usuario.
//#include <vector> : estructura de datos dinámica similar a un arreglo, pero con la capacidad de cambiar su tamaño 