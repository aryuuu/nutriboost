#include <stdio.h>
#include "graph.h"

int main () {
	Graph G;
	infotype Ruangan;
	address P;
	
	/*
	Gambar Ruangan
	 1 | 2
	---|---
	 4 | 3
	*/
	
	CreateEmptyGraph(&G);
	Ruangan = 1;
	P = Alokasi(Ruangan);
	First(G) = P;
	Right(P) = 2;
	Down(P) = 4;
	P = Alokasi(Right(P));
	Left(P) = 1;
	Down(P) = 3;
	P = Alokasi(Down(P));
	Up(P) = 2;
	Left(P) = 4;
	P = Alokasi(Left(P));
	Up(P) = 1;
	Right(P) = 3;
	
	P = First(G);
	printf("%d", Down(P));
		
	return 0;
}
