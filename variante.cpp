// main.cpp
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <cstdlib>     // Para rand() y srand()
#include <ctime>       // Para time()
#include "LabelEncoder.h" // Incluir el archivo de encabezado

using namespace std;

int main() {
    srand(time(0));  // Inicializamos el generador de números aleatorios

    // Parámetros de entrada
    int tamanoMaximo = 10000;       // Hasta 10,000 elementos
    int unicosMaximo = 65535;       // Hasta 65,535 valores únicos // 4 byte on int
    int longitudMaxima = 100;       // Longitud máxima de 100 caracteres

    // Generación de cadenas aleatorias
    unordered_set<string> cadenasUnicas;
    vector<string> arreglo;

    // Generar cadenas únicas aleatorias
    while (arreglo.size() < tamanoMaximo) {
        string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int longitud = rand() % longitudMaxima + 1;  // numero aleatorio  entre 1 y longitudMaxima
        string cadenaAleatoria;

        for (int i = 0; i < longitud; ++i) { // se va a ejecutar longitud de veces anadiendo caracteres
            cadenaAleatoria += caracteres[rand() % caracteres.size()];
        }

        // Solo añadimos la cadena si es única o ya está en el conjunto y necesitamos más elementos
        if (cadenasUnicas.size() < unicosMaximo || cadenasUnicas.count(cadenaAleatoria) > 0) {
            cadenasUnicas.insert(cadenaAleatoria);
            arreglo.push_back(cadenaAleatoria);
        }
    }

    // Llamamos a la función de codificación de etiquetas
    vector<int> resultado = labelEncoder(arreglo);

    // Mostramos los primeros 10 resultados para verificar
    cout << "Primeros 1000 resultados:" << endl;
    for (int i = 0; i < 1000 && i < resultado.size(); ++i) {
        cout << resultado[i] << " ";
    }
    cout << endl;

    return 0;
}

