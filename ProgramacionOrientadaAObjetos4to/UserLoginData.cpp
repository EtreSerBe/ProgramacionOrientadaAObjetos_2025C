#include "UserLoginData.h"

string UserLoginData::GetUsername()
{
	return username;
}


bool UserLoginData::AsignarContrasena(string nuevaContrasena)
{
	// antes de asignarla vamos a corroborar las cosas indispensables para que la contrase�a sea v�lida.
	// por ejemplo, que tenga al menos 8 caracteres.
	if (nuevaContrasena.length() < 8)
	{
		return false;
	}
	if (nuevaContrasena.find("�"))
	{
		return false;
	}
	// si no tiene al menos un n�mero, una may�scula, etc.

	cout << "ATENCI�N, se cambi� la contrase�a del usuario." << endl;
	contrasena = nuevaContrasena;
}

string UserLoginData::ObtenerNombreUsuario()
{
	if (username == "")
	{
		return "error no hay nombre de usuario";
	}
	return username;
}
