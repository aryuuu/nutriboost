#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/player.h"
#include "./lib/ruangan.h"
#include "./lib/pelanggan.h"
void PrintJudul(); //print judul nih cuy ada di bawah implementasi

void Keluar(); //Keluar dari CMD

int main() {
	char Id[50] = {"<NONE>"}; //NAMA USER
	Player P;
	Ruangan Dapur, Ruang1, Ruang2, Ruang3, CurrentRuangan;
	int Option; //Menampung pilihan dari user
	int ruang; //Mencatat nomor ruangan sekarang
	int noMeja;//Mencatat nomor meja
	char command[50];
	char makanan[25];
	Queue Q;
	Nampan S;

	Pelanggan satu[4+1];
	Pelanggan dua[4+1];
	Pelanggan tiga[4+1];

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

			BacaRuangan(&Dapur,"./filex/dapur.txt");
			BacaRuangan(&Ruang1,"./filex/satu.txt");
			BacaRuangan(&Ruang2,"./filex/dua.txt");
			BacaRuangan(&Ruang3,"./filex/tiga.txt");

			CurrentRuangan = Ruang1;
			ruang = 1;

			PrintState(P);
			printf("Nama ruangan : %s\n", Nama(CurrentRuangan));
			CetakRuangan(CurrentRuangan);

			/*Inisialisasi antrian*/
			InitAntrian(&Q);
			Pelanggan pelanggan;
			InitPelanggan(&pelanggan);
			Datang(&Q,pelanggan);

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
				else if (strcmp(command,"ORDER") == 0) {
					/* mengambil orderan makanan dari pelanggan yang sudah ada di tempat duduk */

				}
				else if (strcmp(command,"PUT") == 0) {
					/* menaruh makanan di hand ke nampan */
				}
				else if (strcmp(command,"TAKE") == 0) {
					/* mengambil bahan makanan  atau alat masak di meja */
				}
				else if (strcmp(command,"CH") == 0) {
					KosongTangan(&P);
					Time(P) = NextDetik(Time(P));
				}
				else if (strcmp(command,"CT") == 0) {
					/* mengosongkan tray/nampan */
					/* KosongTray(&T); */
					Time(P) = NextDetik(Time(P));
				}
				else if (strcmp(command,"PLACE") == 0) {
					/* menempatkan pelanggan pada tempat duduk yang kosong */
					Pergi(&Q,&pelanggan,2);
					noMeja =1;
					if(ruang=1)	{
						SalinPelanggan(&satu[noMeja],pelanggan);
					}
					if(ruang=2)	{
						SalinPelanggan(&dua[noMeja],pelanggan);
					}
					if(ruang=3)	{
						SalinPelanggan(&tiga[noMeja],pelanggan);
					}

					Time(P) = NextDetik(Time(P));

				}
				else if (strcmp(command,"GIVE") == 0) {
					/* memberikan makanan yang ada di nampan paling atas */
					Push (&S, makanan);
					if(strcmp(X, Makanan(satu[noMeja]))==0){
						printf("Makanan yanga anda berikan benar\n");
					}
					else	{
						printf("goblok, makanannya salah\n");
					}

					Time(P) = NextDetik(Time(P));
				}
				else if (strcmp(command,"RECIPE") == 0) {
					/* menampilkan pohon resep */
					Time(P) = NextDetik(Time(P));
				}
				else if (strcmp(command,"SAVE") == 0) {
					/* menyimpan suatu permainan */
				}
				else if (strcmp(command,"LOAD") == 0) {
					/* memuat permainan yang pernah di save */
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
