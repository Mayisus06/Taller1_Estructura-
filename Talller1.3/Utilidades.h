
#include <vector>
#include <string>
#include "Ficha.h"
// Función para leer fichas desde un archivo
std::vector<Ficha> leerFichas(const std::string& ruta);
// Función para leer escenarios desde un archivo
std::vector<std::vector<std::string>> leerEscenarios(const std::string& ruta);


//#include "Ficha.h" : hace que incluya el contenido del Ficha.h
//#include <vector> : estructura de datos dinámica similar a un arreglo, pero con la capacidad de cambiar su tamaño 
//#include <string> : nos permite la utilizacion para manejar cadenas de texto.