// .h
// Axel Roberto Flores Moreno

#ifndef RECT_H
#define RECT_H

#include <iostream>
#include <iomanip>
using namespace std;

// Clase Rect
// Representa un rectángulo mediante posición (X, Y) y dimensiones (Ancho, Alto)
class Rect {
public:
    float X; // Coordenada X de inicio
    float Y;   // Coordenada Y de inicio
    float Alto;// Altura del rectángulo
    float Ancho;  // Anchura del rectángulo

    // Constructores
    Rect();  // Constructor por defecto
    Rect(float x, float y, float alto, float ancho); // Constructor completo
    Rect(float alto, float ancho);  // Constructor con tamaño

    // Muestra la información del rectángulo y calcula los valores finales
    bool ImprimirYCalcularFinales(const Rect& r, float& xFinal, float& yFinal) const;

    // Comprueba si dos rectángulos se traslapan
    static bool CheckOverlap(const Rect& A, const Rect& B);
};

#endif
