// Autor: Axel Roberto Flores Moreno
// Ejercicio de Variables, Funciones y Condiciones

#include <iostream>
#include <ctime>
using namespace std;

// Declaración de funciones
void imprimirLunes();
void imprimirJueves(int hora);
void imprimirMartes(int hora);
void cicloDias(int diaActual);

int main() {
    int dia = 1; // 0=domingo, 1=lunes, 2=martes, 3=miércoles, 4=jueves, etc.
    int hora = 10; // hora para pruebas (24h). Ejemplo: 10 = 10 AM, 14 = 2 PM

    cout << "Alumno: Axel Roberto Flores Moreno\n\n";

    if (dia == 1) {
        imprimirLunes();
    }

    if (dia == 4 && hora < 12) {
        imprimirJueves(hora);
    }

    imprimirMartes(hora);
    cicloDias(dia);

    return 0;
}

void imprimirLunes() {
    cout << "Es lunes\n";
}

void imprimirJueves(int hora) {
    cout << "Es jueves antes del mediodía\n";
}

void imprimirMartes(int hora) {
    int dia = 2; // martes
    if (dia == 2) {
        cout << "Es martes\n";
    }
    else if (hora >= 12) {
        cout << "No es martes pero es después de las 12 PM\n";
    }
}

void cicloDias(int diaActual) {
    string dias[7] = { "Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado" };
    for (int i = 0; i < 7; i++) {
        if (i == diaActual) {
            cout << "Hoy sí es " << dias[i] << endl;
        }
        else {
            cout << "Hoy no es " << dias[i] << endl;
        }
    }
}
