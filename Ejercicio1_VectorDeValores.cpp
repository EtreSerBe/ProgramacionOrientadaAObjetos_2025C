// Karen Garduño
#include <iostream>
using namespace std;


//  EJERCICIO 1: STRUCT VectorDeValores

struct VectorDeValores {
    float* datos;
    int tam;

    VectorDeValores() {
        tam = 2;
        datos = new float[tam];
        for (int i = 0; i < tam; i++)
            datos[i] = 0.0f;
        cout << "Constructor por defecto: VectorDeValores con " << tam << " elementos inicializados en 0." << endl;
    }

    VectorDeValores(const float arr[], int n) {
        tam = n;
        datos = new float[tam];
        for (int i = 0; i < tam; i++)
            datos[i] = arr[i];
        cout << "Constructor con parámetros: VectorDeValores creado con " << tam << " elementos." << endl;
    }

    ~VectorDeValores() {
        if (datos != nullptr) {
            cout << "Liberando memoria de VectorDeValores con " << tam << " elementos." << endl;
            delete[] datos;
            datos = nullptr;
        }
    }

    void imprimir() const {
        cout << "VectorDeValores [";
        for (int i = 0; i < tam; i++) {
            cout << datos[i];
            if (i < tam - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    float valores[] = {10.5f, 20.2f, 30.7f};
    VectorDeValores v1(valores, 3);
    v1.imprimir();

    VectorDeValores v2;
    v2.imprimir();
    return 0;
}
