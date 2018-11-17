#include "player.h"
#include <string.h>
#include <stdio.h>

void InitPlayer(Player *P, char nama[50]) {
	strcpy(Name(*P), nama);
	Money(*P) = 0;
	Life(*P) = 2; 
	Time(*P) = MakeJAM(0,0,0);
	Posisi(*P) = MakePOINT(1,1);
	Ruangan(*P)  = 1;
}

void PrintState(Player P) {
	printf("Name : %s | Money : %d | Life : %d\n", Name(P), Money(P), Life(P));
	TulisJAM(Time(P));printf("\n");
}

void Gerak(Player *P, char opsi[50]) {
/* I.S Posisi Player terdefinisi */
/* F.S Posisi berubah sesuai kemauan : GU keatas, GD kebawah, GL kekiri, GR kekanan */
	if (strcmp(opsi, "GU") == 0) {
		Geser(&Posisi(*P), 0, 1);
	}
	else if (strcmp(opsi, "GD") == 0) {
		Geser(&Posisi(*P), 0, -1);
	}
	else if (strcmp(opsi, "GL") == 0) {
		Geser(&Posisi(*P), -1, 0);
	}
	else if (strcmp(opsi, "GR") == 0) {
		Geser(&Posisi(*P), 1, 0);
	}
}

void IsiTangan(Player *P, char Makanan[50]) {
	TOPTangan(*P)++;
	strcpy(InfoTOPTangan(*P), Makanan);
}

void KosongTangan(Player *P) {
	TOPTangan(*P) = Nil;
}

void KeluarkanMakanan(Player *P, char Makanan[50]) {
	strcpy(Makanan,InfoTOPTangan(*P));
	TOPTangan(*P)--;
}

void CetakTangan(Player P) {
	Player temp;
	KosongTangan(&temp);
	char X[50];

	while (TOPTangan(P) != Nil) {
		KeluarkanMakanan(&P, X);
		IsiTangan(&temp, X);
	}

	while (TOPTangan(temp) != Nil) {
		KeluarkanMakanan(&temp, X);
		printf("%s\n", X);
	}
}