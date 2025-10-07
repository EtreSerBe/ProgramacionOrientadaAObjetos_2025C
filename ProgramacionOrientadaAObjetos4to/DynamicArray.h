#pragma once

#include <iostream>
using namespace std;

/// <summary>
/// Un array que incrementa su tama�o autom�ticamente cuando se intenta insertar un elemento en �l,
/// pero ya est� lleno.
/// </summary>
class DynamicArray
{
public:
	static const int maxCapacity = 1024;

	DynamicArray(int capacity = 0);

	~DynamicArray();

	//Append(x) a�adir el valor x en la posici�n �ltima que se ha ocupado del array.
	// si ya est� lleno el arreglo, manda a incrementar su tama�o autom�ticamente.
	void Append(const int value) 
	{
		if (count == capacity)
		{
			int oldCapacity = capacity;
			if (capacity == 0)
				capacity = 1;
			else if (capacity * 2 < maxCapacity)
				capacity *= 2;
			else
			{
				cout << "ERROR: se excedi� el tama�o m�ximo del dynamic array" << endl;
				return;
			}
			// capacity = capacity == 0 ? 1 : capacity * 2; // este ser�a el if de una l�nea que equivale al if-else de arriba
			
			// entonces est� lleno y hay que pedir m�s memoria, copiar el arreglo actual al nuevo, y borrar el viejo.
			int *arrayConMasMemoria = new int[capacity]; // trae el doble de memoria
			for (int i = 0; i < oldCapacity; i++)
			{
				arrayConMasMemoria[i] = elements[i];
			}
			delete[] elements;

			// reasignamos nuestra variable interna de elements, a que apunte a la direcci�n del arreglo nuevo con m�s memoria.
			elements = arrayConMasMemoria;

			// En otras palabras, mandar a llamar la funci�n Resize()
		}
		elements[count] = value;
		count++; // y ahora tiene dentro 1 elementos m�s.
	}

	int ObtenerElemento(const size_t indice) const
	{
		if (indice < capacity)
			return elements[indice];
		else
			cout << "ERROR, se intent� obtener un valor en una posici�n inv�lida de este array. Posici�n: "
			<< indice << endl;
		return -INFINITY;
	}

	//unsigned variable sin signo (no puede ser negativo jam�s)
	// size_t es un unsigned long long, es decir, un n�mero de 64 bits (enorme) que no puede ser negativo
	// si usamos size_t para �ndices de arrays, no nos tenemos que preocupar por que sean valores negativos.
	void AsignarElemento(const size_t indice, const int valor)
	{
		if (indice < capacity)
			elements[indice] = valor;
		else
			cout << "ERROR, se intent� escribir un valor en una posici�n inv�lida de este array. Posici�n: "
			<< indice << endl;
	}

	// te regresa el �ndice de la posici�n en el array donde hay un elemento con valor == value
	int BuscarElemento(const int valor) const
	{
		for (int i = 0; i < count; i++)
		{
			if (elements[i] == valor)
				return i;
		}
		// si sale del for es porque checamos todos los elementos y ninguno fue == valor.
		return -1;
	}

	int QuitarUltimoElemento()
	{
		// si s� hay al menos un elemento, entonces s� lo podemos sacar.
		if (count > 0)
		{
			count--; // nos basta hacer esto para que ese �ltimo elemento ya no se pueda acceder.
			return elements[count];
		}

		// no se necesita el else porque si entr� al if de arriba entonces ya va a hacer return y no
		// llegar�a a esta parte del c�digo.
		cout << "ERROR el dynamic array estaba vac�o pero se intent� sacar un elemento de �l." << endl;
		return -INFINITY;
	}

	// Sirve para iterar sobre los elementos que tiene el array.
	int GetCount() const
	{
		return count;
	}

	void Print() const
	{
		cout << "imprimiendo Array: " << endl;
		for (int i = 0; i < count; i++)
			cout << elements[i] << ", ";
		cout << endl;
	}

private:
	// IMPORTANTE: las propiedades de elements, count, y capacity son privadas FORZOSAMENTE, por seguridad.

	// �D�nde almacenamos esos N elementos? D: 
	// No lo podemos guardar en una variable de tipo primitivo, float, int, char, etc. ah� solo cabe un valor.
	// No lo podemos guardar en un array[10] porque esa cosa tiene �nicamente y para siempre 10 elementos. Es un array de tama�o est�tico.
	// Usamos memoria din�mica para almacenar esos elementos. Porque es un array de tama�o din�mico.
	int* elements;

	// Count, es una propiedad que nos dice cu�ntos elementos hay dentro del array.
	int count;

	// Capacity, qu� tama�o tiene realmente el array (tanto usado como vac�o).
	int capacity;

	// Resize(X), es el que se encarga de cambiar el tama�o din�micamente.
	// esto involucra el proceso de:
	// 1) Pedir memoria para el nuevo arreglo m�s grande.
	// 2) copiar los elementos del viejo arreglo al nuevo arreglo.
	// 3) borrar el viejo arreglo.

};

