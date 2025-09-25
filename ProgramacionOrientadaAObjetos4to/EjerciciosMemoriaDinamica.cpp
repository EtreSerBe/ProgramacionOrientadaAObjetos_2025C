#include "EjerciciosMemoriaDinamica.h"

#include<iostream>
using namespace std;

void MainEjemplosMemoriaDinamica()
{
	// me da memoria del tama�o de un int, en alguna direcci�n de memoria aleatoria.
	// la variable myNewInt es la que nos dice cu�l fue esa direcci�n de memoria.
	int* myNewInt = new int;

	// ac� le damos un valor a la variable que est� en esa direcci�n de memoria.
	*myNewInt = 5;

	int* myIntPointer = myNewInt; // estas dos variables apuntan a la misma direcci�n de memoria.

	// cuando ya no la necesites, tienes que liberar esa memoria de la variable
	delete myNewInt;
	// lo que hay que hacer es poner el valor del puntero DE TODOS LOS PUNTEROS QUE APUNTABA A ESA DIRECCI�N, como nullptr.
	myIntPointer = nullptr;
	myNewInt = nullptr;

	// *myNewInt = 10; // truena porque no tienes permiso de escritura en esa direcci�n porque ya hiciste delete.


	// este sigue apuntando a la direcci�n de memoria que se hab�a obtenido con el new, pero ah� dentro de esa direcci�n
	// ya no hay datos v�lidos, se borraron al hacer el delete.
	// Dangling pointer = puntero colgante, significa que un puntero cree que todav�a apunta a algo v�lido, pero ya no lo es.
	if (myIntPointer == nullptr)
		return;

	*myIntPointer = 10; // ? s� te deja escribir, porque la direcci�n de memoria NO est� reservada, pero no deber�as!


	// NO SE PUEDE HACER DELETE A MEMORIA EST�TICA
	int myNormalInt = 10;
	int* ptrToNormalInt = &myNormalInt; // esto de aqu� no es memoria din�mica, no se le necesita hacer delete
	// delete ptrToNormalInt; // esto apunta a una variable de memoria est�tica, y por lo tanto truena tu programa si le intentas hacer delete.
	cout << "myNormalInt" << myNormalInt << endl;

	myNormalInt = NULL;
	ptrToNormalInt = nullptr;
	// if (myNormalInt == nullptr) // una variable no-puntero no se puede comparar contra nullptr.

}

void ParOImparParaEnteros(int intArray[], int tamano)
{
	// usen un puntero auxiliar para manejar las direcciones de memoria y no modificar a array directamente.
	int* ptrAuxiliar = intArray;
	// iterar por todos los elementos del array y le pongamos el resultado de %2 a cada elemento.
	for (int i = 0; i < tamano; i++)
	{
		*ptrAuxiliar = *ptrAuxiliar % 2;
		ptrAuxiliar++;
	}

	for (int i = 0; i < tamano; i++)
	{
		// estas dos l�neas son exactamente igual de v�lidas.
		*(ptrAuxiliar + i) = *(ptrAuxiliar + i) % 2;
		ptrAuxiliar[i] = ptrAuxiliar[i] % 2;
	}

}
