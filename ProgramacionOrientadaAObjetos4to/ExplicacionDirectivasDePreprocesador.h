#pragma once

#include<iostream>
using namespace std;

// con #define se define un "S�mbolo". En este caso, mi s�mbolo se llama "OPCION_ACTIVADA".
#define OPCION_ACTIVADA 

// A�n si no tiene nada a la derecha de OPCION_SIN_VALOR_ASIGNADO 
// a�n cuenta como definida (como con los #ifndef). Tampoco
#define OPCION_SIN_VALOR_ASIGNADO 

// Para que un #define cuente como no definido, tiene que no estar
// #define OPCION_COMENTADA_PARA_NO_CONTAR_COMO_DEFINIDA
#define OPCION_QUE_SE_DESDEFINE


// la estructura de un bloque #ifdef / #endif es la siguiente
/*

#ifdef MI_SIMBOLO
	// Entonces se compilar� el c�digo que est� entre la l�nea del #ifdef y el #endif
#endif

*/


// la estructura de un bloque #ifdef / #else / #endif es la siguiente
/*

#ifdef MI_SIMBOLO
	// Entonces se compilar� el c�digo que est� entre la l�nea del #ifdef y la l�nea del #else el #endif
#else
	// Si no est� definido MI_SIMBOLO, entonces se compilar� el c�digo que est� entre la l�nea del #else y la del #endif
#endif

*/


#ifdef OPCION_ACTIVADA

const string myVariable = "la opcion esta activada";

#else // es decir, no existe un #define OPCION_ACTIVADA en ning�n .h en este archivo .h 
// ni en ning�n otro .h inclu�do por este archivo.

const string myVariable = "opcion desactivada";

#endif

#ifdef OPCION_QUE_SE_DESDEFINE
const string textoEnLoQueSiEstaDefinido = "esta opcion se desdefinir� despu�s de esta l�nea";
#endif
#undef OPCION_QUE_SE_DESDEFINE

#ifdef OPCION_QUE_SE_DESDEFINE
const string textoEnLoQueNoEstaDefinido = "esto no se va a declarar siquiera";
#endif


void DemostracionDirectivasDePreprocesador();

