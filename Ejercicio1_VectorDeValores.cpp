//Axel Roberto Flores Moreno

#include <iostream>
#include <iomanip>
using namespace std;

struct VectorDeValores {
    float* datos;
    int tamaño;

    VectorDeValores() : datos(nullptr), tamaño(2) {
        datos = new float[tamaño];
        for (int i = 0; i < tamaño; ++i) datos[i] = 0.0f;
        cout << "[VectorDeValores] Constructor por defecto: tamaño = " << tamaño << ", inicializados a 0\n";
    }

    VectorDeValores(const float* arr, int n) : datos(nullptr), tamaño(n) {
        if (tamaño > 0) {
            datos = new float[tamaño];
            for (int i = 0; i < tamaño; ++i) datos[i] = arr[i];
        }
        cout << "[VectorDeValores] Constructor desde array: tamaño = " << tamaño << "\n";
    }

    ~VectorDeValores() {
        if (datos) {
            cout << "[VectorDeValores] Liberando memoria: " << tamaño << " elemento(s)\n";
            delete[] datos;
        }
    }

    void imprimir(const string& etiqueta = "") const {
        if (!etiqueta.empty()) cout << etiqueta << ": ";
        cout << "tamaño=" << tamaño << " [ ";
        for (int i = 0; i < tamaño; ++i) {
            cout << fixed << setprecision(2) << datos[i];
            if (i + 1 < tamaño) cout << ", ";
        }
        cout << " ]\n";
    }
};

int main() {
    float arr[] = {1.1f, 2.2f, 3.3f};
    VectorDeValores v1(arr, 3);
    v1.imprimir("v1");

    VectorDeValores v2;
    v2.imprimir("v2");
    return 0;
}
