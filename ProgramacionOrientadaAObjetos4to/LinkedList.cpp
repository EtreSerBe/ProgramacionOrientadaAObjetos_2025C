#include "LinkedList.h"

#include <iostream>
using namespace std;

void DemostracionLinkedList()
{
	LinkedList<string> myLinkedList;
	myLinkedList.Append("Juan"); // para mostrar el caso donde la lista está vacía
	myLinkedList.Append("Pedro"); // este para cuando solo hay un elemento
	myLinkedList.Append("Luis"); // un tercer elemento para corroborar que el while de append está bien!
	myLinkedList.Append("Maria");

	string result = myLinkedList.GetByIndex(2); // debe de dar a Luis
}
