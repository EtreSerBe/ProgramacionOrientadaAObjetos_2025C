#include "SentinelLinkedList.h"



void DemostracionSentinelLinkedList()
{
	// primero que todo, probar el constructor declarando una variable de este tipo.
	SentinelLinkedList<string> mySentinelLinkedList;

	// esa cosa se crea vacía, hay que meterle algún elemento
	mySentinelLinkedList.Append("Juan");

	// meter un elemento nuevo cuando ya no solo está NIL
	mySentinelLinkedList.Append("Maria");
	mySentinelLinkedList.Append("Pedro");

}