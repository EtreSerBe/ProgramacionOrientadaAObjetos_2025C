#include "ExplicacionDirectivasDePreprocesador.h"


void DemostracionDirectivasDePreprocesador()
{
	cout << myVariable << endl;


	cout << textoEnLoQueSiEstaDefinido << endl;

	// Aqu� el autocompletar ni siquiera nos sugiere que exista la variable "textoEnLoQueNoEstaDefinido"
	// ya que no existe para el compilador porque ya no est� definido OPCION_QUE_SE_DESDEFINE 
	// porque se le hizo #undef 

}