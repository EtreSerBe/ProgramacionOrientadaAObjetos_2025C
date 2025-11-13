#include "BinarySearchTree.h"


void DemostracionBinarySearchTree()
{
	BinarySearchTree<float> myBST;

	/******* PRUEBAS DE ADD DEL ÁRBOL ****************************/
	
	myBST.Add(5); // caso del árbol vacío
	myBST.Add(3); // caso de primera vez de ir a la izquierda
	myBST.Add(8); // caso de primera vez de ir a la derecha

	// casos de ir por combinaciones de izquierdas-derechas
	myBST.Add(4); 
	myBST.Add(7);
	myBST.Add(2);
	myBST.Add(9);

	myBST.InOrderRecursivo();

	myBST.PreOrderRecursivo();

	myBST.PostOrderRecursivo();

	// Buscamos el valor 6, que sabemos que no está en el árbol.
	bool seisEstaEnElArbol = myBST.Find(6); // se espera que sea false.
	if (seisEstaEnElArbol)
	{
		cout << "el valor 6 sí está en el árbol. \n";
	}
	else
	{
		cout << "el valor 6 no está en el árbol. \n";
	}

	bool cuatroEstaEnElArbol = myBST.Find(4); // se espera que sea true.
	if (cuatroEstaEnElArbol)
	{
		cout << "el valor 4 sí está en el árbol. \n";
	}
	else
	{
		cout << "el valor 4 no está en el árbol. \n";
	}

	float maxValue = myBST.MaxValue(); // se espera que sea 9
	cout << "El valor más alto del árbol es: " << maxValue << endl;

	float minValue = myBST.MinValue(); // se espera que sea 2
	cout << "El valor más bajo del árbol es: " << minValue << endl;

	pair<float, float> minimoYMaximo = myBST.ObtenerMinimoYMaximo();
	cout << "El valor más alto del árbol es: " << minimoYMaximo.second << 
		"; el más bajo es: " << minimoYMaximo.first << endl;

	float* raizMinimoYMaximo = myBST.ObtenerRaizMinimoYMaximo();
	cout << "La raíz del árbol es: " << raizMinimoYMaximo[0]
		<< " El valor más alto del árbol es: " << raizMinimoYMaximo[2] <<
		"; el más bajo es: " << raizMinimoYMaximo[1] << endl;
	
	delete[] raizMinimoYMaximo;

	vector<float> raizMinimoYMaximoConVector = myBST.ObtenerRaizMinimoYMaximoConVector();
	cout << "La raíz del árbol es: " << raizMinimoYMaximoConVector[0]
		<< " El valor más alto del árbol es: " << raizMinimoYMaximoConVector[2] <<
		"; el más bajo es: " << raizMinimoYMaximoConVector[1] << endl;


	// Pruebas de Sucesor
	// Casos 1	
	cout << "el siguiente de 3 debe ser 4 y fue: " << myBST.Siguiente(3) << endl; // Debe ser 4
	cout << "el siguiente de 5 debe ser 7 y fue: " << myBST.Siguiente(5) << endl; // Debe ser 7
	cout << "el siguiente de 8 debe ser 9 y fue: " << myBST.Siguiente(8) << endl;  // Debe ser 9

	// Casos 2
	cout << "el siguiente de 2 debe ser 3 y fue: " << myBST.Siguiente(2) << endl;  // Debe ser 3
	cout << "el siguiente de 4 debe ser 5 y fue: " << myBST.Siguiente(4) << endl;  // Debe ser 5
	cout << "el siguiente de 9 debe ser nullptr y fue: " << myBST.Siguiente(9) << endl;  // Debe ser nullptr


	// Pruebas de Predecesor
	// Casos 1	
	cout << "el predecesor de 3 debe ser 2 y fue: " << myBST.Anterior(3) << endl; // Debe ser 2
	cout << "el predecesor de 5 debe ser 4 y fue: " << myBST.Anterior(5) << endl; // Debe ser 4
	cout << "el predecesor de 8 debe ser 7 y fue: " << myBST.Anterior(8) << endl;  // Debe ser 7

	// Casos 2
	cout << "el predecesor de 2 debe ser nullptr y fue: " << myBST.Anterior(2) << endl;  // Debe ser nullptr
	cout << "el predecesor de 4 debe ser 3 y fue: " << myBST.Anterior(4) << endl;  // Debe ser 5
	cout << "el predecesor de 9 debe ser 8 y fue: " << myBST.Anterior(9) << endl;  // Debe ser 8



	// Para el caso 1 del borrado de nodos, necesitamos un nodo que no tenga hijos, por ejemplo el '2'
	myBST.BorrarPorValor(2); // Debe quitar al 2, que es hijo izquierdo del nodo 3.
	
	cout << "Despues de haber borrado al 2" << endl;
	myBST.InOrderRecursivo();


	// Para el caso 2, tenemos que borrar a alguien que solo tiene un hijo, por ejemplo el '3' que ya solo
	// tiene de hijo al 4, porque ya borramos al 2.
	myBST.BorrarPorValor(3);

	cout << "Despues de haber borrado al 3" << endl;
	myBST.InOrderRecursivo();


	myBST.Add(3); // caso de manejo de valores repetidos.
}