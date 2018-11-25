#ifndef graph_H
#define graph_H

#include "boolean.h"  
#include "point.h"
#include "listrek.h"

#define Nihil NULL

typedef List Graph;

/* Definisi graph : */
/* G = (V,E) : V adalah kumpulan titik, E adalah kumpulan busur */
/* Graf Kosong : V tidak ada atau kosong */
/* G adalah Graph, E adalah edge */

/* PROTOTYPE */
/****************** TEST GRAPH KOSONG ******************/
boolean IsGraphEmpty (Graph G);
/* Mengirim true jika graph kosong */

/****************** PEMBUATAN GRAPH KOSONG ******************/
void CreateEmptyGraph (Graph *G);
/* I.S. sembarang             */
/* F.S. Terbentuk graph kosong */

address SearchNode(Graph G, int ruangan, int x, int y);

void BuatGraph (Graph *G);
/* I.S sembarag */
/* F.S Graph jadi seperti yang ada di Spek */

void PindahRuangan (int *ruang, int *x, int *y, Graph G);

#endif
