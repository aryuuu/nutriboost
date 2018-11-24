#ifndef graph_H
#define graph_H

#include "boolean.h"  
#include "point.h"

#define Nil 0

typedef struct {
	int ruangan;
	POINT titik;
} node;

typedef struct {
	node P1;
	node P2;
} edge;

typedef struct { 
	node Node[8+1];
	edge Edge[4+1];
	int NodeNeff;
} Graph;

/* Definisi graph : */
/* G = (V,E) : V adalah kumpulan titik, E adalah kumpulan busur */
/* Graf Kosong : V tidak ada atau kosong */

/* G adalah Graph, E adalah edge */

#define Node(G, i) (G).Node[i]
#define Edge(G, i) (G).Edge[i]
#define Point1(E) (E).P1
#define Point2(E) (E).P2
#define R(N) (N).ruangan
#define Titik(N) (N).titik
#define NodeNeff(G) (G).NodeNeff

/* PROTOTYPE */
/****************** TEST GRAPH KOSONG ******************/
boolean IsGraphEmpty (Graph G);
/* Mengirim true jika graph kosong */

/****************** PEMBUATAN GRAPH KOSONG ******************/
void CreateEmptyGraph (Graph *G);
/* I.S. sembarang             */
/* F.S. Terbentuk graph kosong */

void BuatGraph (Graph *G);
/* I.S sembarag */
/* F.S Graph jadi seperti yang ada di Spek */

node PindahRuangan (int ruang, int x, int y, Graph G);

#endif
