#pragma once

#include<iostream>
using namespace std;

// La clase Animal es abstracta porque tiene al menos una funci�n virtual pura (hacerRuido)
class Animal
{
public:
	int numeroDeOjos;
	int numeroDePatas;
	string nombre;

	void ImprimirNombre();

	// Cuando una funci�n es "virtual" quiere decir que est� hecha para que las clases hijas las puedan 
	// modificar o extender.
	// virtual void HacerRuido();

	// versi�n virtual pura:
	// Ya NO puedo darle cuerpo a la funci�n.
	// Si una clase tiene una funci�n virtual pura, t� NO puedes instanciar un objeto de dicha clase.
	// Puedes tener punteros de dicha clase, pero no instancias.
	virtual void HacerRuido() = 0;

};

