#ifndef graph_H
#define graph_H

#include "boolean.h"  

#define Nil NULL

typedef int infotype;
typedef struct tElmtgraph *address;
typedef struct tElmtgraph { 
	infotype info;
	address up;
	address down;
	address left;
	address right;
} ElmtGraph;
typedef struct {
	address First;
} Graph;

/* Definisi graph : */
/* Graph kosong : First(G) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Left(P), Right(P), Up(P), Down(P) */

#define Info(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Up(P) (P)->up
#define Down(P) (P)->down
#define First(L) (L).First

/* PROTOTYPE */
/****************** TEST GRAPH KOSONG ******************/
boolean IsGraphEmpty (Graph G);
/* Mengirim true jika graph kosong */

/****************** PEMBUATAN GRAPH KOSONG ******************/
void CreateEmptyGraph (Graph *G);
/* I.S. sembarang             */
/* F.S. Terbentuk graph kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Left(P)=Nil, Right(P)=Nil, Up(P)=Nil, Down(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

#endif
