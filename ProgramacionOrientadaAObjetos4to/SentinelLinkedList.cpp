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

}