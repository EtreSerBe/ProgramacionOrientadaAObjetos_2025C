#include "UsuarioAdmin.h"

UsuarioAdmin::UsuarioAdmin(string _nombreDeUsuario, string _nombreCompleto) : 
	Usuario(_nombreDeUsuario, _nombreCompleto)
{

}

void UsuarioAdmin::MostrarOpciones()
{
	Usuario::MostrarOpciones(); // esto manda a llamar la funci�n de la clase base. Que hace esto de aqu�: cout << "Hola " << ObtenerNombreCompleto() << endl;

	// Despu�s de hacer las cosas generales de la clase base, ya puedes hacer cosas espec�ficas de esta clase Alumno.

	cout << "Presione 1 para ver usuarios; 2 para salir" << endl;
	int opcionElegida = 0;
	cin >> opcionElegida;
	// si se presion� 1
	if (opcionElegida == 1)
	{
		// Entonces mostramos m�s opciones
		cout << "Los usuarios son: " << endl; 
		// listaDeUsuarios.Print();
		
		cout << "presione 4 para para salir. Presione 1 para borrar al profesor; 2 al alumno; y 3 al admin" << endl;
		cin >> opcionElegida;

		switch (opcionElegida)
		{
		case 1:
			cout << "borrando al usuario Profesor" << endl;
			break;
		case 2:
			cout << "borrando al usuario alumno" << endl;
			break;
		case 3:
			cout << "borrando al usuario admin" << endl;
			break;
		case 4:
			cout << "Gracias por usar el sistema. Ha salido." << endl;
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

void UsuarioAdmin::AgregarUsuario(Usuario* usuario)
{
	if (listaDeUsuarios.Contains(usuario))
	{
		cout << "Error, el usuario ya existe en el sistema" << endl;
		return;
	}

	listaDeUsuarios.Append(usuario);
}

void UsuarioAdmin::BorrarUsuarioPorNombreDeUsuario(Usuario* usuario)
{
	listaDeUsuarios.DeleteByValue(usuario);
}
