#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/player.h"
#include "./lib/ruangan.h"
#include "./lib/pelanggan.h"
#include "./lib/nampan.h"
#include "./lib/pesanan.h"
#include "./lib/graph.h"
#include "./lib/bintree.h"

void PrintJudul(); //print judul nih cuy ada di bawah implementasi

int CharToInt(char c);// Diperlukan buat konversi nama meja ke int

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
	char Food;
	Queue Q;
	Nampan S;
	Pesanan O;
	Graph G;
	ArrayMejaPelanggan Mp;
	BinTree Resep;

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
			BacaResep(&Resep, "./filex/resep.txt");

			CurrentRuangan = Ruang1;
			ruang = 1;

			/*Inisialisasi antrian*/
			InitAntrian(&Q);
			Pelanggan pelanggan;
			InitPelanggan(&pelanggan);
			Datang(&Q,pelanggan);

			/*Inisialisasi array untuk menyimpan pelanggan yang telah duduk*/
			InitArrayMejaPelanggan(&Mp);

			/*Inisialisasi Nampan*/
			CreateEmptyNampan(&S);

			/*Inisialisasi Graph */
			BuatGraph(&G);
			KosongTangan(&P);

			PrintState(P);
			PrintPelanggan(Q);
			CetakTangan(P);
			PrintPesanan(O);
			printf("Nama ruangan : %s\n", Nama(CurrentRuangan));
			CetakRuangan(CurrentRuangan);
			printf("	>> ");
			scanf("%s", command);
			system("cls");
			while (strcmp(command,"EXIT") != 0) {
				if (strcmp(command,"GU") == 0) {
					if(BisaGerak(CurrentRuangan, 'P', 1)){
						switch (ruang) {
							case 1 : GerakO(&Ruang1, 'P', 1); CurrentRuangan = Ruang1; break;
							case 2 : GerakO(&Ruang2, 'P', 1); CurrentRuangan = Ruang2;break;
							case 3 : GerakO(&Ruang3, 'P', 1); CurrentRuangan = Ruang3;break;
							case 4 : GerakO(&Dapur, 'P', 1); CurrentRuangan = Dapur; break;
						}
						KurangiKesabaranAntrian(&Q,&P);
						KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
						GeneratePelanggan(&Q);
						Time(P) = NextDetik(Time(P));
					}
					else {
						POINT LokasiP = FindObjek(CurrentRuangan,'P'); int x = Ordinat(LokasiP); int y = Absis(LokasiP);
						if (SearchNode(G,ruang,x,y) != Nihil) {
							Objek L = CreateObjek('L', 0, false);
							switch(ruang) {
								case 1 : SetObjek(&Ruang1, L, y, x);
										break;
								case 2 : SetObjek(&Ruang2, L, y, x);
										break;
								case 3 : SetObjek(&Ruang3, L, y, x);
										break;
								case 4 : SetObjek(&Dapur, L, y, x);
										break;
							}
							PindahRuangan(&ruang, &x, &y, G);
							Objek PNew = CreateObjek('P', 1, true);
							switch (ruang) {
								case 1 : SetObjek(&Ruang1, PNew, y, x);
										CurrentRuangan = Ruang1;
										break;
								case 2 : SetObjek(&Ruang2, PNew, y, x);
										CurrentRuangan = Ruang2;
										break;
								case 3 : SetObjek(&Ruang3, PNew, y, x);
										CurrentRuangan = Ruang3;
										break;
								case 4 : SetObjek(&Dapur, PNew, y, x);
										CurrentRuangan = Dapur;
										break;
							}
							KurangiKesabaranAntrian(&Q,&P);
							KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
							GeneratePelanggan(&Q);
							Time(P) = NextDetik(Time(P));
						}
						else {
							printf("	>>Ouch Kejedut gan!\n");	
						}
					}
				}
				else if (strcmp(command,"GR") == 0) {
					if(BisaGerak(CurrentRuangan, 'P', 2)){
						switch (ruang) {
							case 1 : GerakO(&Ruang1, 'P', 2); CurrentRuangan = Ruang1; break;
							case 2 : GerakO(&Ruang2, 'P', 2); CurrentRuangan = Ruang2; break;
							case 3 : GerakO(&Ruang3, 'P', 2);  CurrentRuangan = Ruang3;break;
							case 4 : GerakO(&Dapur, 'P', 2);  CurrentRuangan = Dapur; break;
						}
						KurangiKesabaranAntrian(&Q,&P);
						KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
						GeneratePelanggan(&Q);
						Time(P) = NextDetik(Time(P));
					} 
					else {
						POINT LokasiP = FindObjek(CurrentRuangan,'P'); int x = Ordinat(LokasiP); int y = Absis(LokasiP);
						if (SearchNode(G,ruang,x,y) != Nihil) {
							Objek L = CreateObjek('L', 0, false);
							switch(ruang) {
								case 1 : SetObjek(&Ruang1, L, y, x);
										break;
								case 2 : SetObjek(&Ruang2, L, y, x);
										break;
								case 3 : SetObjek(&Ruang3, L, y, x);
										break;
								case 4 : SetObjek(&Dapur, L, y, x);
										break;
							}
							PindahRuangan(&ruang, &x, &y, G);
							Objek PNew = CreateObjek('P', 1, true);
							switch (ruang) {
								case 1 : SetObjek(&Ruang1, PNew, y, x);
										CurrentRuangan = Ruang1;
										break;
								case 2 : SetObjek(&Ruang2, PNew, y, x);
										CurrentRuangan = Ruang2;
										break;
								case 3 : SetObjek(&Ruang3, PNew, y, x);
										CurrentRuangan = Ruang3;
										break;
								case 4 : SetObjek(&Dapur, PNew, y, x);
										CurrentRuangan = Dapur;
										break;
							}
							KurangiKesabaranAntrian(&Q,&P);
							KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
							GeneratePelanggan(&Q);
							Time(P) = NextDetik(Time(P));
						}
						else {
							printf("	>>Ouch Kejedut gan!\n");	
						}
					}
				}
				else if (strcmp(command,"GD") == 0) {
					if(BisaGerak(CurrentRuangan, 'P', 3)){
						switch (ruang) {
							case 1 : GerakO(&Ruang1, 'P', 3); CurrentRuangan = Ruang1; break;
							case 2 : GerakO(&Ruang2, 'P', 3); CurrentRuangan = Ruang2; break;
							case 3 : GerakO(&Ruang3, 'P', 3); CurrentRuangan = Ruang3; break;
							case 4 : GerakO(&Dapur, 'P', 3); CurrentRuangan = Dapur; break;
						}
						KurangiKesabaranAntrian(&Q,&P);
						KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
						GeneratePelanggan(&Q);
						Time(P) = NextDetik(Time(P));
					} 
					else {
						POINT LokasiP = FindObjek(CurrentRuangan,'P'); int x = Ordinat(LokasiP); int y = Absis(LokasiP);
						if (SearchNode(G,ruang,x,y) != Nihil) {
							Objek L = CreateObjek('L', 0, false);
							switch(ruang) {
								case 1 : SetObjek(&Ruang1, L, y, x);
										break;
								case 2 : SetObjek(&Ruang2, L, y, x);
										break;
								case 3 : SetObjek(&Ruang3, L, y, x);
										break;
								case 4 : SetObjek(&Dapur, L, y, x);
										break;
							}
							PindahRuangan(&ruang, &x, &y, G);
							Objek PNew = CreateObjek('P', 1, true);
							switch (ruang) {
								case 1 : SetObjek(&Ruang1, PNew, y, x);
										CurrentRuangan = Ruang1;
										break;
								case 2 : SetObjek(&Ruang2, PNew, y, x);
										CurrentRuangan = Ruang2;
										break;
								case 3 : SetObjek(&Ruang3, PNew, y, x);
										CurrentRuangan = Ruang3;
										break;
								case 4 : SetObjek(&Dapur, PNew, y, x);
										CurrentRuangan = Dapur;
										break;
							}
							KurangiKesabaranAntrian(&Q,&P);
							KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
							GeneratePelanggan(&Q);
							Time(P) = NextDetik(Time(P));
						}
						else {
							printf("	>>Ouch Kejedut gan!\n");	
						}
					}
				}
				else if (strcmp(command,"GL") == 0) {
					if(BisaGerak(CurrentRuangan, 'P', 4)){
						switch (ruang) {
							case 1 : GerakO(&Ruang1, 'P', 4); CurrentRuangan = Ruang1; break;
							case 2 : GerakO(&Ruang2, 'P', 4); CurrentRuangan = Ruang2; break;
							case 3 : GerakO(&Ruang3, 'P', 4); CurrentRuangan = Ruang3; break;
							case 4 : GerakO(&Dapur, 'P', 4); CurrentRuangan = Dapur; break;
						}
						KurangiKesabaranAntrian(&Q,&P);
						KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
						GeneratePelanggan(&Q);
						Time(P) = NextDetik(Time(P));
					} else {
						POINT LokasiP = FindObjek(CurrentRuangan,'P'); int x = Ordinat(LokasiP); int y = Absis(LokasiP);
						if (SearchNode(G,ruang,x,y) != Nihil) {
							Objek L = CreateObjek('L', 0, false);
							switch(ruang) {
								case 1 : SetObjek(&Ruang1, L, y, x);
										break;
								case 2 : SetObjek(&Ruang2, L, y, x);
										break;
								case 3 : SetObjek(&Ruang3, L, y, x);
										break;
								case 4 : SetObjek(&Dapur, L, y, x);
										break;
							}
							PindahRuangan(&ruang, &x, &y, G);
							Objek PNew = CreateObjek('P', 1, true);
							switch (ruang) {
								case 1 : SetObjek(&Ruang1, PNew, y, x);
										CurrentRuangan = Ruang1;
										break;
								case 2 : SetObjek(&Ruang2, PNew, y, x);
										CurrentRuangan = Ruang2;
										break;
								case 3 : SetObjek(&Ruang3, PNew, y, x);
										CurrentRuangan = Ruang3;
										break;
								case 4 : SetObjek(&Dapur, PNew, y, x);
										CurrentRuangan = Dapur;
										break;
							}
							KurangiKesabaranAntrian(&Q,&P);
							KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
							GeneratePelanggan(&Q);
							Time(P) = NextDetik(Time(P));
						}
						else {
							printf("	>>Ouch Kejedut gan!\n");	
						}
					}
				}
				else if (strcmp(command,"ORDER") == 0) {
					if (MejaTerdekat(CurrentRuangan) == '1' | MejaTerdekat(CurrentRuangan) == '2' | MejaTerdekat(CurrentRuangan) == '3' | MejaTerdekat(CurrentRuangan) == '4') {
						int nomeja = CharToInt(MejaTerdekat(CurrentRuangan));
						TambahPesanan(ArrayMeja(Mp,ruang,nomeja), nomeja, ruang, &O);
					}
					else {
						printf("	>> Maaf anda tidak berada di samping pelanggan\n");
					}
				}
				else if (strcmp(command,"PUT") == 0) {
					KeluarkanMakanan(&P, &Food);
					if (IsMakananJadi(Food)) {
						if (DekatNampan(CurrentRuangan)) {
							KodeMakanan(Food, makanan);
							Push(&S, makanan);
							Time(P) = NextDetik(Time(P));
						}
						else {
							printf("	>> Maaf, anda tidak disebelah nampan\n" );
							IsiTangan(&P, Food);
						}
					}
					else {
						printf("	>> Maaf, di tangan anda bukan makanan jadi\n");
						IsiTangan(&P, Food);
					}
				}
				else if (strcmp(command,"TAKE") == 0) {
					char Bahan; boolean Valid = true; 
					Bahan = BahanTerdekat(CurrentRuangan);
					switch (Bahan) {
						case 'p' : IsiTangan(&P,'p');
									break;
						case 'S' : IsiTangan(&P,'S');
									break;
						case 'g' : IsiTangan(&P,'g');
									break;
						case 'e' : IsiTangan(&P,'e');
									break;
						case 'n' : IsiTangan(&P,'n');
									break;
						case 'r' : IsiTangan(&P,'r');
									break;
						case 's' : IsiTangan(&P,'s');
									break;
						case 'b' : IsiTangan(&P,'b');
									break;
						case 'o' : IsiTangan(&P,'o');
									break;
						case 't' : IsiTangan(&P,'t');
									break;
						case 'a' : IsiTangan(&P,'a');
									break;
						case 'k' : IsiTangan(&P,'k');
									break;
						case 'w' : IsiTangan(&P,'w');
									break;
						case 'B' : IsiTangan(&P,'B');
									break;
						case 'c' : IsiTangan(&P,'c');
									break;
						default : printf("	>> Anda tidak sedang di dekat bahan makanan\n");
									Valid = false;
					}
					if (Valid && MakananHampirJadi(Bahan)) {
						Time(P) = NextDetik(Time(P));
						BuatMakanan(&P, Resep);
					}
				}
				else if (strcmp(command,"CH") == 0) {
					KosongTangan(&P);
					printf("	>> Tangan dikosongkan\n");
					Time(P) = NextDetik(Time(P));
				}
				else if (strcmp(command,"CT") == 0) {
					CreateEmptyNampan(&S);
					printf("	>> Nampan dikosongkan\n");
					Time(P) = NextDetik(Time(P));
				}
				else if (strcmp(command,"PLACE") == 0) {
					/* menempatkan pelanggan pada tempat duduk yang kosong */
					if (ruang == 1) { 
							if (MejaTerdekat(Ruang1) == '1' || MejaTerdekat(Ruang1) == '2' || MejaTerdekat(Ruang1) == '3' || MejaTerdekat(Ruang1) == '4') {
								noMeja = CharToInt(MejaTerdekat(Ruang1));					
								Pergi(&Q,&pelanggan,Kapasitas(Elmt(Ruang1,Absis(FindObjek(Ruang1,MejaTerdekat(Ruang1))),Ordinat(FindObjek(Ruang1,MejaTerdekat(Ruang1))))));
								IsiMeja(&Ruang1,MejaTerdekat(Ruang1),Jumlah(pelanggan));
	
								IsiArrayMejaPelanggan(&Mp,noMeja,ruang,pelanggan);
								Time(P) = NextDetik(Time(P));
								CurrentRuangan = Ruang1;
							}
							else {
								printf("	>> Maaf, anda tidak berada di samping pelanggan\n");
							}
					}
					else if (ruang == 2) {
						if (MejaTerdekat(Ruang2) == '1' || MejaTerdekat(Ruang2) == '2' || MejaTerdekat(Ruang2) == '3' || MejaTerdekat(Ruang2) == '4') {
							noMeja = CharToInt(MejaTerdekat(Ruang2));					
							Pergi(&Q,&pelanggan,Kapasitas(Elmt(Ruang2,Absis(FindObjek(Ruang2,MejaTerdekat(Ruang2))),Ordinat(FindObjek(Ruang2,MejaTerdekat(Ruang2))))));
							IsiMeja(&Ruang2,MejaTerdekat(Ruang2),Jumlah(pelanggan));
	
							IsiArrayMejaPelanggan(&Mp,noMeja,ruang,pelanggan);
							Time(P) = NextDetik(Time(P));
							CurrentRuangan = Ruang2;
						}
						else {
							printf("	>> Maaf, anda tidak berada di samping pelanggan\n");
						}
					}
					else if (ruang == 3) {
						if (MejaTerdekat(Ruang3) == '1' || MejaTerdekat(Ruang3) == '2' || MejaTerdekat(Ruang3) == '3' || MejaTerdekat(Ruang3) == '4') {
							noMeja = CharToInt(MejaTerdekat(Ruang3));					
							Pergi(&Q,&pelanggan,Kapasitas(Elmt(Ruang3,Absis(FindObjek(Ruang3,MejaTerdekat(Ruang3))),Ordinat(FindObjek(Ruang3,MejaTerdekat(Ruang3))))));
							IsiMeja(&Ruang3,MejaTerdekat(Ruang3),Jumlah(pelanggan));
	
							IsiArrayMejaPelanggan(&Mp,noMeja,ruang,pelanggan);
							Time(P) = NextDetik(Time(P));
							CurrentRuangan = Ruang3;
						}
						else {
							printf("	>> Maaf, anda tidak berada di samping pelanggan\n");
						}
					}
				}
				else if (strcmp(command,"GIVE") == 0) {
					/* memberikan makanan yang ada di nampan paling atas */
					if (!IsEmptyNampan(S)) {
						Pop(&S, &makanan);

						if (ruang==1) {
							noMeja = CharToInt(MejaTerdekat(Ruang1));
							if(strcmp(makanan, Makanan(ArrayMeja(Mp,ruang,noMeja)))==0){
								printf("	>> Makanan yang anda berikan benar\n");
								UsirPelanggan(&Ruang1, MejaTerdekat(Ruang1));
							}
							else {
								printf("	>> Anda salah memberikan makanan\n");
							}
							Time(P) = NextDetik(Time(P));
						}
						else if (ruang == 2) {
							noMeja = CharToInt(MejaTerdekat(Ruang2));
							if(strcmp(makanan, Makanan(ArrayMeja(Mp,ruang,noMeja)))==0){
								printf("	>> Makanan yang anda berikan benar\n");
								UsirPelanggan(&Ruang2, MejaTerdekat(Ruang2));
							}
							else {
								printf("	>> Anda salah memberikan makanan\n");
							}
							Time(P) = NextDetik(Time(P));
						}
						else if (ruang == 3) {
							noMeja = CharToInt(MejaTerdekat(Ruang3));
							if(strcmp(makanan, Makanan(ArrayMeja(Mp,ruang,noMeja)))==0){
								printf("	>> Makanan yang anda berikan benar\n");
								UsirPelanggan(&Ruang3, MejaTerdekat(Ruang3));
							}
							else {
								printf("	>> Anda salah memberikan makanan\n");
							}
							Time(P) = NextDetik(Time(P));
						}
					}
					else {
						printf("	>> Nampan anda kosong!\n");
					}
				}
				else if (strcmp(command,"RECIPE") == 0) {
					PrintTree(Resep,5);
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
				CetakTangan(P);
				CetakNampan(S);
				PrintPesanan(O);
				printf("Nama ruangan : %s\n", Nama(CurrentRuangan));
				CetakRuangan(CurrentRuangan);
				printf("	>> ");
				scanf("%s", command);
				system("cls");
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

int CharToInt(char c)	{
	if(c=='1')	{
		return 1;
	}
	else if(c=='2')	{
		return 2;
	}
	else if(c=='3')	{
		return 3;
	}
	else if(c=='4')	{
		return 4;
	}
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
