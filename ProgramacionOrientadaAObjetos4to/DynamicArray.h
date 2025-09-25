#pragma once


/// <summary>
/// Un array que incrementa su tama�o autom�ticamente cuando se intenta insertar un elemento en �l,
/// pero ya est� lleno.
/// </summary>
class DynamicArray
{
public:
	DynamicArray(int capacity);

	~DynamicArray();

	void Append(int value)
	{
		if (count == capacity)
		{
			// entonces est� lleno y hay que pedir m�s memoria, copiar el arreglo actual al nuevo, y borrar el viejo.
			// En otras palabras, mandar a llamar la funci�n Resize()
			// NOS QUEDAMOS EL D�A 25 DE SEPTIEMBRE
		}
		elements[count] = value;
		count++; // y ahora tiene dentro 1 elementos m�s.
	}

	//Append(x) a�adir el valor x en la posici�n �ltima que se ha ocupado del array.
	// si ya est� lleno el arreglo, manda a incrementar su tama�o autom�ticamente.

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

