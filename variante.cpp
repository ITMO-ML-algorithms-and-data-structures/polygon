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

    //Parámetros de entrada
    int tamanoMaximo = 10000;       // Hasta 10,000 elemento // 4 byte on int
    cout <<"size TamanoMaximo" << sizeof(tamanoMaximo) << endl;
    int unicosMaximo = 65535;// Hasta 65,535 valores únicos // 4 byte on int
   cout <<"size unicosMaximo=" << sizeof(unicosMaximo) << endl;
    int longitudMaxima = 100;       // Longitud máxima de 100 caracteres // 4 byte on
    cout << "size longitudMaxima="<<sizeof(longitudMaxima) << endl;

    // Generación de cadenas aleatorias
    unordered_set<string> cadenasUnicas; //56 byte on
    cout <<"size cadenasunicas" << sizeof(cadenasUnicas) << endl;
    vector<string> arreglo;// 24 byte on
    cout<<"size arreglo" << sizeof(arreglo)<<endl;

    // Generar cadenas únicas aleatorias
    while (arreglo.size() < tamanoMaximo) {
        string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 4 byte on
        int longitud = rand() % longitudMaxima + 1;  // numero aleatorio  entre 1 y longitudMaxima // 4 byte on
        string cadenaAleatoria;// 32 byte on string
       //cout<<"size caracteres" << sizeof(caracteres) << endl;
        //cout<<"size longitud"<< sizeof(longitud)<<endl;
        //cout << "size cadenaaleatorea=" << sizeof(cadenaAleatoria) << endl;

        for (int i = 0; i < longitud; ++i) { // se va a ejecutar longitud de veces anadiendo caracteres
            cadenaAleatoria += caracteres[rand() % caracteres.size()];//32 byte on caracteres // 32 byte on cadenaAleatorea
            //cout<< "size de i"<<sizeof(i) <<endl;// 4 byte on
            //cout<<"caracteres"<<sizeof(caracteres)<<endl;
            //cout<<"cadenaAleatoria"<<sizeof(cadenaAleatoria)<<endl;
        }

        // Solo añadimos la cadena si es única o ya está en el conjunto y necesitamos más elementos
        if (cadenasUnicas.size() < unicosMaximo || cadenasUnicas.count(cadenaAleatoria) > 0) { //4 byte on unicosMaximo //32 byte on CadenaAleatoria
            cadenasUnicas.insert(cadenaAleatoria);//32 byte on cadenaAleatoria

            arreglo.push_back(cadenaAleatoria);//32 byte on cadenaAleatoria

            //cout << "size unicosMaximo"<<sizeof(unicosMaximo)<< endl
            //cout << "size cadenaAleatoria"<<sizeof(cadenaAleatoria) << endl;
        }
    }

    // Llamamos a la función de codificación de etiquetas
    vector<int> resultado = labelEncoder(arreglo); //24 byte on resultado
    //cout<<"size resultado" << sizeof(resultado) << endl;

    // Mostramos los primeros 5 resultados para verificar
    cout << "Primeros 5 resultados:" << endl;
    for (int i = 0; i < 5 && i < resultado.size(); ++i) { //4 byte on i
        cout << resultado[i] << " ";
        //cout << "size i" << sizeof(i)<<endl;
    }

    cout << endl;

    return 0;
}

