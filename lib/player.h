#ifndef _PLAYER_H
#define _PLAYER_H

#include "jam.h"
#include "point.h"

#define Nil 0
#define MaxEl 10

typedef int address;

typedef struct { 
	char T[MaxEl+1][50]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} Hand;

typedef struct {
	char name[50];
	int money;
	int life;
	JAM time;
	POINT posisi; 
	int ruangan; /* Ruangan 1, 2, 3, dan 4(dapur) */
	Hand tangan;
} Player;

#define Name(P) (P).name
#define Money(P) (P).money
#define Life(P) (P).life
#define Time(P) (P).time
#define Posisi(P) (P).posisi
#define Ruangan(P) (P).ruangan
#define Tangan(P) (P).tangan
#define TOPTangan(P) (P).tangan.TOP
#define InfoTOPTangan(P) (P).tangan.T[(P).tangan.TOP]

void InitPlayer(Player *P, char nama[50]);
/* I.S Player sembarang */
/* F.S Player terdefinisi */

void PrintState(Player P);
/* I.S Player Terdefinisi */
/* F.S Print kondisi player */

void Gerak(Player *P, char opsi[50]);
/* I.S Posisi Player terdefinisi */
/* F.S Posisi berubah sesuai kemauan : GU keatas, GD kebawah, GL kekiri, GR kekanan */

void IsiTangan(Player *P, char Makanan[50]);
/* I.S Tangan bisa kosong */
/* F.S Tangan diisikan Makanan */

void KosongTangan(Player *P);
/* I.S Tangan terdefinisi bisa kosong bisa tidak */
/* F.S Kosongkan tangan */

void KeluarkanMakanan(Player *P, char Makanan[50]);

void CetakTangan(Player P);
/* Mencetak semua apa yang ada di Tangan */

#endif

