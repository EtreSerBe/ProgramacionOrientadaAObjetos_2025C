
// Karen Sthefanie Trejo Garduño
// Ejercicio 2 -Arrays y Arrays como Parámetros

#include <iostream>
using namespace std;

// Declaración de funciones
void modificarArray(bool arr[], int tam);
void modificarArray(int* arr, int tam);

int main() {
    cout << "----------------------------------------" << endl;
    cout << "EJERCICIO 2: ARRAYS Y PARAMETROS" << endl;
    cout << "----------------------------------------" << endl;

    // 1) Array de 5 booleanos
    bool arregloBool[5];
    modificarArray(arregloBool, 5);

    cout << "\nValores del array booleano:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Índice " << i << ": " << (arregloBool[i] ? "true" : "false") << endl;
    }

    // 2) Array de 10 enteros (0 al 9)
    int arregloInt[10];
    for (int i = 0; i < 10; i++) {
        arregloInt[i] = i;
    }

    modificarArray(arregloInt, 10);

    cout << "\nValores del array entero tras aplicar %2:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Índice " << i << ": " << arregloInt[i] << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}

//Funciones

// 1.1) Función para modificar arreglo de booleanos
void modificarArray(bool arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (i % 2 == 0) arr[i] = false;
        else arr[i] = true;
    }
}

// 1.4) Sobrecarga para enteros usando aritmética de punteros
void modificarArray(int* arr, int tam) {
    int* aux = arr; // auxiliar para no modificar el puntero original
    cout << "\nDirecciones de memoria y valores resultantes del %2:\n";

    for (int i = 0; i < tam; i++) {
        *aux = *aux % 2; // aplica el módulo 2
        cout << "Elemento " << i << " -> Dirección: " << (aux) << " | Valor: " << *aux << endl;
        aux++; // avanza al siguiente elemento
    }
}
