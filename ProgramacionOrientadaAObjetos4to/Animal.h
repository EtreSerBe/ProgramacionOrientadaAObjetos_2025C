#pragma once

#include<iostream>
using namespace std;

// La clase Animal es abstracta porque tiene al menos una funci�n virtual pura (hacerRuido)
class Animal
{
public:
	~Animal();

	int numeroDeOjos;
	int numeroDePatas;
	string nombre;

	// Una funci�n que NO lleva virtual es porque no la debe de modificar nadie m�s en la herencia.
	void ImprimirNombre();

	// Cuando una funci�n es "virtual" quiere decir que est� hecha para que las clases hijas las puedan 
	// modificar o extender.
	// virtual void HacerRuido();

	// versi�n virtual pura:
	// Ya NO puedo darle cuerpo a la funci�n.
	// Si una clase tiene una funci�n virtual pura, t� NO puedes instanciar un objeto de dicha clase.
	// Puedes tener punteros de dicha clase, pero no instancias.
	virtual void HacerRuido() = 0;

	// Si t� no le pones virtual a la funci�n de la clase padre Y en la clase hija tienes una funci�n que se llama igual
	// entonces si t� la mandas a llamar a trav�s de un puntero de la clase padre, se manda a llamar la funci�n de la clase padre
	// pero si fue a trav�s de un puntero de la clase hija, se manda a llamar la de la clase hija.
	void FuncionEnClasePadrePeroQueNoEsVirtual();
	// Nunca poner una funci�n en la clase padre que NO es virtual, pero que alguna clase hija tenga una funci�n que 
	// se llame igual.
};

