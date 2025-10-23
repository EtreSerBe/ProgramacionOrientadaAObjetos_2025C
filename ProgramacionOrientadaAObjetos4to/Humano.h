#pragma once
#include "Animal.h"

class Humano :
    public Animal
{
public:
    Humano();

    bool puedeHablar;

    void Hablar();

    // Si quito el hacer el override de una funci�n que es Virtual Pura,
    // entonces esta clase sigue siendo Abstracta (que tiene al menos un m�todo sin definir (es decir, virtual puro))
    // T� NO puedes instanciar una clase abstracta.
    void HacerRuido() override;
};

void DemostracionHerenciaDeClases();