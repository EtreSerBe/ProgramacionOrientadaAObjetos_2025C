#pragma once

#include <iostream>
using namespace std;

// recordatorio: en los .h van las puras declaraciones, y en los cpp las puras definiciones.

// los datos para el login (iniciar sesi�n) de un usuario.
class UserLoginData
{
public:
	string GetUsername();

	// si bien esta cosa es p�blica y por tanto la variable privada "contrasena" se puede asignar en cualquier parte,
	// el hecho de tener esta funci�n para asignarla nos da m�s control y seguridad sobre c�mo cambia dicha variable.
	bool AsignarContrasena(string nuevaContrasena);

	// esta de aqu� nos da funcionamiento adicional al momento de que se intenta acceder a una variable.
	string ObtenerNombreUsuario();

private:
	// Nombre de usuario
	string username;

	// contrase�a del usuario
	string contrasena;

	// protected es b�sicamente lo mismo que private, 
	// PERO las clases que hereden de dicha clase S� pueden acceder a esas propiedades.

public:
	bool otraVariablePublic;
};

