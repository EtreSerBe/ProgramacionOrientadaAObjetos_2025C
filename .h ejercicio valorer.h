// .h
//  Axel Roberto Flores Moreno

#ifndef VECTOR_DE_VALORES_H
#define VECTOR_DE_VALORES_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Estructura que representa un vector dinámico de valores float
struct VectorDeValores {
    float* datos; // Puntero al arreglo dinámico de datos
    int tamano; // Número de elementos almacenados

    // Constructor por defecto: crea un vector de 2 elementos inicializados en 0
    VectorDeValores();

    // Constructor que copia valores desde un arreglo existente
    VectorDeValores(const float* arr, int n);

    // Destructor: libera la memoria dinámica
    ~VectorDeValores();

    // Muestra el contenido del vector con formato
    void Imprimir(const string& etiqueta = "") const;
};

#endif
