#include "Gato.h"

Gato::Gato()
{
    numeroDeOjos = 2;
    numeroDePatas = 4;
    nombre = "Gato";

    ImprimirNombre();
}


void Gato::Maullar()
{
    cout << "Meow" << endl;
}

void Gato::HacerRuido()
{
    Maullar();
}
