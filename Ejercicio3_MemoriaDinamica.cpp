// Karen Garduño

#include <iostream>
using namespace std;


//  EJERCICIO 3: MEMORIA DINÁMICA

int main() {
    cout << "=== Ejercicio 3: Uso de memoria dinámica ===" << endl;

    float* p = nullptr;
    p = new float;
    *p = 7.77f;
    cout << "Puntero p creado dinámicamente con valor: " << *p << endl;

    float var = 6.66f;
    cout << "Variable var creada con valor: " << var << endl;

    p = &var;
    cout << "Cuidado, acabas de causar un memory leak!" << endl;
    cout << "Explicación: se perdió la referencia a memoria dinámica sin delete." << endl;

    p = new float;
    *p = 1984.0f;
    float* q = p;

    delete p;
    p = nullptr;
    cout << "Memoria liberada correctamente y puntero p puesto a nullptr." << endl;

    if (p == nullptr) cout << "p es nullptr" << endl;
    if (p == NULL) cout << "p es NULL" << endl;

    if (q == nullptr || q == NULL)
        cout << "q es nullptr o NULL" << endl;
    else
        cout << "q no es nullptr ni NULL. Apunta a memoria liberada, cuidado!" << endl;

    q = nullptr;
    return 0;
}
