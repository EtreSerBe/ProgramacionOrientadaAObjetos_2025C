#pragma once


template <typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList()
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}

	void Append(T value)
	{
		// checamos si est� vac�a
		if (first == nullptr) // o lo podr�amos hacer con el count if(count == 0)
		{
			// si s� est� vac�a creamos el nuevo nodo, 
			Node* newNode = new Node(value);
			first = newNode;
			// Como es el �nico nodo, no solo es el primero, tambi�n es el �ltimo
			last = newNode;
			count++;
			return;
		}

		// tomamos last y hacemos la conexi�n de este nuevo nodo
		Node* newNode = new Node(value);
		// este nuevo nodo, hacia atr�s tiene al �ltimo actual
		newNode->prev = last;
		// el siguiente del �ltimo actual ahora es el nuevo nodo
		last->next = newNode;
		// finalmente, el apuntador al �ltimo nodo ahora apunta al nuevo nodo.
		last = newNode;
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
			prev = nullptr;
		}

		T data; // los datos que realmente se guardan en la lista
		Node* next; // cu�l nodo sigue de este nodo, en la lista ligada.
		// si next == nullptr, entonces este nodo es el �ltimo de la lista.
		Node* prev; // cu�l nodo va antes de este nodo en la lista ligada.
	};

	Node* first;
	Node* last;
	int count;

};

