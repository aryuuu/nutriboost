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
	return (GetFirstIdxBrs(M)+NBrsEff(M)-1);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (Ruangan R){
	return (GetFirstIdxKol(M)+NKolEff(M)-1);
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (Ruangan R, indeks i, indeks j){
	return (IsIdxValid(i,j) && i <= NBrsEff(M) && j <= NKolEff(M));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */



void CreateRuangan(Ruangan *R, char N[50], int NB, int NK){
	NamaR(*R) = N;
	NBrsEff(*R) = NB;
	NKolEff(*R) = NK;


	Objek Lantai = CreateObjek('L',0,false);

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
		printf("===");
	}
	printf("\n");

	//cetak bagian 'tengah' ruangan
	for(int i )

}
//cetak ruangan