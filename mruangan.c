#include "ruangan.h"
#include "player.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	Ruangan Kosan;

	BacaRuangan(&Kosan,"kosan.txt");
	printf("Nama ruangan : %s\n", Nama(Kosan) );
	CetakRuangan(Kosan);

//	CreateRuangan(&Kosan,"kamarkuh",3,3);
//	CetakRuangan(Kosan);
	return 0;
}