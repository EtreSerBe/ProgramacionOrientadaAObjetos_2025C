#pragma once


// CORRECCI�N: 
// Una funci�n virtual pura es aquella que NO tiene una implementaci�n, �nicamente una declaraci�n y termina en = 0;
// por ejemplo: virtual void ImprimirNombre() = 0;
// Para qu� sirven? Para obligar a las clases que la heredan a hacerle un override, si no no se podr�n instanciar. :D 

// Una clase abstracta: Una clase que tiene AL MENOS una funci�n virtual pura SIN hacerle override.
// Cualquier clase que herede de una clase abstracta SIGUE SIENDO ABSTRACTA mientras siga habiendo funciones 
// a las que no se les haya hecho override.
// Para qu� sirve una clase abstracta? Para impedir que se hagan instancias de dicha clase; 
// sirven solo para manejar a las clases que hereden de dicha clase base (a trav�s de punteros).

// Una clase Interfaz (en ingl�s es Interface) es aquella en la que TODAS sus funciones son virtuales puras.
// Estas son las �NICAS clases que se pueden usar en herencia m�ltiple.
// Nunca jam�s debe haber herencia m�ltiple, a menos que todas menos una sean interfaces.
// Ejemplo: ClaseHija : clasePadre, Interfaz1, Interfaz2   // esto es correcto
// Ejemplo: ClaseHija : Interfaz1, Interfaz2, InterfazN		// tambi�n es correcto
// Ejemplo: ClaseHija : clasePadre1, clasePadre2			// Esto NO es correcto, porque m�s de una clase padre NO es interfaz.
// Por est�ndar llevan el prefijo 'I' (i may�scula), por ejemplo IMyInterfaceClass;

class ClaseConFuncionesVirtualesPuras
{

	// El ponerle que una funci�n es = 0 lo convierte en una funci�n virtual Pura.
	// Solo declara los est�ndares de las funciones que las clases hijas DEBER�N implementar.
	virtual void ImprimirNombre() = 0;
};

