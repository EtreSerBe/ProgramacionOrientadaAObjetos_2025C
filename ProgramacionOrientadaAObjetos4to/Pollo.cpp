#include "Pollo.h"


Pollo::Pollo()
{
	numeroDeOjos = 2;
	numeroDePatas = 2;
	nombre = "Pollo";
}

void Pollo::Piar()
{
	cout << "Pio" << endl;
}

void Pollo::HacerRuido()
{
	Piar();
}
