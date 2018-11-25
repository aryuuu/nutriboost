#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/player.h"
#include "./lib/ruangan.h"
#include "./lib/pelanggan.h"
#include "./lib/nampan.h"
#include "./lib/pesanan.h"
#include "./lib/graph.h"

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
	Queue Q;
	Nampan S;
	Pesanan O;
	Graph G;
	ArrayMejaPelanggan Mp;

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


			PrintState(P);
			PrintPelanggan(Q);
			CetakTangan(P);
			PrintPesanan(O);
			printf("Nama ruangan : %s\n", Nama(CurrentRuangan));
			CetakRuangan(CurrentRuangan);
			printf("	>> ");
			scanf("%s", command);
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
						}
						else {
							printf("	>>Ouch Kejedut gan!\n");	
						}
					}
				}
				else if (strcmp(command,"ORDER") == 0) {
					if (MejaTerdekat(CurrentRuangan) == '1' | MejaTerdekat(CurrentRuangan) == '2' | MejaTerdekat(CurrentRuangan) == '3' | MejaTerdekat(CurrentRuangan) == '4') {
						int nomeja = CharToInt(MejaTerdekat(CurrentRuangan));
						TambahPesanan(ArrayMeja(Mp,ruang,nomeja), ruang, nomeja, &O);
					}
					else {
						printf("	>> Maaf anda tidak berada di samping pelanggan\n");
					}
				}
				else if (strcmp(command,"PUT") == 0) {
					/*KeluarkanMakanan(&P, makanan);
					if (IsMakananJadi(Recipe)) {
						if (DekatNampan(CurrentRuangan)) {
							Push(&S, makanan);
							Time(P) = NextDetik(Time(P));
						}
						else {
							printf("	>> Maaf, anda tidak disebelah nampan\n" );
							IsiTangan(&P, makanan);
						}
					}
					else {
						printf("	>> Maaf, di tangan anda bukan makanan jadi\n");
					}*/
				}
				else if (strcmp(command,"TAKE") == 0) {
					char Bahan; boolean Valid = true; 
					Bahan = BahanTerdekat(CurrentRuangan);
					switch (Bahan) {
						case 'p' : IsiTangan(&P, "Piring");
									break;
						case 'S' : IsiTangan(&P, "Sendok");
									break;
						case 'g' : IsiTangan(&P, "Garpu");
									break;
						case 'e' : IsiTangan(&P, "Es Krim");
									break;
						case 'n' : IsiTangan(&P, "Nasi");
									break;
						case 'r' : IsiTangan(&P, "Roti");
									break;
						case 's' : IsiTangan(&P, "Spaghetti");
									break;
						case 'b' : IsiTangan(&P, "Pisang");
									break;
						case 'o' : IsiTangan(&P, "Stroberi");
									break;
						case 't' : IsiTangan(&P, "Telur");
									break;
						case 'a' : IsiTangan(&P, "Ayam goreng");
									break;
						case 'k' : IsiTangan(&P, "Patty");
									break;
						case 'w' : IsiTangan(&P, "Sosis");
									break;
						case 'B' : IsiTangan(&P, "Bolognese");
									break;
						case 'c' : IsiTangan(&P, "Carbonara");
									break;
						default : printf("	>> Anda tidak sedang di dekat bahan makanan\n");
									Valid = false;
					}
					if (Valid) {
						Time(P) = NextDetik(Time(P));
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
					if (MejaTerdekat(CurrentRuangan) == '1' | MejaTerdekat(CurrentRuangan) == '2' | MejaTerdekat(CurrentRuangan) == '3' | MejaTerdekat(CurrentRuangan) == '4') {
						noMeja = CharToInt(MejaTerdekat(CurrentRuangan));					
						Pergi(&Q,&pelanggan,Kapasitas(Elmt(CurrentRuangan,Absis(FindObjek(CurrentRuangan,MejaTerdekat(CurrentRuangan))),Ordinat(FindObjek(CurrentRuangan,MejaTerdekat(CurrentRuangan))))));
						IsiMeja(&CurrentRuangan,MejaTerdekat(CurrentRuangan),Jumlah(pelanggan));
	
						IsiArrayMejaPelanggan(&Mp,noMeja,ruang,pelanggan);
						Time(P) = NextDetik(Time(P));
					}
					else {
						printf("	>> Maaf, anda tidak berada di samping pelanggan\n");
					}
				}
				else if (strcmp(command,"GIVE") == 0) {
					/* memberikan makanan yang ada di nampan paling atas */
					Pop(&S, &makanan);
					noMeja = CharToInt(MejaTerdekat(CurrentRuangan));
					if(strcmp(makanan, Makanan(ArrayMeja(Mp,ruang,noMeja)))==0){
						printf("Makanan yang anda berikan benar\n");
					}
					else {
						printf("goblog, makanannya salah\n");
					}

					Time(P) = NextDetik(Time(P));
				}
				else if (strcmp(command,"RECIPE") == 0) {
					/* menampilkan pohon resep */
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
				PrintPesanan(O);
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
