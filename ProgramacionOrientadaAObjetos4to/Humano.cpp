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

Humano::~Humano()
{
    cout << "Soy el destructor de Humano, con override del destructo de Animal." << endl;
}

void Humano::Hablar()
{
    cout << "Rechapos" << endl;
}

void Humano::HacerRuido()
{
    Hablar();
}

void Humano::FuncionEnClasePadrePeroQueNoEsVirtual()
{
    cout << "Soy de la clase animal, NO hice override porque no es virtual la de la clase padre. Y soy un Humano" << endl;
}

void DemostracionHerenciaDeClases()
{
    Perro myPerro;
    myPerro.Ladrar();
    myPerro.HacerRuido();
    myPerro.FuncionEnClasePadrePeroQueNoEsVirtual();

    Gato myGato;
    myGato.Maullar();
    myGato.HacerRuido();
    myGato.FuncionEnClasePadrePeroQueNoEsVirtual();

    //// C�digo de error E0322->
    //// Si les dice que la funci�n X virtual pura no tiene ning�n elemento que la invalide,
    //// eso quiere decir que hay alguna funci�n virtual pura en las clases de las que hereda,
    //// que esta clase NO ha hecho override. Por eso dice que la clase es abstracta.
    //// La soluci�n es hacerle override a las funciones que te diga y darles cuerpo (definici�n).

    Humano myHumano;
    myHumano.Hablar();
    myHumano.HacerRuido();
    myHumano.FuncionEnClasePadrePeroQueNoEsVirtual();

    Pollo myPollo;
    myPollo.FuncionEnClasePadrePeroQueNoEsVirtual();

    // Con una variable del tipo de la clase base, t� puedes apuntar a una variable de cualquier clase hija.
    Animal* animalHumano = new Humano();
    animalHumano->HacerRuido();
    // IMPORTANTE: esta llamada imprime lo de la clase animal, porque estamos usando un puntero de tipo animal 
    // y esta funci�n no tiene virtual en el padre.
    animalHumano->FuncionEnClasePadrePeroQueNoEsVirtual(); 

    Animal* arrayAnimales[5] = { &myPerro, &myGato, &myPollo, &myHumano, animalHumano };
    for (int i = 0; i < 5; i++)
    {
        arrayAnimales[i]->HacerRuido();
        arrayAnimales[i]->FuncionEnClasePadrePeroQueNoEsVirtual();
    }

    Animal* animalPerro= new Perro();
    delete animalPerro; // este de aqu� llamar� al destructor de animal
    // este 1) Si el destructor de Animal es virtual, llamar� al destructor de Humano, 
    // que es un override del destructor virtual de animal, y despu�s al destructor de animal.
    // O 2) Si el destructor de animal NO es virtual, entonces solamente se manda a llamar el destructor de Animal,
    // �por qu�? porque lo estamos manejando a trav�s de un puntero de Animal.
    delete animalHumano; 

    Humano* HumanoHumano = new Humano();
    delete HumanoHumano;

    // Resumen de virtual y override:
    // Si la clase hija va a hacer algo distinto en esa funci�n que la clase padre, 
    // entonces la funci�n en la clase padre lleva virtual, y la funci�n en la clase hija lleva override.
    // NOTA: El destructor tambi�n cuenta como una funci�n, pero el constructor no :D 
}
