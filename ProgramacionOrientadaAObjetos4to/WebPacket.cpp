#include "WebPacket.h"


void MainWebPacket()
{
	WebPacket paqueteConPuroHeader;
	paqueteConPuroHeader.Inicializar(1234, "192.168.0.1");

	int myTenArray[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	WebPacket paqueteConTodoElPayload;
	// Cuando t� mandas un array como par�metro, lo �nico que se manda es la direcci�n de memoria hacia el primer elemento.
	paqueteConTodoElPayload.Inicializar(1234, "192.168.0.1", myTenArray);
}