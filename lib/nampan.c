/*	ADT Nampan based from ADT Stack */
	
#include "nampan.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Nampan *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
	Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Nampan S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
	return Top(S) == Nil;
}
boolean IsFull (Nampan S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
	return Top(S) == MaxEl;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Nampan * S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
	if(IsEmpty(*S)){
		Top(*S) = 1;
	} else {
		Top(*S)++;
	}
	strcpy(InfoTop(*S), X);
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Nampan * S, infotype* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	strcpy(*X, InfoTop(*S));
	if(Top(*S) == 1){
		Top(*S) = Nil;
	} else {
		Top(*S)--;
	}
}
