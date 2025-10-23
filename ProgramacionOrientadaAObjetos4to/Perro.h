#pragma once
#include "Animal.h"


// los dos puntos ':' significa que hereda de la clase que est� a la derecha. Aqu� Perro hereda de Animal.
class Perro :
    public Animal
{
public:
    Perro();

    void Ladrar();

    // El problema de la herencia m�ltiple (entre clases no virtuales puras)
    // string name; // que hered� de Animal
    // string name; // que hered� de Fungi

    // La palabra clave "override" especifica que est�s modificando la funcionalidad de la clase padre para dicha funci�n.
    void HacerRuido() override;
};

