#include "ExplicacionStatic.h"


void PieDeCorreo(string nombreDelUsuario)
{
	static string miNombre = nombreDelUsuario;

	cout << miNombre << endl;
}


void MainExplicacionStatic()
{
	// Aqu� s� se va a setear el nombre de miNombre en la funci�n, porque es la primera vez que se le asigna un valor,
	PieDeCorreo("Adrian Ulises Gonzalez Casillas");

	// Pero aqu� ya no se va a asignar, porque no ser�a la primera vez.
	PieDeCorreo("Juanito P�rez");

	// para mandar a llamar la funci�n "CambiarMyStaticInt" necesito un objeto de la clase ExplicacionStatic
	ExplicacionStatic myExplicacionStatic;
	myExplicacionStatic.CambiarMyStaticInt(12);


	ExplicacionStatic::ImprimirNombreDeClase();

	//cout << "la variable myStaticInt que le pertenece a la clase ExplicacionStatic tiene el valor de:"
	//	<<ExplicacionStatic::myStaticInt << endl;

	Archivo archivoCargado = Archivo::CargarArchivo();

	// A diferencia de static, las const NO le pertenecen a la clase, s� se necesita una instancia de la clase.
	ExplicacionConst miExplicacionConst;
	miExplicacionConst.miConst;

	// static const S� le pertenecen a la clase y no a las instancias.
	ExplicacionConst::miStaticConstInt;

	Archivo miArchivo;
	miExplicacionConst.EjemploConst(miArchivo);
}

void Archivo::BorrarDatos() // no puede ser const.
{
	datos = "";
}
