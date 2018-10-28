#include "ruangan.h"
#include <stdio.h>

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
	return ((i >= BrsMin) && (i <= BrsMax) && (j >= KolMin) && (j <= KolMax));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (Ruangan R){
	return (BrsMin);
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (Ruangan R){
	return (KolMin);
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (Ruangan R){
	return (GetFirstIdxBrs(R)+NBrsEff(R)-1);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (Ruangan R){
	return (GetFirstIdxKol(R)+NKolEff(R)-1);
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (Ruangan R, indeks i, indeks j){
	return (IsIdxValid(i,j) && i <= NBrsEff(R) && j <= NKolEff(R));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */



void CreateRuangan(Ruangan *R, char N[50], int NB, int NK){
	strcpy(NamaR(*R),N);
	NBrsEff(*R) = NB;
	NKolEff(*R) = NK;

	char NO = 'L';
	Objek Lantai = CreateObjek(NO,0,false);

	for(int i = GetFirstIdxBrs(*R); i <= GetLastIdxBrs(*R); i++){
		for(int j = GetFirstIdxKol(*R); j <= GetLastIdxKol(*R); j++){
			SetObjek(R,Lantai,i,j);
		}
	}
}
//bikin ruangan baru yang isinya cuma lantai doang, ukurannya NBxNK

void SetObjek(Ruangan *R, Objek O, indeks i, indeks j){
	Elmt(*R,i,j).Nama = Nama(O);
	Elmt(*R,i,j).Kapasitas = Kapasitas(O);
	Elmt(*R,i,j).Fill = Fill(O);
}
//penempatan objek di ruangan di indeks i,j


Objek CreateObjek(char N, int K, boolean F){
	Objek result;

	Nama(result) = N;
	Kapasitas(result) = K;
	Fill(result) = F;

	return result;
}
//mengembalikan sebuah objek dengan nilai-nilai parameter di atas


void CetakRuangan(Ruangan R){

	//cetak dinding atas, 
	for(int i = GetFirstIdxKol(R); i <= GetLastIdxKol(R); i++){
		printf("========");
	}
	printf("\n");

	//cetak bagian 'tengah' ruangan
	for(int i = GetFirstIdxBrs(R); i <= GetLastIdxBrs(R); i++ ){
		for(int j = GetFirstIdxKol(R); j <= GetLastIdxKol(R); j++){
			printf("|      |");//beri sedikit ruang
		}
		printf("\n");

		for (int j = GetFirstIdxKol(R); j <= GetLastIdxKol(R); j++){
			if(Nama(Elmt(R,i,j)) == 'L'){
				printf("|      |");//cetak lantai
			} else if(Nama(Elmt(R,i,j)) >  48 && Nama(Elmt(R,i,j)) < 58){
				printf("|   %c  |",Nama(Elmt(R,i,j)));//cetak meja
			}else if(Nama(Elmt(R,i,j)) == 'K'){
				printf("|   K  |");//cetak kursi
			}else if(Nama(Elmt(R,i,j)) == 'P'){
				printf("|   P  |");//cetak player
			}else if(Nama(Elmt(R,i,j)) == 'C'){
				printf("|   C  |");//cetak costumer
			}
		}
		printf("\n");

		for(int j = GetFirstIdxKol(R); j <= GetLastIdxKol(R); j++){
			printf("|      |");//beri sedikit ruang
		}
		printf("\n");

		for(int j = GetFirstIdxKol(R); j <= GetLastIdxKol(R); j++){
			printf("========");//sekat pemmbatas antar blok objek
		}
		printf("\n");
		
	}

}
//cetak ruangan


void BacaRuangan(Ruangan *R, chr File[50]);
//membentuk ruangan baru dengan masukan dari file eksternal
