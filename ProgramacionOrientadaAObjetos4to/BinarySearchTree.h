#pragma once
#include <iostream>
using namespace std;


template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree()
	{
		root = nullptr;
	}

	// A�ade un elemento de tipo T al �rbol.
	void Add(T value)
	{
		// Si no hay nodo ra�z... 
		if (root == nullptr)
		{
			// entonces este valor se va a convertir en el nodo ra�z.
			root = new Node(value);
			return; // y nos salimos porque ya lo insertamos.
		}

		// Se mueve por el �rbol usando izquierda-derecha hasta encontrar un lugar en el �rbol que est� vac�o.
		// Necesitamos una variable que representa el nodo contra el cual se est� comparando value en cada iteraci�n
		Node* nodoActual = root;
		// while(true) es que se ejecute infinitamente,
		// entonces DEBE haber algo dentro del while que nos permita salir de �l.
		while (true) 
		{
			// Si me tengo que ir a la derecha Y el hijo derecho del NodoActual es nullptr...
			// si el valor de value es mayor que el del nodo actual...
			if (value > nodoActual->value)
			{
				// ... entonces me tengo que ir a la derecha, 
				// PERO primero checo si el nodo a la derecha del actual NO es nullptr
				if (nodoActual->rightChild != nullptr)
				{
					nodoActual = nodoActual->rightChild;
					continue; // continue te devuelve al inicio del while.
				}
				else // si no tiene hijo derecho...
				{
					// ... entonces value se convierte en el hijo derecho del nodo actual.
					Node* nodoConNuevoValor = new Node(value);
					nodoActual->rightChild = nodoConNuevoValor;
					// El nuevo nodo ahora apunta al nodo actual como su padre
					nodoConNuevoValor->parent = nodoActual;
					// Ya que metimos el nuevo nodo, ya acabamos la funci�n y nos salimos.
					return;
				}
			}
			// NOTA 2: Su compa�ero Juan Alexis se lleva 5 puntos extras en el parcial final por haber notado el problema con anticipaci�n.
			// NOTA: PARA EL CASO DE LA CLASE, ESTE �RBOL VA A TRATAR A LOS VALORES IGUALES MAND�NDOLOS A LA IZQUIERDA
			// VA A HABER OCASIONES EN LAS QUE LOS �RBOLES NO PERMITAN REPETIDOS.
			else if (value <= nodoActual->value) // si fuimos menores O IGUALES ... 
			{
				// ... entonces nos tenemos que ir a la izquierda
				// PERO primero checo si el nodo a la izquierda del actual NO es nullptr
				if (nodoActual->leftChild != nullptr)
				{
					// entonces S� tiene un hijo izquierdo
					nodoActual = nodoActual->leftChild;
					continue; // continue te devuelve al inicio del while.
				}
				else // si no tiene hijo izquierdo...
				{
					// ... entonces value se covierte en el hijo izquierdo del nodo actual.
					Node* nodoConNuevoValor = new Node(value);
					nodoActual->leftChild = nodoConNuevoValor;
					// El nuevo nodo ahora apunta al nodo actual como su padre
					nodoConNuevoValor->parent = nodoActual;
					// Ya que metimos el nuevo nodo, ya acabamos la funci�n y nos salimos.
					return;
				}
			}
		}
	}

	// Es la versi�n p�blica de la funci�n, que un usuario puede utilizar.
	// La otra de InOrderRecursivo NO es p�blica porque los usuarios no deben manipular nodos del �rbol 
	// directamente nunca.
	void InOrderRecursivo()
	{
		cout << "In order Recursivo: ";
		InOrderRecursivo(root);
		cout << endl;
	}

	void PreOrderRecursivo()
	{
		cout << "Pre order Recursivo: ";
		PreOrderRecursivo(root);
		cout << endl;
	}

	void PostOrderRecursivo()
	{
		cout << "Post order Recursivo: ";
		PostOrderRecursivo(root);
		cout << endl;
	}

private:
	// Cada nodo pesa 3 punteros (8 bytes por puntero en un sistema operativo de 64 bits)
	// m�s los bytes que pese T. Entonces los �rboles gastan  mucha m�s memoria que los arrays.
	class Node
	{
	public:
		Node(T _value)
		{
			value = _value;
			parent = nullptr;
			rightChild = nullptr;
			leftChild = nullptr;
		}

		T value;
		// Puntero hacia el Nodo padre. 
		Node* parent;
		// Puntero hacia el hijo derecho
		Node* rightChild;
		// puntero hacia el hijo izquierdo
		Node* leftChild;
	};


	void InOrderRecursivo(Node* nodoActual)
	{
		// Si el nodo actual no es nullptr ...
		if (nodoActual != nullptr)
		{
			// ... entonces mandamos a llamar esta misma funci�n pero con el hijo izquierdo del actual
			InOrderRecursivo(nodoActual->leftChild);
			// Visitamos al nodo actual (en este caso visitar significa imprimir su valor)
			cout << nodoActual->value << ", ";
			// mandamos a llamar esta misma funci�n pero con el hijo derecho del actual
			InOrderRecursivo(nodoActual->rightChild);
		}
	}

	void PreOrderRecursivo(Node* nodoActual)
	{
		// Si el nodo actual no es nullptr ...
		if (nodoActual != nullptr)
		{
			// ... entonces 
			// Visitamos al nodo actual (en este caso visitar significa imprimir su valor)
			cout << nodoActual->value << ", ";

			//mandamos a llamar esta misma funci�n pero con el hijo izquierdo del actual
			PreOrderRecursivo(nodoActual->leftChild);

			// mandamos a llamar esta misma funci�n pero con el hijo derecho del actual
			PreOrderRecursivo(nodoActual->rightChild);
		}
	}

	void PostOrderRecursivo(Node* nodoActual)
	{
		// Si el nodo actual no es nullptr ...
		if (nodoActual != nullptr)
		{
			// ... entonces mandamos a llamar esta misma funci�n pero con el hijo izquierdo del actual
			PostOrderRecursivo(nodoActual->leftChild);
			// mandamos a llamar esta misma funci�n pero con el hijo derecho del actual
			PostOrderRecursivo(nodoActual->rightChild);
			// Visitamos al nodo actual (en este caso visitar significa imprimir su valor)
			cout << nodoActual->value << ", ";
		}
	}


	/********************************************************/
	/*
	1) Implementar la funci�n "Search" del Binary Search Tree de manera iterativa (10 puntos).

	2) Implementar una funci�n de la clase Binary Search Tree una funci�n que haga:
		1.Viaja al sub-�rbol izquierdo de este nodo, recursivamente.
		2.Viaja al sub-�rbol derecho de este nodo, recursivamente.
		3.borra el nodo actual.
	Puede ser recursiva (20 puntos) o iterativa (30 puntos). D�nle un nombre apropiado.

	3) Implementar la funci�n Post-order del Binary Search Tree de manera iterativa. (10 puntos). 

	*/

	/********************************************************/





	// Puntero al nodo ra�z de este �rbol
	Node* root;
	// int count;

};

void DemostracionBinarySearchTree();
