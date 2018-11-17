#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "ruangan.h"
#include "pelanggan.h"
void PrintJudul(); //print judul nih cuy ada di bawah implementasi

void Keluar(); //Keluar dari CMD

int main() {
	char Id[50] = {"<NONE>"}; //NAMA USER
	Player P;
	Ruangan Dapur, Ruang1, Ruang2, Ruang3, CurrentRuangan;
	int Option; //Menampung pilihan dari user
	char command[50];
	Queue Q;

	PrintJudul();
	printf("	1. NEW GAME\n");
	printf("	2. START GAME\n");
	printf("	3. LOAD GAME\n");
	printf("	4. EXIT\n");
	printf("\n");

	printf("	>> ");
    scanf("%d", &Option);
	while ((Option < 1) || (Option > 4)){
        printf("	>> Wrong Input !\n");
		printf("	>> ");
        scanf("%d", &Option);
	}

	switch (Option) {
		case 1 :
			printf("	>> Insert Name : ");
			scanf("%s", Id);
			InitPlayer(&P, Id);
		case 3 :
			/* LOAD GAME */
		case 2 :
			if (strcmp(Id, "<NONE>") == 0) {
				printf("	>> Insert Name : ");
				scanf("%s", Id);
				InitPlayer(&P, Id);
			}
			//Nama sudah ada

			BacaRuangan(&Dapur,"dapur.txt");
			BacaRuangan(&Ruang1,"satu.txt");
			BacaRuangan(&Ruang2,"dua.txt");
			BacaRuangan(&Ruang3,"tiga.txt");

			CurrentRuangan = Ruang1;

			PrintState(P);
			printf("Nama ruangan : %s\n", Nama(CurrentRuangan));
			CetakRuangan(CurrentRuangan);
			/*Inisialisasi antrian*/
			InitAntrian(&Q);
			Pelanggan pertama;
			InitPelanggan(&pertama);
			Datang(&Q,pertama);

			printf("	>> ");
			scanf("%s", command);
			while (strcmp(command,"EXIT") != 0) {
				if (strcmp(command,"GU") == 0) {
					if(BisaGerak(CurrentRuangan, 'P', 1)){
						GerakO(&CurrentRuangan, 'P', 1);
						KurangiKesabaranAntrian(&Q,&P);
						GeneratePelanggan(&Q);
						Time(P) = NextDetik(Time(P));
					} else {
						printf("	>> Ouch! Kejedut gan!\n");
					}
				}
				else if (strcmp(command,"GR") == 0) {
					if(BisaGerak(CurrentRuangan, 'P', 2)){
						GerakO(&CurrentRuangan, 'P', 2);
						KurangiKesabaranAntrian(&Q,&P);
						GeneratePelanggan(&Q);
						Time(P) = NextDetik(Time(P));
					} else {
						printf("	>> Ouch! Kejedut gan!\n");
					}
				}
				else if (strcmp(command,"GD") == 0) {
					if(BisaGerak(CurrentRuangan, 'P', 3)){
						GerakO(&CurrentRuangan, 'P', 3);
						KurangiKesabaranAntrian(&Q,&P);
						GeneratePelanggan(&Q);
						Time(P) = NextDetik(Time(P));
					} else {
						printf("	>> Ouch! Kejedut gan!\n");
					}
				}
				else if (strcmp(command,"GL") == 0) {
					if(BisaGerak(CurrentRuangan, 'P', 4)){
						GerakO(&CurrentRuangan, 'P', 4);
						KurangiKesabaranAntrian(&Q,&P);
						GeneratePelanggan(&Q);
						Time(P) = NextDetik(Time(P));
					} else {
						printf("	>> Ouch! Kejedut gan!\n");
					}
				}
				else {
					printf("	>> Perintah Salah!\n");
				}
				PrintState(P);
				PrintPelanggan(Q);
				printf("Nama ruangan : %s\n", Nama(CurrentRuangan));
				CetakRuangan(CurrentRuangan);
				printf("	>> ");
				scanf("%s", command);
			}
		case 4 :
			Keluar();
	}
}

void PrintJudul() {
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
