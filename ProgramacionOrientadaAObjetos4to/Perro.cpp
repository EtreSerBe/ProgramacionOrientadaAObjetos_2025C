#include "Perro.h"

Perro::Perro()
{
    nombre = "perro";
    numeroDePatas = 4;
    numeroDeOjos = 2;

    ImprimirNombre();
}

void Perro::Ladrar()
{
    cout << "guau" << endl;
}

void Perro::HacerRuido()
{
    Ladrar();
}
