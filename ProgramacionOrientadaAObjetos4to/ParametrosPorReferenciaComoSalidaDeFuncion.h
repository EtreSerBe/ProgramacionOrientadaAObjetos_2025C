#pragma once

#include<iostream>
#include<filesystem>
using namespace std;

/*
2.4) Hacer una funci�n (m�todo) que reciba por referencia una variable 
de tipo Rect e imprima las coordenadas X y Y de dicha variable, 
as� como las coordenadas X y Y donde terminar�a ese Rect tomando 
en cuenta su Alto y Ancho. 
La funci�n debe regresar false si al menos uno de los campos del Rect 
es menor que 0, y regresar true al final si todo sale bien. 
Adem�s, saquen las coordenadas X y Y donde terminar�a dicho 
Rect como dos par�metros por referencia.
*/

// Los par�metros por referencia no solo sirven para arrays y punteros,
// a veces se usan para guardar uno o m�s variables como resultado
// de una funci�n. 
bool CargarArchivo(string nombreDeArchivo, string& out_archivoCargado);


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
bool ObtenerPerimetroYArea(int alto, int ancho, int& perimetro, int& area);

void MainParametrosPorReferenciaComoSalidaDeFuncion();
