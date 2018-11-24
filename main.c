#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/player.h"
#include "./lib/ruangan.h"
#include "./lib/pelanggan.h"
#include "./lib/nampan.h"
#include "./lib/pesanan.h"

void PrintJudul(); //print judul nih cuy ada di bawah implementasi

void KurangiKesabaranArrayMejaPelanggan(ArrayMejaPelanggan *M, Player *player,Ruangan *R1,Ruangan *R2,Ruangan *R3);
/* Proses: Mengurangi kesabaran pelanggan dalam array pelanggan di meja */

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
						GerakO(&CurrentRuangan, 'P', 1);
						KurangiKesabaranAntrian(&Q,&P);
						KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
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
						KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
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
						KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
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
						KurangiKesabaranArrayMejaPelanggan(&Mp,&P,&Ruang1,&Ruang2,&Ruang3);
						GeneratePelanggan(&Q);
						Time(P) = NextDetik(Time(P));
					} else {
						printf("	>> Ouch! Kejedut gan!\n");
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
						printf("--------------------------------\n");
						PrintArrayMejaPelanggan(Mp);
						printf("--------------------------------\n");
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

void KurangiKesabaranArrayMejaPelanggan (ArrayMejaPelanggan *M, Player *player,Ruangan *R1,Ruangan *R2,Ruangan *R3)
/* Proses: Mengurangi kesabaran pelanggan dalam array pelanggan di meja */
{
	int i,r;
  r=1;
  while(r<=3){
    i=1;
    while(i<=4) {
      if(FillArrayMeja(*M,r,i))  {
        KurangiKesabaranPelanggan(&ArrayMeja(*M,r,i));
        if(Sabar(ArrayMeja(*M,r,i))==0)  {
					printf("%d %d",r,i);
          Life(*player)--;
          FillArrayMeja(*M,r,i)=false;
          if(r==1)  {
						printf("iiiii");
            UsirPelanggan(R1,i);
          }
          else if(r==2)  {
						printf("aaaaa");
            UsirPelanggan(R2,i);
          }
          else if(r==3)  {
						printf("fddddd");
            UsirPelanggan(R3,i);
          }
					printf("tembus");

        }

      }
      i=i+1;
    }
    r=r+1;
  }
}
