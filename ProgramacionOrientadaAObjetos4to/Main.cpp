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
	return 0;
}

// Estos cambios los hice yo en mi m�quina.
int FuncionAdrian()
{
	cout << "esta es la funcion de Adrian" << endl;
	return 0;
}


enum TipoDeUsuario
{
	Alumno=0,
	Profesor,
	Admin = 255,
	Otro
};

//enum TipoDeUsuarioBanderas
//{
//	Alumno = 1,
//	Profesor = 2,
//	Admin = 4,
//	Otro = 8,
//};

//[0000 0011] // nuestro usuario
//[0000 0110] // m�scara de bits para checar si eres del tipo "Admin" o un profe
//
//[0000 0010] // AND L�GICO que es como el &&


void FuncionPila1();

void FuncionPila2();

void FuncionPila3();


struct Rectangulo
{
	float alto;
	float ancho;
};


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


	TipoDeUsuario tipoDeUsuario = TipoDeUsuario::Alumno;
	switch (tipoDeUsuario)
	{
	case Alumno:
		cout << "switch es alumno " << endl;
		tipoDeUsuario = TipoDeUsuario::Profesor;
		break;
	case Profesor:
		cout << "switch es profe " << endl;
		break;
	case Admin:
		cout << "switch es admin " << endl;
		break;
	default:
		{
			cout << "ERROR O WARNING: switch cay� en default porque tra�a el valor: " << tipoDeUsuario << endl;
			// return 0; // Return es: salte de la funci�n donde est� puesto. Te lleva a la llave de cierre de la funci�n en donde est�.
		}
	}

	// Programaci�n defensiva es hacer c�digo que 
	// 1) Toma en cuenta los casos extremos o los poco comunes, o los nulos o los valores inv�lidos
	// 2) Que si falla algo, no va a fallar todo el programa
	// 3) Y que si falla, va a dejar un rastro de d�nde fall�
	// 4) Y que va a tratar de recuperarse lo mejor posible.

	for (int x = 0; x < 10; x++)
	{
		cout << "antes del for de Y" << endl;

		for (int y = 0; y < 10; y++)
		{
			if (y < 4)
				continue;

			cout << "antes del break dentro del for de Y, y es: " << y << endl;
			if (y == 5)
			{
				break; // te saca del scope del ciclo dentro del cual est�, salt�ndose todo lo que est� debajo.

			} // esta es la llave de cierre del If, que el if es condicional pero no es un ciclo.
			cout << "despu�s del break dentro del for de Y, y es: " << y << endl;
		}// esta es la llave de cierre del for (de la Y) que s� es un ciclo.

		cout << "despu�s del for de Y" << endl;
	}

	// Operadores l�gicos
	// && (operador AND) ambos tienen que ser verdad para que el resultado sea verdad
	// || (operador OR) cualquiera de los dos tienen que ser verdad para que el resultado sea verdad
	// ! (operador NOT) invierte el valor de verdad de a quien se le use
	// bool myBool = true;
	// if(myBool != true)
	// XOR es uno de los dos valores tiene que ser verdad, pero el otro no. Existe la palabra clave en c++ "xor".
	// if( (x==true && y == false) ||  
	// 	(x==false && y == true))

	// La pila de llamadas le dice al programa d�nde va la ejecuci�n, y a d�nde regresar una vez que acabe 
	// con la funci�n que est� ejecutando actualmente
	FuncionPila1();


	Rectangulo myRectangulo;
	myRectangulo.alto = 5.0f;
	myRectangulo.ancho = 3.0f;

	Rectangulo myOtherRectangulo;



	// Return es: salte de la funci�n donde est� puesto. Te lleva a la llave de cierre de la funci�n en donde est�.

	// Retorna el c�digo de error de la ejecuci�n del Main.
	// El c�digo "0" significa que no hubo error alguno. Significa que el main termin� satisfactoriamente.
	return 0;
}





void FuncionPila1()
{
	cout << "funci�n pila 1 \n";
	FuncionPila2();
}

void FuncionPila2()
{
	cout << "funci�n pila 2 \n";
	FuncionPila3();
}

void FuncionPila3()
{
	cout << "funci�n pila 3 \n";
}