#pragma once
#include <iostream>
using namespace std;

// Las cosas templates S� pueden dejar la declaraci�n Y definici�n en el .h

//template <typename T>
//class Node
//{
//	T data;
//	Node<T>* next;
//};
//
//template <typename T>
//class Node
//{
//	T data;
//	Node<T>* parent;
//	Node<T>* right;
//	Node<T>* left;
//};


template <typename T>
class LinkedList
{
public:
	LinkedList()
	{
		count = 0; // si inicia vac�a, su count ser�a 0.
		// y si va a empezar vac�a, no necesitamos pedir memoria para el primer elemento.
		first = nullptr; // como no se va a usar ahorita todav�a, lo ponemos como nullptr.
	}

	// A�ade un nodo con el valor "value" al final de la lista ligada.
	void Append(const T value)
	{
		// tenemos que checar el caso en el que first es nullptr. Es decir, cuando la lista est� vac�a.
		if (first == nullptr)
		{
			first = new Node(value);
			count++;
			return; // ya lo pusimos al frente y despu�s de �l es nullptr, entonces ya es el primero de la lista (y tambi�n el �ltimo)
		}

		// comenzamos al inicio de la lista (el nodo first)
		Node* nodoActual = first;
		// y avanzamos el "next" de los nodos, hasta el final de la lista (cuando el next del nodo actual sea nullptr)
		// nodoActual se va convirtiendo en SU next hasta que ya sea nullptr.
		while (nodoActual->next != nullptr)
		{
			nodoActual = nodoActual->next; // el nodo actual se mueve al que le sigue en la lista.
		}

		// cuando se sale de este while, es que ya llegamos al final de la lista.
		// y entonces a�adimos un nuevo nodo con el valor value.
		Node* nuevoNodo = new Node(value);
		// El nodo que antes era el �ltimo, ahora es el pen�ltimo, 
		// y nuevoNodo es el �ltimo (porque su next es nullptr).
		nodoActual->next = nuevoNodo;
		count++;
	}

	// funci�n que nos da el valor (los datos) del Nodo i-�simo de la lista.
	T GetByIndex(const size_t indice) const  // como es size_t no puede ser negativo.
	{
		if (indice >= count)
		{
			cout << "ERROR: intentando acceder a un nodo con un �ndice inv�lido." << endl;
			return T{}; // retornamos un valor por defecto.
		}

		// necesitamos acceder desde el first, 
		Node* nodoActual = first;

		// y desde �l avanzar n posiciones, hacer n movimientos hacia el next, con n = indice.
		for (int i = 0; i < indice; i++)
		{
			nodoActual = nodoActual->next;
		}
		// ya llegaste al i-�simo que te pidieron, y retornas su valor
		return nodoActual->data;
	}

private:
	// clase anidada.
	// Sirve para que este node en espec�fico solo exista dentro de las funciones de la clase LinkedList.
	class Node
	{
	public:
		Node(T _data)
		{
			data = _data;
			next = nullptr;
		}

		T data; // los datos que realmente se guardan en la lista
		Node* next; // cu�l nodo sigue de este nodo, en la lista ligada.
		// si next == nullptr, entonces este nodo es el �ltimo de la lista.
	};

	Node* first; // el puntero al primer nodo de nuestra lista.
	int count; // cu�ntos elementos tiene dentro esta lista.

};

void DemostracionLinkedList();