#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"
/* *** Manajemen Memori *** */
address Alokasi (int ruangan, int x, int y){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	address P= (address) malloc(sizeof(ElmtList));
	if(P!= Nihil){
		InfoRuangan(P)=ruangan;
		InfoAbsis(P)=x;
		InfoOrdinat(P)=y;
		Next(P)=Nihil;
		Succ(P)=Nihil;
	}
	return P;
}
void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
	free(P);
}
