#include "ClaseConstructoresYDestructores.h"

Triangle::Triangle()
{
	cout << "soy el constructor por defecto" << endl;
	// podr�amos inicializar sus variables en 0 u otro valor que queramos
	base = 0;
	altura = 0;
}


Triangle::Triangle(float altura, float in_base)
{
	cout << "soy el constructor que recibe altura y base." << endl;
	// como recordatorio: "this" se refiere a la instancia espec�fica de esta clase/struct que 
	// est� mandando a llamar esta funci�n.
	this->altura = altura;
	base = in_base; // aqu� no uso el this porque la variable in_base tiene distinto nombre de base, entonces no hay ambiguedad.
}


Triangle GenerarTriangulo(float altura, float base)
{
	Triangle myTriangle;
	myTriangle.altura = altura;
	myTriangle.base = base;
	return myTriangle;
}