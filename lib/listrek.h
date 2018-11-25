/* File: listrek.h */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#ifndef _LISTREK_H_
#define _LISTREK_H_

#include "boolean.h"
#include "point.h"

#define Nihil NULL

/* Definisi Type */
typedef struct {
	int ruangan;
	POINT titik;
} infoNode;

typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infoNode info;
	address next;
	address succ;
} ElmtList;

/* Definisi list : */
/* List kosong : L = Nil */
typedef address List;

/* Deklarasi  nama untuk variabel kerja */ 
/*  	L : List */
/*  	P : address 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
#define InfoRuangan(P) (P)->info.ruangan
#define InfoAbsis(P) (P)->info.titik.X
#define InfoOrdinat(P) (P)->info.titik.Y
#define Next(P) (P)->next
#define Succ(P) (P)->succ

/* *** Manajemen Memori *** */
address Alokasi (int ruangan, int x, int y);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

#endif