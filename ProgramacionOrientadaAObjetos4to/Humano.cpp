#include "Humano.h"
#include "Perro.h"
#include "Gato.h"
#include "Pollo.h"

Humano::Humano()
{
    numeroDeOjos = 2;
    numeroDePatas = 2;
    nombre = "Humano";

    ImprimirNombre();
}

void Humano::Hablar()
{
    cout << "Rechapos" << endl;
}

void Humano::HacerRuido()
{
    Hablar();
}

void DemostracionHerenciaDeClases()
{
    Perro myPerro;
    myPerro.Ladrar();
    myPerro.HacerRuido();

    Gato myGato;
    myGato.Maullar();
    myGato.HacerRuido();

    // C�digo de error E0322->
    // Si les dice que la funci�n X virtual pura no tiene ning�n elemento que la invalide,
    // eso quiere decir que hay alguna funci�n virtual pura en las clases de las que hereda,
    // que esta clase NO ha hecho override. Por eso dice que la clase es abstracta.
    // La soluci�n es hacerle override a las funciones que te diga y darles cuerpo (definici�n).

    Humano myHumano;
    myHumano.Hablar();
    myHumano.HacerRuido();

    Pollo myPollo;

    // Con una variable del tipo de la clase base, t� puedes apuntar a una variable de cualquier clase hija.
    Animal* animalHumano = &myHumano;
    animalHumano->HacerRuido();

    Animal* arrayAnimales[4] = { &myPerro, &myGato, &myHumano, &myPollo };
    for (int i = 0; i < 4; i++)
        arrayAnimales[i]->HacerRuido();

}
