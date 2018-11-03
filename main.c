#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "player.c"
#include "ruangan.h"
#include "ruangan.c"

int main() {
	void PrintNama();
	void Keluar();
	int Option;
	char Id[50];
	Player P;
	Ruangan Kosan;
	
	PrintNama();
	printf("	1. NEW GAME\n");
	printf("	2. START GAME\n");
	printf("	3. LOAD GAME\n");
	printf("	4. EXIT\n");
	printf("\n");
	while ((Option < 1) || (Option > 4)){
		printf("	>> ");
		scanf("%d", &Option);
		if ((Option < 1) || (Option > 4)) {
			printf("	>> Wrong Input !\n");			
		}
	}
	
	if (Option == 1) {
		printf("	>> Insert Name : ");
		scanf("%s", &Id);
		InitPlayer(&P, Id);
		BacaRuangan(&Kosan,"kosan.txt");
		printf("Nama ruangan : %s\n", Nama(Kosan) );
		CetakRuangan(Kosan);
	
		POINT pmeja1 = FindObjek(Kosan,'1');
		printf("Posisi meja 1 adalah : ");
		TulisPOINT(pmeja1);
		printf("\n");
	}
	else if (Option == 2) {
		
	}
	else if (Option == 3) {
		
	}
	else if (Option == 4) {
		Keluar();
	}
}

void PrintNama() {
	system("cls");
	printf("========================================================================================================================================================\n");
	printf("========================================================================================================================================================\n");
	printf("	######## ##    ##  ######   #### ####  ######     ##    ## #### ########  ######  ##     ## ######## ##    ##     #######        #####\n");
	printf("	##     	 ###   ## ##    ##   ##  #### ##    ##    ##   ##   ##     ##    ##    ## ##     ## ##       ###   ##    ##     ##      ##   ##\n");
	printf("	##       ####  ## ##         ##   ##  ##          ##  ##    ##     ##    ##       ##     ## ##       ####  ##           ##     ##     ##\n");
	printf("	######   ## ## ## ##   ####  ##  ##    ######     #####     ##     ##    ##       ######### ######   ## ## ##     #######      ##     ##\n");
	printf("	##       ##  #### ##    ##   ##             ##    ##  ##    ##     ##    ##       ##     ## ##       ##  ####    ##            ##     ##\n");
	printf("	##       ##   ### ##    ##   ##       ##    ##    ##   ##   ##     ##    ##    ## ##     ## ##       ##   ###    ##        ###  ##   ##\n");
	printf("	######## ##    ##  ######   ####       ######     ##    ## ####    ##     ######  ##     ## ######## ##    ##    ######### ###   #####\n");
	printf("========================================================================================================================================================\n");
	printf("========================================================================================================================================================\n");
	printf("\n");
}

void Keluar() {
	printf("	>> Has Left The Game, Thanks for Playing !\n");
	printf("\n");
	printf("	CREDIT TO :\n");
	printf("	!Need(Carry) Developer Team\n");
	printf("	13517041 Irfan Haris Widyadhana\n");
	printf("	13517056 Fatur Rahman\n");
	printf("	13517080 Mgs. M. Riandi Ramadhan\n");
	printf("	13517104 M. Fikri Hizbullah\n");
	printf("	13517122 M. Algah Fattah Illahi\n");
	exit(0);
}
