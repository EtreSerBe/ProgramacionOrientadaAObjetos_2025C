// Incluye el código (archivo, o biblioteca) que se pida. // Es básicamente lo mismo que el import en python o Java, 
// En este caso, está incluyendo la biblioteca iostream.
#include <iostream>
// El namespace de "std" trae un montón de funcionalidades útiles para desarrollo en c++ que son Standard. 
// De ahí su nombre STanDard STD.
using namespace std;

#include "ArchivosEjemplo.h"
#include "ArchivoEjemplo2.h"
#include "TareaEjemplo.h"

#include "WebPacket.h"
#include "EjerciciosMemoriaDinamica.h"
#include "ClaseConstructoresYDestructores.h"

#include "ExplicacionIfndef.h"

// aquí ya no se procesa lo del bloque #ifndef porque ya se procesó en el "ExplicacionIfndef.h" y ahí ya se definió
// el símbolo EXPLICACIONIFNDEF_H.
#ifndef EXPLICACIONIFNDEF_H
#define EXPLICACIONIFNDEF_H
// si no está definido X, entonces defíneme X

// todas las cosas que tienen # son directivas de preprocesador

// ifndef -> if undefined, "si no está definido", se procesa (para compilarse) todo el código que esté entre 
// ese #ifndef y el #endif




class ExplicacionIfndef
{
};

#endif // !EXPLICACIONIFNDEF_H


#include "ExplicacionTemplates.h"
#include "DynamicArray.h"


// Todos los defines se remplazan por el texto que tienen a la derecha.
#define TAMANO_MY_INT_ARRAY 10
#define MULTIPLICACION_2_X_3 2*3 

// aquí, lo que está entre paréntesis son parámetros, pero los parámetros que uses tienen que ser constantes, no variables.
#define MULTIPLICACION_CON_PARAMETROS(a, b) a*b

// estas de abajo sí son cosas ya más elaboradas, avanzadas, complejas, no necesito que se las aprendan ni
// que las dominen, solo que sepan que existen.
#define DEFINIR_VARIABLES float myValue1; float myValue2; float myValue3;
#define DEFINIR_VARIABLES_CON_NOMBRE(a, b, c) float a; float b; float c;


// Por qué 'C' se llama 'C'? Porque existen los lenguajes A y B

// C++ es una alternativa al lenguaje 'C'

// por qué se llaman archivos ".cpp"
// C Plus Plus -> C++


// Definir y Declarar
// Declara es decir: Esto existe. Esto puede ser una variable, una función, una estructura, una clase, entre otros.
// Definir es decir: Qué hace, qué tiene dentro, para que sirve, etc.


// Declarar una variable:
int myInt = 7; // a partir de esta línea, el código ya sabe que esta variable existe.
int myOtherInt = 5; // esta es declaración Y también asignación de valor.

// Intenten evitar declarar variables con el mismo nombre dentro de Contextos de ejecución anidados 
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

int Resta(int a, int b)
{
	int resultado = a - b;
	return resultado;
}

int Division(int a, int b)
{
	return a / b;
}


// estos cambios los hizo juanito en su máquina
int FuncionJuanito()
{
	cout << "esta es la maravillosa funcion de Juanito" << endl;
	return 0;
}

// Estos cambios los hice yo en mi máquina.
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
//[0000 0110] // máscara de bits para checar si eres del tipo "Admin" o un profe
//
//[0000 0010] // AND LÓGICO que es como el &&


void FuncionPila1();

void FuncionPila2();

void FuncionPila3();


struct Rectangulo
{
	// Por defecto, todas las propiedades de una struct son públicas.
	// public es que se puede usar esa propiedad de la clase desde cualquier instancia/objeto de dicha clase.
public:
	float alto;
	float ancho;

	// generalmente* las structs no deben llevar funciones/métodos, mientras que las classes sí.
	// *aplican casos especiales.


	bool myBool;

	// DEFINIR_VARIABLES_CON_NOMBRE(posicionx, posiciony, posicionz)
};

class RectanguloClase
{
	// Por el contrario a las structs, las classes tienen todas sus propiedades como privadas.
	// privado es que solo se puede usar dicha propiedad dentro del alcance (las '{}') de la clase donde fue declarado/definido.
	// Entonces solo sirven para cosas internas de dicha clase (o estructura).
	// Para poder acceder a ellas hay que especificarle que son públicas
// private:
public:
	float alto;
	float ancho;

	float ObtenerArea()
	{
		return alto * ancho;
	}

// protected
protected:

};



// Los parámetros de una función son los valores "externos a ella" que se le pasan para hacer un procedimiento.
int SumaDeTres(int a, int b, int c)
{
	return a + b + c;
}

// Overload = sobrecarga
// regresan el mismo tipo de dato, se llaman exactamente igual, pero reciben distintos parámetros, ya sea de tipo o cantidad
int SumaDeTres(char a, char b, int c)
{
	if(a < 'a' || a > 'z')
		// entonces no es una letra
	return a + b + c;
}

// Ejemplos básicos de sobrecarga con 2, 3 y 4 parámetros
int Suma(int a, int b)
{
	return a + b;
}

int Suma(int a, int b, int c)
{
	return a + b + c;
}

int Suma(int a, int b, int c, int d)
{
	return a + b + c + d;
}



// Caso de uso que podría ser real.
 


//string InvertirCadena(string texto)
//{
//	string invertida;
//	for (int i = texto.length() - 1; i > 0; i++)
//	{
//		invertida.append(texto.at);
//	}
//	return;
//}


// parámetros por valor y parámetros por referencia (value & reference)
// Los de valor se pasa una copia del valor de la variable.
void FuncionConParametrosPorValor(int a, int b)
{
	a = a + b;
	cout << "el valor de a ahora es: " << a << endl;
}

// si nosotros queremos que los cambios que una variable sufre dentro de una función sean permanentes, 
// lo tenemos que pasar como un parámetro por referencia.
// Lo que pasa cuando pasas un parámetro por referencia, es que realmente pasas la dirección de memoria de la variable,
// por eso es que el cambio permanece.
void FuncionConParametrosPorReferencia(int &a, int b)
{
	a = a + b;
	cout << "el valor de a, pasador por referencia, ahora es: " << a << endl;
}

// el cambio a lo que está dentro de donde apunta 'a' sí es permanente, pero los cambios a 'a' no lo son.
void FuncionConParametrosQueSonPunteros(int* a, int b)
{
	*a = *a + b; // esto modifica el valor que tiene dentro la dirección de memoria a la que apunta 'a'
	cout << "el valor de a, pasado por referencia, ahora es: " << *a << endl;

	cout << "La dirección de memoria a la que apunta a es: " << a << endl;
	a = a + b; // esto modifica la dirección de memoria a la que apunta 'a' (los mueve b*(tamañoDeInt) a la derecha en memoria)
	cout << "La dirección de memoria a la que apunta a después de sumarle b es: " << a << endl;
}



// 1) checar si es lunes, y si sí, llamar una función  que imprima: "es lunes"
void EsLunes(int dia)
{
	// esto de aquí primero manda a llamar la función y luego checa si sí es lunes.
	if (dia == 0) // 0 es lunes, digamos
	{
		cout << "es lunes" << endl;
	}
}

void ImprimirEsLunes()
{ 
	cout << "es lunes" << endl;
}


// void es un tipo de dato (técnicamente hablando). La traducción de void sería "vacío".
// cuando tú dices que el tipo de retorno de una función es void, sería que su retorno es vacío, es decir, es nada.
// Entonces no necesitan un "return". Lo pueden tener, pero solo sirve para salirse de la función.

// Qué es un Main?
// ¿Por qué Main? Main significa principal, se refiere a que es el punto principal de entrada de la ejecución de este programa
// ¿Por qué int? Más específicamente Main es una función, entonces necesita cumplir con la sintáxis de una función.
	// tipoDeData + Nombre +( parámetros* ) +{ otroCódigo }.
	// Main es una función que debe regresar un valor entero (int).

int main()
{
	DynamicArray myDArray = DynamicArray(5);

	for (int i = 0; i < 6; i++)
	{
		myDArray.Append(i);
	}



	int myArrayForTemplate[10];
	ImprimirArrayTemplate(myArrayForTemplate, 10);

	float myFloatArrayForTemplate[10];
	ImprimirArrayTemplate(myFloatArrayForTemplate, 10);

	Triangle myTriangleArrayForTemplate[10];
	ImprimirArrayTemplate(myTriangleArrayForTemplate, 10);

	char myCharArrayForTemplate[10];
	ImprimirArrayTemplate(myCharArrayForTemplate, 10);



	// cuando tú no especificas el constructor, se manda a llamar el constructor por defecto.
	Triangle myTriangle; // el constructor se manda a llamar automáticamente al declarar este objeto

	myTriangle.ImprimirTriangulo();

	// Así es como se manda a llamar un constructor manualmente. En este caso estoy mandando a llamar el constructor
	// por defecto.
	Triangle myDefaultTriangle = Triangle();


	Triangle myNonDefaultTriangle = Triangle(5, 2);

	Triangle creadoPorFuncionEnVezDeConstructor = GenerarTriangulo(5, 2);


	Triangle* ptrTriangle = new Triangle();
	// como aquí le hago delete, aquí se va a mandar a llamar el destructor de Triangle.
	delete ptrTriangle;

	// el destructor de los Triangle de memoria estática declarados arriba, se manda a llamar cuando se sale de 
	// las llaves {} donde fueron declarados, en este caso, al salir de la función main().

	int dia = 0;
	if (dia == 0)
	{
		ImprimirEsLunes();
	}

	// Imprimir la dirección de memoria
	// static_cast<void*>(myAuxPointer)
	// static_cast
	// cast es una interpretación de los bits/bytes de una variable como si fuera del tipo solicitado.
	// int myCastedInt = (int)7.77;

	// cast normalito, no estático
	void* myCastedVoidPtr = (void*)&creadoPorFuncionEnVezDeConstructor;

	// cast estático, tiene seguridad adicional, si el casteo falla lanza (throw) un error.
	int myCastedInt = static_cast<int>(7.77);

	// dynamic_cast, se usa clases con herencia

	// bool myBool = true;
	// cout << (myBool ? "true" : "false") << endl;
	// cout <<  boolalpha(myBool) << endl;

	// If de una sola línea
	// (condition) ? then : else

	// no se puede declarar variables void.
	// void myVoid;
	// sí podemos hacer punteros a void :D 
	// se usan para punteros a funciones
	// void* myVoidPointer; // NO LOS VAMOS A VER NI USAR EN ESTA CLASE, PERO LES DEJO EL DATO.

	int valorA = 1;
	int valorB = 2;
	cout << "el valorA antes de la función con parámetros por valor es: " << valorA << endl;
	FuncionConParametrosPorValor(valorA, valorB);
	cout << "el valorA después de la función con parámetros por valor es: " << valorA << endl;

	FuncionConParametrosPorReferencia(valorA, valorB);
	cout << "el valorA después de la función con parámetros por referencia es: " << valorA << endl;

	// le digo a la variable myPointer que ahora guarda la dirección de memoria donde está la variable valorA.
	int* myPointer = &valorA;
	FuncionConParametrosQueSonPunteros(myPointer, valorB);
	cout << "el valorA después de la función con parámetros por referencia es: " << valorA << endl;

	*myPointer += 10;

	

	// En el main del proyecto, mandan a llamar el Main de la tarea en específico que estén entregando.
	MainTareaEjemplo();

	// Para la segunda tarea, por ejemplo, ya solo pondrían la llamada al Main de esa nueva tarea.
	// MainTareaEjemplo2();

	// Para la tarea 3, lo mismo.
	// MainTareaEjemplo3();

	MainWebPacket();

	// Suma(1, 2);

	// cout está dentro del namespace de std, por necesitamos incluirlo en el archivo.
	// cout viene de C que es Console y out que es salida. Entonces lo que hace es mandar información de salida a la consola.
	// endl es End Line, que sería terminar línea que lo que hace es pasarse a la siguiente línea de texto.
	// '\n' es básicamente lo mismo que el endl. 
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
			cout << "ERROR O WARNING: switch cayó en default porque traía el valor: " << tipoDeUsuario << endl;
			// return 0; // Return es: salte de la función donde está puesto. Te lleva a la llave de cierre de la función en donde está.
		}
	}

	// Programación defensiva es hacer código que 
	// 1) Toma en cuenta los casos extremos o los poco comunes, o los nulos o los valores inválidos
	// 2) Que si falla algo, no va a fallar todo el programa
	// 3) Y que si falla, va a dejar un rastro de dónde falló
	// 4) Y que va a tratar de recuperarse lo mejor posible.


	int tamanioDelEjeX = 10;
	int tamanioDelEjeY = 10;
	int valorDeYQueHaraContinue = 4;
	int valorDeYQueHaraBreak = 5;

	for (int x = 0; x < tamanioDelEjeX; x++)
	{
		cout << "antes del for de Y" << endl;

		for (int y = 0; y < tamanioDelEjeY; y++)
		{
			if (y < valorDeYQueHaraContinue)
				continue;

			cout << "antes del break dentro del for de Y, y es: " << y << endl;
			if (y == valorDeYQueHaraBreak)
			{
				break; // te saca del scope del ciclo dentro del cual está, saltándose todo lo que esté debajo.

			} // esta es la llave de cierre del If, que el if es condicional pero no es un ciclo.
			cout << "después del break dentro del for de Y, y es: " << y << endl;
		}// esta es la llave de cierre del for (de la Y) que sí es un ciclo.

		cout << "después del for de Y" << endl;
	}

	// Operadores lógicos
	// && (operador AND) ambos tienen que ser verdad para que el resultado sea verdad
	// || (operador OR) cualquiera de los dos tienen que ser verdad para que el resultado sea verdad
	// ! (operador NOT) invierte el valor de verdad de a quien se le use
	// bool myBool = true;
	// if(myBool != true)
	// XOR es uno de los dos valores tiene que ser verdad, pero el otro no. Existe la palabra clave en c++ "xor".
	// if( (x==true && y == false) ||  
	// 	(x==false && y == true))

	// La pila de llamadas le dice al programa dónde va la ejecución, y a dónde regresar una vez que acabe 
	// con la función que esté ejecutando actualmente
	FuncionPila1();


	Rectangulo myRectangulo;
	myRectangulo.alto = 5.0f;
	cout << "el alto de myRectangulo es: " << myRectangulo.alto << endl;
	myRectangulo.ancho = 3.0f;

	Rectangulo* myRectanguloPointer = &myRectangulo;
	(*myRectanguloPointer).alto = 10.0f; // esta línea y la de abajo hacen exactamente lo mismo.
	myRectanguloPointer->alto = 10.0f;


	Rectangulo myOtherRectangulo = Rectangulo();
	cout << "el alto de myOtherRectangulo es: " << myOtherRectangulo.alto << endl;

	RectanguloClase myRectanguloClase;
	myRectanguloClase.alto = 5.0f;
	myRectanguloClase.ancho = 5.0f;
	myRectanguloClase.ObtenerArea(); // aquí le estoy pidiendo que me dé el área de este rectángulo en específico.




	/*bool myBoolSinInicializar;
	cout << myBoolSinInicializar << endl;*/

	// le tenemos que dar el tamaño de antemano.
	int myIntArray[10];
	cout << myIntArray[0] << endl;
	

	// el tamaño tiene que ser una constante, una variable normal NO es constante, 
	// entonces no la podemos usar para definir ese tamaño.
	// int tamanioArray = 10;
	// int myIntArray2[tamanioArray];

	// Sí se puede usar un valor definido (#define), constante (const)
	int myDefineArray[TAMANO_MY_INT_ARRAY];

	int myDefineArrayConMultiplicacion[MULTIPLICACION_2_X_3];

	for (int i = 0; i < MULTIPLICACION_2_X_3; i++)
	{
		myDefineArrayConMultiplicacion[i] = i;
		cout << "myDefineArrayConMultiplicacion[i] es: " << myDefineArrayConMultiplicacion[i];
	}

	int myDefineArrayConMacro[MULTIPLICACION_CON_PARAMETROS(10, 4)];


	// arreglos bidimensionales
	int myBidimensionalArray[2][3];
	// [X1,X2]
	// [Y1,Y2]
	// [Z1,Z2]
	// Lo que la computadora hace en memoria

	// un arreglo de [N][M] es lo mismo que un arreglo de [N*M]
	int bidimensional[2][3];
	int unidimensional[2 * 3];


	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			myBidimensionalArray[x][y] = x * 3 + y;
			cout << "myBidimensionalArray["<<x<<"]["<<y<<"]" << myBidimensionalArray[x][y] << endl;
		}
	}


	int tridimensional[2][3][4];

	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			for(int z = 0; z < 4; z++ )
			{
				tridimensional[x][y][z] = (x * 3 * 4) + (y*4) + z;
				cout << "myBidimensionalArray[" << x << "][" << y << "]["<<z<<"]: " << myBidimensionalArray[x][y] << endl;
			}
		}
	}

	// Esto se acaba la memoria estática cuando ponemos 365*1000, 
	//int nDimensional[365][100];
	//for (int x = 0; x < 365; x++)
	//{
	//	for (int y = 0; y < 100; y++)
	//	{
	//		nDimensional[x][y] = x * 100 + y;
	//		cout << "nDimensional[" << x << "][" << y << "]" << nDimensional[x][y] << endl;
	//	}
	//}

	MainEjemplosMemoriaDinamica();



	// Return es: salte de la función donde está puesto. Te lleva a la llave de cierre de la función en donde está.

	// Retorna el código de error de la ejecución del Main.
	// El código "0" significa que no hubo error alguno. Significa que el main terminó satisfactoriamente.
	return 0;
}





void FuncionPila1()
{
	cout << "función pila 1 \n";
	FuncionPila2();
}

void FuncionPila2()
{
	cout << "función pila 2 \n";
	FuncionPila3();
}

void FuncionPila3()
{
	cout << "función pila 3 \n";
}