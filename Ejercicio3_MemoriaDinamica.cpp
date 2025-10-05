//Axel Roberto Flores Moreno
#include <iostream>
using namespace std;

int main() {
    cout << "=== Ejercicio 3: Memoria Dinámica ===\n";
    float* p = nullptr;
    p = new float(7.77f);
    cout << "Valor inicial: " << *p << "\n";

    float var = 6.66f;
    p = &var;
    cout << "Cuidado, acabas de causar un memory leak!\n";
    cout << "Porque perdiste la referencia a la memoria asignada con new.\n";

    p = new float(1984.0f);
    float* q = p;
    delete p;
    p = nullptr;

    if (p == nullptr) cout << "p es nullptr\n";
    if (q != nullptr) cout << "q sigue apuntando a memoria liberada!\n";
    return 0;
}
