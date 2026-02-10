// Autor: Axel Roberto Flores Moreno
// Ejercicio de Arrays y Sobrecarga de Funciones

#include <iostream>
using namespace std;

void modificarArray(bool arr[], int tam);
void modificarArray(int arr[], int tam);

int main() {
    cout << "Alumno: Axel Roberto Flores Moreno\n\n";

    bool arrayBool[5];
    modificarArray(arrayBool, 5);

    cout << "Array booleano:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Index " << i << ": " << (arrayBool[i] ? "true" : "false") << endl;
    }

    int arrayInt[10] = { 0,1,2,3,4,5,6,7,8,9 };
    modificarArray(arrayInt, 10);

    cout << "\nArray enteros (valores reemplazados por valor %2):\n";
    for (int i = 0; i < 10; i++) {
        cout << "Dir: " << (arrayInt + i) << " -> Valor: " << *(arrayInt + i) << endl;
    }

    return 0;
}

void modificarArray(bool arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (i % 2 == 0)
            arr[i] = false;
        else
            arr[i] = true;
    }
}

void modificarArray(int arr[], int tam) {
    int* aux = arr;
    for (int i = 0; i < tam; i++) {
        *(aux + i) = *(aux + i) % 2;
    }
}
