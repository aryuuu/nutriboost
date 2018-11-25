#include "graph.h"
#include "stdlib.h" 
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST GRAPH KOSONG ******************/
boolean IsGraphEmpty(Graph G)
/* Mengirim true jika list kosong */
{
	return (G == Nihil);	
}

/****************** PEMBUATAN GRAPH KOSONG ******************/
void CreateEmptyGraph (Graph *G)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	*G = Nihil;
}

address SearchNode(Graph G, int ruangan, int x, int y) {
	if (IsGraphEmpty(G)) {
		return Nihil;
	}
	else {
		if (InfoRuangan(G) == ruangan && InfoAbsis(G) == x && InfoOrdinat(G) == y) {
			return G;
		}
		else {
			return SearchNode(Next(G), ruangan, x, y);
		}
	}
}

/******************* PEMBUATAN GRAPH ****************************/
void BuatGraph (Graph *G) {
	address P1,P2,P3,P4,P5,P6,P7,P8;
	/* Pembuatan Titik */
	P1 = Alokasi(1, 8, 5); //Ruang 1 ke Dapur
	P2 = Alokasi(1, 5, 8); //Ruang 1 ke Ruang 3
	P3 = Alokasi(2, 1, 5); //Ruang 2 ke Ruang 3
	P4 = Alokasi(2, 5, 8); //Ruang 2 ke Ruang 1
	P5 = Alokasi(3, 5, 1); //Ruang 3 ke Dapur
	P6 = Alokasi(3, 1, 5); //Ruang 3 ke Ruang 2
	P7 = Alokasi(4, 5, 1); //Dapur ke Ruang 3
	P8 = Alokasi(4, 8, 5); //Dapur ke Ruang 1

	*G = P1;
	Next(P1) = P2;
	Succ(P1) = P3;

	Next(P2) = P3;
	Succ(P2) = P7;

	Next(P3) = P4;
	Succ(P3) = P1;

	Next(P4) = P5;
	Succ(P4) = P5;

	Next(P5) = P6;
	Succ(P5) = P4;

	Next(P6) = P7;
	Succ(P6) = P8;

	Next(P7) = P8;
	Succ(P7) = P2;

	Next(P8) = Nihil;
	Succ(P8) = P6;
}

void PindahRuangan (int *ruang, int *x, int *y, Graph G) {
	if (SearchNode(G,*ruang, *x, *y) != Nihil) {
		printf("ruang %d x %d y %d\n", *ruang, *x, *y);
		address P2 = Succ(SearchNode(G,*ruang, *x, *y));
		*ruang = InfoRuangan(P2);
		*x = InfoAbsis(P2);
		*y = InfoOrdinat(P2);
		printf("ruang %d x %d y %d\n", *ruang, *x, *y);
	}
}
