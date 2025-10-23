#include "UsuarioAlumno.h"

// Este constructor EXTIENDE el constructor de la clase Usuario, es decir, 
// hace lo mismo (poner el nombre de usuario y el completo), 
// pero tambi�n cosas extras (asignar las 3 materias).
UsuarioAlumno::UsuarioAlumno(string _nombreDeUsuario, string _nombreCompleto) :
	Usuario(_nombreDeUsuario, _nombreCompleto)
{
	nombresDeMaterias.Append("1");
	nombresDeMaterias.Append("2");
	nombresDeMaterias.Append("3");
}

void UsuarioAlumno::MostrarOpciones()
{
	// Me sale nombre de Usuario, pero no NombreCompleto, �por qu�? porque nombreCompleto es private.
	// Las propiedades private (tanto variables como funciones NO se pueden acceder por las clases hijas)
	
	Usuario::MostrarOpciones(); // esto manda a llamar la funci�n de la clase base. Que hace esto de aqu�: cout << "Hola " << ObtenerNombreCompleto() << endl;

	// Despu�s de hacer las cosas generales de la clase base, ya puedes hacer cosas espec�ficas de esta clase Alumno.

	cout << "Presione 1 para ver sus calificiones; 2 para salir" << endl;
	int opcionElegida = 0;
	cin >> opcionElegida;
	// si se presion� 1
	if (opcionElegida == 1)
	{
		// Entonces mostramos m�s opciones
		cout << "Sus calificaciones son: \n 10 en Clase 1 \n 10 en Clase 2 \n 9 en clase 3 \n  " <<
			"presione 4 para para salir. Presione 5 para darse de alta en la clase 5; Presione 1 para darse de baja de la clase 1; 2 de la 2; y 3 de la 3" << endl;
		cin >> opcionElegida;
		
		switch (opcionElegida)
		{
		case 1:
			// le pedir�amos a nuestra linkedList que borre esa materia de la lista.
			QuitarMateria("1");
			break;
		case 2:
			// le pedir�amos a nuestra linkedList que borre esa materia de la lista.
			QuitarMateria("2");
			break;
		case 3:
			// le pedir�amos a nuestra linkedList que borre esa materia de la lista.
			QuitarMateria("3");
			break;
		case 4:
			cout << "Gracias por usar el sistema. Ha salido." << endl;
			break;
		case 5:
			nombresDeMaterias.Append("5");
			break;
		default: 
			cout << "Opci�n inv�lida, saliendo del sistema." << endl;
		}

	}
	else if (opcionElegida == 2)
	{
		cout << "Gracias por usar el sistema. Ha salido." << endl;
	}
	else
	{
		cout << "Opci�n inv�lida, saliendo del sistema." << endl;
	}

	cout << "Gracias por usar el sistema. " << ObtenerNombreCompleto() << " \n\n";

}
