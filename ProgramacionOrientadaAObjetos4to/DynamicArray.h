#pragma once


/// <summary>
/// Un array que incrementa su tamaño automáticamente cuando se intenta insertar un elemento en él,
/// pero ya está lleno.
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
			// entonces está lleno y hay que pedir más memoria, copiar el arreglo actual al nuevo, y borrar el viejo.
			// En otras palabras, mandar a llamar la función Resize()
			// NOS QUEDAMOS EL DÍA 25 DE SEPTIEMBRE
		}
		elements[count] = value;
		count++; // y ahora tiene dentro 1 elementos más.
	}

	//Append(x) añadir el valor x en la posición última que se ha ocupado del array.
	// si ya está lleno el arreglo, manda a incrementar su tamaño automáticamente.

private:
	// IMPORTANTE: las propiedades de elements, count, y capacity son privadas FORZOSAMENTE, por seguridad.

	// ¿Dónde almacenamos esos N elementos? D: 
	// No lo podemos guardar en una variable de tipo primitivo, float, int, char, etc. ahí solo cabe un valor.
	// No lo podemos guardar en un array[10] porque esa cosa tiene únicamente y para siempre 10 elementos. Es un array de tamaño estático.
	// Usamos memoria dinámica para almacenar esos elementos. Porque es un array de tamaño dinámico.
	int* elements;

	// Count, es una propiedad que nos dice cuántos elementos hay dentro del array.
	int count;

	// Capacity, qué tamaño tiene realmente el array (tanto usado como vacío).
	int capacity;

	// Resize(X), es el que se encarga de cambiar el tamaño dinámicamente.
	// esto involucra el proceso de:
	// 1) Pedir memoria para el nuevo arreglo más grande.
	// 2) copiar los elementos del viejo arreglo al nuevo arreglo.
	// 3) borrar el viejo arreglo.

};

