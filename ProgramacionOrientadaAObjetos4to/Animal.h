#pragma once

#include<iostream>
using namespace std;

// La clase Animal es abstracta porque tiene al menos una función virtual pura (hacerRuido)
class Animal
{
public:
	int numeroDeOjos;
	int numeroDePatas;
	string nombre;

	void ImprimirNombre();

	// Cuando una función es "virtual" quiere decir que está hecha para que las clases hijas las puedan 
	// modificar o extender.
	// virtual void HacerRuido();

	// versión virtual pura:
	// Ya NO puedo darle cuerpo a la función.
	// Si una clase tiene una función virtual pura, tú NO puedes instanciar un objeto de dicha clase.
	// Puedes tener punteros de dicha clase, pero no instancias.
	virtual void HacerRuido() = 0;

};

