
//Karen Sthefanie Trejo Garduño
// Ejercicio 1 -Variables, Funciones y Condiciones

#include <iostream>
#include <ctime> // Para obtener la hora actual
using namespace std;

// Declaración de funciones
void esLunes(int dia);
void juevesAntesMediodia(int dia, int hora, int minuto);
void martesODespues(int dia, int hora, int minuto);
void cicloDias(int diaActual);

// Función principal 
int main() {
    // 0 = Lunes, 1 = Martes, 2 = Miércoles, 3 = Jueves, 4 = Viernes, 5 = Sábado, 6 = Domingo
    int dia = 3; // Cambia este valor para probar diferentes días

    // Obtener hora actual del sistema
    time_t tiempoActual = time(0);
    tm* tiempoLocal = localtime(&tiempoActual);
    int hora = tiempoLocal->tm_hour;
    int minuto = tiempoLocal->tm_min;

    // Para pruebas, puedes forzar una hora manualmente:
    // hora = 11; minuto = 30;

    cout << "Día actual: " << dia << "  (0=Lunes ... 6=Domingo)" << endl;
    cout << "Hora actual: " << hora << ":" << minuto << endl << endl;

    // 1) Si es lunes
    esLunes(dia);

    // 2) Si es jueves antes del mediodía
    juevesAntesMediodia(dia, hora, minuto);

    // 3) Si es martes o después de las 12 PM
    martesODespues(dia, hora, minuto);

    // 4) Ciclo For con los días de la semana
    cicloDias(dia);

    cout << endl;
    system("pause");
    return 0;
}

//Definición de funciones

void esLunes(int dia) {
    if (dia == 0) {
        cout << "Es lunes" << endl;
    }
}

void juevesAntesMediodia(int dia, int hora, int minuto) {
    if (dia == 3 && (hora < 12 || (hora == 11 && minuto <= 59))) {
        cout << "Es jueves antes del mediodía" << endl;
    }
}

void martesODespues(int dia, int hora, int minuto) {
    if (dia == 1) {
        cout << "Es martes" << endl;
    } else if (hora >= 12) {
        cout << "No es martes, pero es después de las 12 PM" << endl;
    }
}

void cicloDias(int diaActual) {
    string dias[7] = { "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo" };

    cout << "Recorriendo los días de la semana:" << endl;
    for (int i = 0; i < 7; i++) {
        if (i == diaActual) {
            cout << "Hoy sí es " << dias[i] << endl;
        } else {
            cout << "Hoy no es " << dias[i] << endl;
        }
    }
}
