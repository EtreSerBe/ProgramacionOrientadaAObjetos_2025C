#pragma once

#include<iostream>
using namespace std;

// NOTA: Como queue es template, aqu� S� pongo declaraci�n Y definici�n de las funciones en el .h, 
// porque si no es un dolor de cabeza.

template <typename T>
class Queue
{

public:
	Queue(int in_capacity)
	{
		capacity = in_capacity;
		// si s� va a tener elementos, se pide capacity-memoria para almacenar.
		if (capacity > 0)
			elements = new T[capacity];
		else // y si no, se pone nullptr por seguridad.
			elements = nullptr;
		count = 0;
	}

	~Queue()
	{
		// si s� se hab�a pedido memoria din�mica, la liberamos.
		if (capacity > 0)
			delete[] elements;
	}

	// mete un elemento al final de la fila (�ndice tail)
	void Enqueue(T value)
	{
		// antes de meter un elemento, hay que checar si s� cabe o no.
		if (count == capacity)
		{
			int oldCapacity = capacity;
			// entonces est� lleno.
			if (capacity == 0)
				capacity = 1;
			else
				capacity *= 2;
			// capacity = capacity == 0 ? 1 : capacity * 2; // este ser�a el if de una l�nea que equivale al if-else de arriba

			// entonces est� lleno y hay que pedir m�s memoria, copiar el arreglo actual al nuevo, y borrar el viejo.
			T* arrayConMasMemoria = new T[capacity]; // trae el doble de memoria
			// en vez de copiarlos desde el 0, los copiamos desde el head, para que queden ordenaditos de una vez 
			// en el nuevo array. 
			for (int i = 0; i < oldCapacity; i++)
			{
				int indiceDeLaFilaOrigen = (head + i) % oldCapacity; // AGUAS: aqu� va oldCapacity, no la capacity normal.
				arrayConMasMemoria[i] = elements[indiceDeLaFilaOrigen];
			}
			delete[] elements;

			// reasignamos nuestra variable interna de elements, a que apunte a la direcci�n del arreglo nuevo con m�s memoria.
			elements = arrayConMasMemoria;

			// Es necesario reajustar head y tail.
			head = 0;
			tail = oldCapacity;
		}

		// en el �ndice tail pon el valor value recibido
		elements[tail] = value;

		// movemos uno a la derecha el �ndice tail
		tail++;

		// despu�s, checa si necesitas ciclarlo a 0.
		tail %= capacity;
		// si tail es 2, y capacity es 3; 2 entre 3 es 0, te sobran 2, entonces tail se queda en 2
		// si tail es 3, y capacity es 3; 3 entre 3 es 1, te sobran 0, entonces tail ahora es 0, se cicl� al inicio del array.

		// e incrementamos count
		count++;
	}

	// Quita el elemento del inicio de la fila (�ndice head)
	T Dequeue()
	{
		// si no hay elementos, no podemos sacar nada, es un error.
		if (count <= 0)
		{
			cout << "ERROR: se intent� hacer Dequeue cuando est� vac�a.";
			return T{}; // esto es: dame el elemento de tipo T por defecto.
		}

		// si s� hay al menos un elemento, entonces s� lo podemos sacar.
		T front = elements[head]; // obtenemos el valor que est� en el �ndice head
		head++; // movemos head uno a la derecha
		head %= capacity; // ciclamos a 0 si es necesario.

		// decrementamos count
		count--;

		// finalmente regresamos el valor que estaba antes al frente.
		return front;
	}

	// Retorna el elemento del frente de la fila, pero sin quitarlo.
	T Front()
	{
		// si no hay elementos, no podemos sacar nada, es un error.
		if (count <= 0)
		{
			cout << "ERROR: se intent� hacer Front de la Queue cuando est� vac�a. " << endl;
			return T{}; // esto es: dame el elemento de tipo T por defecto.
		}

		// si s� hay al menos un elemento, entonces s� lo podemos checar.
		T front = elements[head]; // obtenemos el valor que est� en el �ndice head

		// finalmente regresamos el valor que est� al frente.
		return front;
	}

	//
	void Print()
	{
		cout << "imprimiendo Queue: " << endl;
		// aqu� tenemos que imprimir desde head hasta tail. Usamos head + i, pero lo cicla a 0 usando el %capacity
		for (int i = 0; i < count; i++)
			cout << elements[(head + i) % capacity] << ", ";
		cout << endl;
	}

	int GetCount()
	{
		return count;
	}

private:
	// un puntero donde se guardan los datos.
	T* elements;

	// cu�ntos elementos hay dentro
	int count;

	// cu�ntos elementos realmente caben
	int capacity;

	// el �ndice de inicio y de final de la fila 
	int head; // Inicio
	int tail; // Final.

};

void MainQueues();
