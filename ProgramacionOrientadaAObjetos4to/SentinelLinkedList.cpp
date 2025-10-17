#include "SentinelLinkedList.h"



void DemostracionSentinelLinkedList()
{
	// primero que todo, probar el constructor declarando una variable de este tipo.
	SentinelLinkedList<string> mySentinelLinkedList;

	// esa cosa se crea vac�a, hay que meterle alg�n elemento
	mySentinelLinkedList.Append("Juan");

	// meter un elemento nuevo cuando ya no solo est� NIL
	mySentinelLinkedList.Append("Maria");
	mySentinelLinkedList.Append("Pedro");

	// probemos a buscar un valor que s� est�
	if (mySentinelLinkedList.Contains("Maria"))
	{
		cout << "La lista con centinela S� contiene a Maria" << endl;
	}
	else
	{
		cout << "La lista con centinela NO contiene a Maria" << endl;
	}

	// probemos a buscar un valor que No est�
	if (mySentinelLinkedList.Contains("Juancho"))
	{
		cout << "La lista con centinela S� contiene a Juancho" << endl;
	}
	else
	{
		cout << "La lista con centinela NO contiene a Juancho" << endl;
	}

	cout << "el valor del nodo en posici�n -1 es: " <<  mySentinelLinkedList.ObtenerValorPorIndice(-1) << endl;

	// Probando PopBack
	cout << "haciendo pop back: " << mySentinelLinkedList.PopBack() << " se espera que el valor sea Pedro" << endl;
	cout << "haciendo pop back: " << mySentinelLinkedList.PopBack() << " se espera que el valor sea Maria" << endl;
	cout << "haciendo pop back: " << mySentinelLinkedList.PopBack() << " se espera que el valor sea Juan" << endl;
	cout << "haciendo pop back: " << mySentinelLinkedList.PopBack() << " se espera que marque error porque ya debe estar vac�a" << endl;


	

	/////////////// COSA APARTE, EJEMPLO DE C�MO HACER CASOS DE PRUEBA A GRANDES RASGOS ///////////////
	/*
	Begin with a letter.
	Use only letters (a-z, A-Z), numbers (0-9) and whitespace ( ). 
	Must be 3 to 24 characters long. 
	Not case sensitive.
	*/
	string username = "Juancho3000";
	// checamos si el primer caracter no es una letra
	bool esLetraMayuscula = (username[0] >= 65 && username[0] <= 90);
	bool esLetraMinuscula = (username[0] >= 97 && username[0] <= 122);

	if (!esLetraMinuscula && !esLetraMayuscula)
	{
		// imprimimos error porque no es una letra.
		cout << "El nombre debe comenzar con una letra pero comienza con: " << username[0] << endl;
	}
	// cadena con letra minuscula // s� debe funcionar
	// cadena con letra mayuscula // s� debe funcionar
	// cadena sin letra // debe imprimir error

	// ya sabemos checar si es letra (tanto may�scula como min�scula)
	// n�meros del 0 al 9 son del 48 al 57
	// espacio en blanco es 32
	for (int i = 0; i < username.size(); i++)
	{
		esLetraMayuscula = (username[i] >= 65 && username[i] <= 90);
		esLetraMinuscula = (username[i] >= 97 && username[i] <= 122);
		bool esUnaLetra = esLetraMayuscula || esLetraMinuscula;
		bool esNumero = (username[i] >= 48 && username[i] <= 57);
		bool esEspacioEnBlanco = username[i] == 32;
		// si alguno de ellos no es una letra Y no es un n�mero Y no es un espacio en blanco
		if (!esUnaLetra &&
			!esNumero &&
			!esEspacioEnBlanco)
		{
			cout << "El nombre contiene un caracter que no es n�mero ni letra ni espacio en blanco: " << username[i] << endl;
		}
	}
	// puras letras
	// puros n�meros (excepto el primero que tiene que ser letra)
	// puro espacio en blanco (excepto el primero que tiene que ser letra)
	// combinar letras y n�meros
	// combinar letras y espacios
	// n�meros y espacios
	// hacer algunas pruebas con may�sculas y min�sculas


	// Debe tener entre 3 y 24 caracteres.
	if (username.size() < 3 || username.size() > 24)
	{
		cout << "El nombre contiene m�s o menos caracteres que lo establecido: " << username.size() << endl;
	}
	// cadena de menos de 3
	// cadena de 3 
	// cadena de 3 < X < 24
	// cadena de 24
	// cadena de m�s de 24
}