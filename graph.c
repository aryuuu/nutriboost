#include "graph.h"
#include "stdlib.h" 
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST GRAPH KOSONG ******************/
boolean IsGraphEmpty (Graph G)
/* Mengirim true jika list kosong */
{
	return (First(G) == Nil);	
}

/****************** PEMBUATAN GRAPH KOSONG ******************/
void CreateEmptyGraph (Graph *G)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*G) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Left(P)=Nil, Right(P)=Nil, Up(P)=Nil, Down(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P;
	
	P = (address) malloc (sizeof(ElmtGraph));
	if (P != Nil) {
		Info(P) = X;
		Left(P) = Nil;
		Right(P) = Nil;
		Up(P) = Nil;
		Down(P) = Nil;
		return P;
	}
	else {
		return Nil;
	}
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}
