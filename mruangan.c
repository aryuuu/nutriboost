#include "ruangan.h"
#include "player.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	Ruangan Kosan;

	CreateRuangan(&Kosan,"Kosan",3,4);//bikin kamar kosong

	Objek Meja = CreateObjek('1',2,false);//bikin meja baru
	Objek Kursi = CreateObjek('K',1,false);//bikin kursi baru
	Objek Costumer = CreateObjek('C',0,true);//bikin costumer



	//SetObjek(&Kosan,Meja,1,1);//taruh meja di posisi 1,1

	CetakRuangan(Kosan);
	return 0;
}