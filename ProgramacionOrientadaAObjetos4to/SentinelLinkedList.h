#pragma once
#include <iostream>
using namespace std;

template <typename T>
class SentinelLinkedList
{
public:
	SentinelLinkedList()
	{
		// El nodo NIL tiene un data X por defecto (no importa)
		NIL = new Node(T{});
		// NIL se apunta a s� mismo tanto hacia adelante como hacia atr�s.
		NIL->next = NIL;
		NIL->prev = NIL;
		count = 0;
	}

	~SentinelLinkedList()
	{
		// �OJO! El nodo centinela solamente se borra cuando se borra la lista.
		Node* nodoActual = NIL->next;
		while (nodoActual != NIL)
		{
			Node* nodoABorrar = nodoActual;
			nodoActual = nodoActual->next;
			delete nodoABorrar;
		}

		delete NIL;
		cout << "Sentinel linked list destruida con �xito" << endl;
	}

	// En esta versi�n no necesita ning�n tipo de chequeo. Adem�s es tiempo constante O(1)
	void Append(T value)
	{
		Node* newNode = new Node(value);

		// el que es el �ltimo nodo antes de insertar el nuevo ahora apunta al nuevo hacia adelante
		// OJO: el previo de NIL es el �ltimo nodo.
		NIL->prev->next = newNode;
		
		// el nuevo nodo apunta al anterior �ltimo hacia atr�s
		newNode->prev = NIL->prev;

		// NIL ahora hacia atr�s apunta al nuevo nodo.
		NIL->prev = newNode;

		// El nuevo nodo apunta a NIL hacia adelante
		newNode->next = NIL;
		count++;
	}

	// Funci�n PopBack quita y borra el �ltimo elemento de la Lista y regresa su valor.
	T PopBack()
	{
		// tenemos que checar que no est� vac�a la lista.
		if (count == 0)
		{
			cout << "Error, trataron de hacer PopBack de una lista vac�a." << endl;
			return T{}; // regresamos un valor por defecto.
		}

		// El nodo final es el prev de NIL. 
		Node* nodoABorrar = NIL->prev;
		T valorDelNodoABorrar = nodoABorrar->data;

		// hace las reconexiones entre prev's y next's y reduce el count en 1.
		Delete(nodoABorrar);

		// Regresamos el valor que almacena dicho nodo.
		return valorDelNodoABorrar;
	}

	// Funci�n Front devuelve el valor del primer elemento de la lista
	T Front()
	{
		// tenemos que checar que no est� vac�a la lista.
		if (count == 0)
		{
			cout << "Error, trataron de sacar el front de una lista vac�a." << endl;
			return T{}; // regresamos un valor por defecto.
		}
		// El nodo inicial es el next de NIL. Regresamos el valor que almacena dicho nodo.
		return NIL->next->data;
	}

	// Back devuelve el valor del �ltimo elemento de la lista.
	T Back()
	{
		// tenemos que checar que no est� vac�a la lista.
		if (count == 0)
		{
			cout << "Error, trataron de sacar el Back de una lista vac�a." << endl;
			return T{}; // regresamos un valor por defecto.
		}
		// El nodo final es el prev de NIL. Regresamos el valor que almacena dicho nodo.
		return NIL->prev->data;
	}

	// Regresa true si hay al menos un nodo con dicho value, y falso si no.
	bool Contains(T value)
	{
		Node* nodoEncontrado = Search(value);
		// si no encontramos el nodo, entonces regresamos false
		if (nodoEncontrado == nullptr)
			return false;
		// si s� lo encontramos, regresamos true.
		return true;

		// return nodoEncontrado != nullptr;
	}

	// Nos regresa los datos guardados el nodo en la i-�sima posici�n desde el inicio.
	T ObtenerValorPorIndice(size_t indice)
	{
		if (indice >= count)
		{
			cout << "Error, trataron de acceder a un �ndice inv�lido:" << indice << endl;
			return T{};
		}

		Node* nodoActual = NIL->next;
		for (int i = 0; i < indice; i++)
			nodoActual = nodoActual->next;

		return nodoActual->data;
	}
	
	// versi�n inventada que trata de llegar m�s r�pido al �ndice dependiendo de si est� en la mitad de atr�s
	// o en la mitad de adelante.
	T ObtenerValorPorIndiceOptimizada(int indice)
	{
		if (indice >= count)
		{
			cout << "Error, trataron de acceder a un �ndice inv�lido:" << indice << endl;
			return T{};
		}

		// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] // 10 nodos
		// dame el 9no t� tienes que hace 9 iteraciones
		// pero si empezaras desde el final, solo tendr�as que hacer una iteraci�n
		// si ese �ndice es mayor que la mitad del count, entonces empieza desde el final.
		// y ahora tenemos que hacer count-�ndice iteraciones.
		Node* nodoActual = nullptr;
		if(indice < count/2)
		{
			nodoActual = NIL->next;
			for (int i = 0; i < indice; i++)
				nodoActual = nodoActual->next;
		}
		else
		{
			int iteraciones = count - indice;
			nodoActual = NIL->prev;
			for (int i = 0; i < iteraciones; i++)
				nodoActual = nodoActual->prev;
		}
		
		return nodoActual->data;
	}


	void DeleteByValue(T value)
	{
		Node* nodoABorrar = Search(value);
		// si es nullptr, no se encontr� un nodo con ese value, entonces no hay nada que borrar.
		if (nodoABorrar == nullptr)
		{
			cout << "no se encontr� el valor a borrar: " << value << " en esta lista con centinela." << endl;
			return;
		}

		Delete(nodoABorrar);
	}

	/* FUNCIONES PARA EL EXAMEN QUE SE ENTREGA A M�S TARDAR EL JUEVES 6 DE NOVIEMBRE A LAS 11:59 PM*/
	void PushFront(T value)
	{
		// USTEDES HACEN LA IMPLEMENTACI�N
	}

	T PopFront()
	{
		// USTEDES HACEN LA IMPLEMENTACI�N
		return T{};
	}
	/* FIN DE FUNCIONES PARA EL EXAMEN QUE SE ENTREGA A M�S TARDAR EL JUEVES 6 DE NOVIEMBRE A LAS 11:59 PM*/


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
			prev = nullptr;
		}

		T data; // los datos que realmente se guardan en la lista
		Node* next; // cu�l nodo sigue de este nodo, en la lista ligada.
		// si next == nullptr, entonces este nodo es el �ltimo de la lista.
		Node* prev; // cu�l nodo va antes de este nodo en la lista ligada.
	};

	// funci�n privada porque la clase Node es privada, entonces no se puede usar fuera de esta clase.
	// Funci�n que busca el primer nodo con valor "value" y lo devuelve.
	Node* Search(T value)
	{
		// Empezamos desde el nodo inicial.
		// OJO: el nodo inicial es el next de NIL (NIL->next)
		Node* nodoActual = NIL->next;

		// hacemos un ciclo para iterar por toda la lista. 
		// Si el nodo actual lleg� a NIL, quiere decir que ya llegaste al final de la lista.
		while (nodoActual != NIL)
		{
			// si este nodo tiene el valor value que buscamos, entonces ya lo encontramos y retornamos el nodo.
			if (nodoActual->data == value)
			{
				return nodoActual;
			}
			nodoActual = nodoActual->next;
		}

		// Si se sali� del ciclo, quiere decir que llegaste al final de la lista.
		cout << "no se encontr� el valor: " << value << " en esta lista con centinela." << endl;
		return nullptr;
	}

	// funci�n privada porque la clase Node es privada, entonces no se puede usar fuera de esta clase.
	void Delete(Node* nodoABorrar)
	{
		// si s� se encontr�, pues vamos a borrar ese nodo.
		// Del nodoABorrar su nodo previo ahora va a apuntar hacia adelante a quien nodoABorrar apunta hacia adelante
		nodoABorrar->prev->next = nodoABorrar->next;
		// Del nodoABorrar su siguiente ahora apunta hacia atr�s al nodo que apunta actualmente hacia atr�s el nodo a borrar.
		nodoABorrar->next->prev = nodoABorrar->prev;
		count--;
	}

	Node* NIL;
	int count;
};

void DemostracionSentinelLinkedList();