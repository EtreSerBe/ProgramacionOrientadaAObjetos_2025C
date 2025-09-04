// Incluye el c�digo (archivo, o biblioteca) que se pida. // Es b�sicamente lo mismo que el import en python o Java, 
// En este caso, est� incluyendo la biblioteca iostream.
#include <iostream>
// El namespace de "std" trae un mont�n de funcionalidades �tiles para desarrollo en c++ que son Standard. 
// De ah� su nombre STanDard STD.
using namespace std;

#include "ArchivosEjemplo.h"
#include "ArchivoEjemplo2.h"
#include "TareaEjemplo.h"



// Por qu� 'C' se llama 'C'? Porque existen los lenguajes A y B

// C++ es una alternativa al lenguaje 'C'

// por qu� se llaman archivos ".cpp"
// C Plus Plus -> C++


// Definir y Declarar
// Declara es decir: Esto existe. Esto puede ser una variable, una funci�n, una estructura, una clase, entre otros.
// Definir es decir: Qu� hace, qu� tiene dentro, para que sirve, etc.


// Declarar una variable:
int myInt = 7; // a partir de esta l�nea, el c�digo ya sabe que esta variable existe.
int myOtherInt = 5; // esta es declaraci�n Y tambi�n asignaci�n de valor.

// Intenten evitar declarar variables con el mismo nombre dentro de Contextos de ejecuci�n anidados 
/* 
int Suma(int a, int b)
{
	int resultado = a + b;
	if (resultado < 0)
	{
		int resultado2 = 0;
		cout << resultado2;
	}
	return resultado;
}
*/

int Suma(int a, int b)
{
	int resultado = a + b;
	return resultado;
}

int Resta(int a, int b)
{
	int resultado = a - b;
	return resultado;
}

int Division(int a, int b)
{
	return a / b;
}


// estos cambios los hizo juanito en su m�quina
int FuncionJuanito()
{
	cout << "esta es la maravillosa funcion de Juanito" << endl;
}

// Estos cambios los hice yo en mi m�quina.
int FuncionAdrian()
{
	cout << "esta es la funcion de Adrian" << endl;
}







// Qu� es un Main?
// �Por qu� Main? Main significa principal, se refiere a que es el punto principal de entrada de la ejecuci�n de este programa
// �Por qu� int? M�s espec�ficamente Main es una funci�n, entonces necesita cumplir con la sint�xis de una funci�n.
	// tipoDeData + Nombre +( par�metros* ) +{ otroC�digo }.
	// Main es una funci�n que debe regresar un valor entero (int).

int main()
{
	// En el main del proyecto, mandan a llamar el Main de la tarea en espec�fico que est�n entregando.
	MainTareaEjemplo();

	// Para la segunda tarea, por ejemplo, ya solo pondr�an la llamada al Main de esa nueva tarea.
	// MainTareaEjemplo2();

	// Para la tarea 3, lo mismo.
	// MainTareaEjemplo3();



	// Suma(1, 2);

	// cout est� dentro del namespace de std, por necesitamos incluirlo en el archivo.
	// cout viene de C que es Console y out que es salida. Entonces lo que hace es mandar informaci�n de salida a la consola.
	// endl es End Line, que ser�a terminar l�nea que lo que hace es pasarse a la siguiente l�nea de texto.
	// '\n' es b�sicamente lo mismo que el endl. 
	cout << "hola mundo \n hola mundo 2 \n"; 
	// cout << "hola mundo 2" << endl;
	cout << "Suma(1, -2) es: " << Suma(1, -2) << endl;
	
	cout << "Multiplicacion(2, 4) es: " << Multiplicacion(2, 4) << endl;


	cout << "Division(2, 4) es: " << Division(2, 4) << endl;


	// Retorna el c�digo de error de la ejecuci�n del Main.
	// El c�digo "0" significa que no hubo error alguno. Significa que el main termin� satisfactoriamente.
	return 0;
}


