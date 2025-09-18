#pragma once

#include <iostream>
using namespace std;



class WebPacket
{
	int payload[10]; // datos �tiles de este paquete web
	
	// datos del header (encabezado del paquete)
	int origen;
	string direccionIP;

public:
	void Inicializar(int in_origen, string in_direccionIP)
	{
		origen = origen;
		direccionIP = direccionIP;
	}

	void Inicializar(int in_origen, string in_direccionIP, int in_payload[10])
	{
		Inicializar(in_origen, in_direccionIP);
		// payload = in_payload; // esto no nos deja.
		payload[0] = in_payload[0]; // esto s�, 
		payload[1] = in_payload[1]; // esto tambi�n
		// y este for tambi�n
		for (int i = 0; i < 10; i++)
		{
			payload[i] = in_payload[i];
		}
	
		// un valor 'L' se refiere a lo que est� a la izquierda de un operador, 
		// por ejemplo a la izquierda de un '='
	}

	// al recibir el array como in_payload[], es decir, sin un n�mero entre los [], el array puede ser de cualquier tama�o
	void Inicializar(int in_origen, string in_direccionIP, int in_payload[], int tamanio_payload)
	{
		if (tamanio_payload > 10)
		{
			cout << "error, el tama�o del payload recibido es mayor que la capacidad del payload del Packet" << endl;
			return; // le damos return para salirnos de la funci�n y no hacer nada m�s, porque si no dar�a error.
		}

		Inicializar(in_origen, in_direccionIP);
		for (int i = 0; i < tamanio_payload; i++)
		{
			payload[i] = in_payload[i];
		}
	}

	// inicioDeEscritura es en qu� posici�n de nuestro payload se va a comenzar a poner lo del in_payload recibido.
	void SetearPayload(int in_payload[], int tamanio_payload, int inicioDeEscritura)
	{
		if (tamanio_payload + inicioDeEscritura > 10)
		{
			cout << "error, el tama�o del payload recibido m�s el inicio de escritura es mayor que la capacidad del payload del Packet" << endl;
			return; // le damos return para salirnos de la funci�n y no hacer nada m�s, porque si no dar�a error.
		}

		// las direcciones de memoria tambi�n son bits/bytes, entonces tambi�n se les puede hacer aritm�tica.
		//payload += 1 = payload[1]
		//payload += 2 = payload[2]

		// como queremos que empiece a escribir a partir de inicioDeEscritura, pues ponemos el valor inicial de 'i' igual a ello.
		for (int i = inicioDeEscritura; i < tamanio_payload; i++)
		{
			// a la direcci�n de memoria que est� i*(tama�o de entero en bytes) a la derecha del origen, as�gnale in_payload[i]
			*(payload + i) = in_payload[i]; // va entre par�ntesis porque primero queremos que mueva la direcci�n de memoria, y despu�s que nos d� lo que hay dentro.
			// el operador de indirecci�n '*' nos permite acceder al valor que est� almacenado en la direcci�n de memoria dada.
			// *payload = in_payload[0];
			// sin el punto, lo que t� est�s manejando es la pura direcci�n de memoria.
			// payload = in_payload
		}
	}


};

void MainWebPacket();