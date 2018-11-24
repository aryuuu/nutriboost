#include "graph.h"
#include "stdlib.h" 
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST GRAPH KOSONG ******************/
boolean IsGraphEmpty (Graph G)
/* Mengirim true jika list kosong */
{
	return (NodeNeff(G) == Nil);	
}

/****************** PEMBUATAN GRAPH KOSONG ******************/
void CreateEmptyGraph (Graph *G)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	NodeNeff(*G) = Nil;
}

/******************* PEMBUATAN GRAPH ****************************/
void BuatGraph (Graph *G) {
	/* Titik 1 */
	R(Node(*G,1)) =  1;
	Absis(Titik(Node(*G,1))) = 5;
	Ordinat(Titik(Node(*G,1))) = 8;
	/* Titik 2 */
	R(Node(*G,2)) =  1;
	Absis(Titik(Node(*G,2))) = 8;
	Ordinat(Titik(Node(*G,2))) = 5;
	/* Titik 3 */
	R(Node(*G,3)) =  2;
	Absis(Titik(Node(*G,3))) = 5;
	Ordinat(Titik(Node(*G,3))) = 1;
	/* Titik 4 */
	R(Node(*G,4)) =  2;
	Absis(Titik(Node(*G,4))) = 8;
	Ordinat(Titik(Node(*G,4))) = 5;
	/* Titik 5 */
	R(Node(*G,5)) =  3;
	Absis(Titik(Node(*G,5))) = 1;
	Ordinat(Titik(Node(*G,5))) = 5;
	/* Titik 6 */
	R(Node(*G,6)) =  3;
	Absis(Titik(Node(*G,6))) = 5;
	Ordinat(Titik(Node(*G,6))) = 1;
	/* Titik 7 */
	R(Node(*G,7)) =  4;
	Absis(Titik(Node(*G,7))) = 5;
	Ordinat(Titik(Node(*G,7))) = 8;
	/* Titik 8 */
	R(Node(*G,8)) = 4;
	Absis(Titik(Node(*G,8))) = 1;
	Ordinat(Titik(Node(*G,8))) = 5;

	NodeNeff(*G) = 8;

	/* Edge 1 */
	R(Point1(Edge(*G,1))) = 1;
	Absis(Titik(Point1(Edge(*G,1)))) = 5;
	Ordinat(Titik(Point1(Edge(*G,1)))) = 8;
	R(Point2(Edge(*G,1))) = 2;
	Absis(Titik(Point2(Edge(*G,1)))) = 5;
	Ordinat(Titik(Point2(Edge(*G,1)))) = 1;

	/* Edge 2 */
	R(Point1(Edge(*G,2))) = 2;
	Absis(Titik(Point1(Edge(*G,2)))) = 8;
	Ordinat(Titik(Point1(Edge(*G,2)))) = 5;
	R(Point2(Edge(*G,2))) = 3;
	Absis(Titik(Point2(Edge(*G,2)))) = 1;
	Ordinat(Titik(Point2(Edge(*G,2)))) = 5;

	/* Edge 3 */
	R(Point1(Edge(*G,3))) = 3;
	Absis(Titik(Point1(Edge(*G,3)))) = 5;
	Ordinat(Titik(Point1(Edge(*G,3)))) = 1;
	R(Point2(Edge(*G,3))) = 4;
	Absis(Titik(Point2(Edge(*G,3)))) = 5;
	Ordinat(Titik(Point2(Edge(*G,3)))) = 8;

	/* Edge 4 */
	R(Point1(Edge(*G,4))) = 4;
	Absis(Titik(Point1(Edge(*G,4)))) = 1;
	Ordinat(Titik(Point1(Edge(*G,4)))) = 5;
	R(Point2(Edge(*G,4))) = 1;
	Absis(Titik(Point2(Edge(*G,4)))) = 8;
	Ordinat(Titik(Point2(Edge(*G,4)))) = 5;
}

node PindahRuangan (int ruang, int x, int y, Graph G) {
	for (int i = 1; i <= 4; i++) {
		if (R(Point1(Edge(G,i))) == ruang) {
			if (Absis(Titik(Point1(Edge(G,i)))) == x) {
				if (Ordinat(Titik(Point1(Edge(G,i)))) == y) {
					return Point2(Edge(G,i));
				}
			}
		}
		else if (R(Point2(Edge(G,i))) == ruang) {
			if (R(Point2(Edge(G,i))) == ruang) {
				if (Absis(Titik(Point2(Edge(G,i)))) == x) {
					if (Ordinat(Titik(Point2(Edge(G,i)))) == y) {
						return Point1(Edge(G,i));
					}
				}
			}
		}
	}
	node PTemp;
	R(PTemp) = 0;
	Absis(Titik(PTemp)) = 0;
	Ordinat(Titik(PTemp)) = 0;
	return PTemp;
}
