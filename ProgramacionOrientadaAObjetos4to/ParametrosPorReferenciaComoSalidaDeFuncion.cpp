#include "ParametrosPorReferenciaComoSalidaDeFuncion.h"

// Los par�metros por referencia no solo sirven para arrays y punteros,
// a veces se usan para guardar uno o m�s variables como resultado
// de una funci�n. 
bool CargarArchivo(string nombreDeArchivo, string& out_archivoCargado)
{
	// Si el archivo nombreDeArchivo existe
	{
		// entonces lo cargamos en la variable out_archivoCargado.
		// Ya que lo cargamos, regresamos true.
		return true;
	}

	// si no existe, regresamos false.
	return false;
}


// Primero que todo, esta funci�n necesitar�a retornar dos valores: 
// Per�metro y �rea, sin embargo las funciones solo pueden retornar una variable.
// Una posibilidad ser�a hacer una struct que tenga dos variables y pon�rselas ah�...
// pero entonces tendr�amos un mont�n de structs de 1, 2, 3, ... n variables solo para eso.
// La otra posibilidad, es guardar esos valores en variables pasadas por referencia,
// ya que as� los cambios que se hagan a esas variables son permanentes.
// 
// Adem�s, digamos que esta funci�n solo es v�lida si alto y ancho son mayores que 0,
// de lo contrario regresa false. Entonces la funci�n checa si es v�lido,
// y solo si s� es v�lido calcula y asigna los valores de per�metro y �rea.
bool ObtenerPerimetroYArea(int alto, int ancho, int& perimetro, int& area)
{
	if (alto > 0 && ancho > 0)
	{
		perimetro = 2 * alto + 2 * ancho;
		area = alto * ancho;
		return true;
	}
	return false;
}

void MainParametrosPorReferenciaComoSalidaDeFuncion()
{
	int alto = 5;
	int ancho = 7;
	int perimetro;
	int area;
	bool esValido = ObtenerPerimetroYArea(alto, ancho, perimetro, area);
	if (esValido)
	{
		cout << "El alto y ancho son mayores que 0, entonces el perimetro es: " << perimetro
			<< " y el area es: " << area << endl;
	}
	else
	{
		cout << "alto o ancho son menores o iguales a 0. Favor de verificar. No se pudo calcular el �rea ni el per�metro. " << endl;
	}
}

