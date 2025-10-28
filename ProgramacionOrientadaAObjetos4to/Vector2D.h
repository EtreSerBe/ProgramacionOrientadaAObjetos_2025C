#pragma once

#include<iostream>
using namespace std;

class Vector2D
{
public:
	Vector2D(int _x, int _y);

	int x;
	int y;
	string nombre;

	// Operadores para sumar, restar, multiplicar, etc. dos vectores
	// Tipo de retorno: Vector2D
	// operator Y s�mbolo del operador: operator+
	// par�metros
	Vector2D operator+(const Vector2D other);

	Vector2D operator*(const Vector2D other);

	Vector2D operator*(const int multiplicador);

	// Regresa true si el que est� a la izquierda del operador es m�s chico que el de la derecha en su X y en su Y
	bool operator<(const Vector2D other);

	// OJO: Dos operadores del mismo nombre (s�mbolo) y con los mismos par�metros 
	// NO pueden tener distinto tipo de retorno.
	// Vector2D operator<(const Vector2D other);

	bool operator==(const Vector2D other);


	Vector2D Sumar(const Vector2D other);

	// Friend function overloading (commonly used for stream operators << and >>)
	friend std::ostream& operator<<(std::ostream& os, const Vector2D& obj);
};

// operador es muy parecido a una funci�n, pero usa la palabra clave operator
// Tipo de dato que regresa el operador (o que sale como resultado del operador) + operator + s�mbolo del operador + par�metros
ostream& operator<<(ostream& os, const Vector2D& obj);

void DemostracionSobrecargaDeOperadores();