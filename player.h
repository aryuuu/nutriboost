#ifndef _PLAYER_H
#define _PLAYER_H

#include "jam.h"
#include "point.h"

typedef struct {
	char name[50];
	int money;
	int life;
	JAM time;
	POINT posisi; 
	int ruangan; /* Ruangan 1, 2, 3, dan 4(dapur) */
} Player;

#define Name(P) (P).name
#define Money(P) (P).money
#define Life(P) (P).life
#define Time(P) (P).time
#define Posisi(P) (P).posisi
#define Ruangan(P) (P).ruangan

void InitPlayer(Player *P, char nama[50]);
/* I.S Player sembarang */
/* F.S Player terdefinisi */

void PrintState(Player P);
/* I.S Player Terdefinisi */
/* F.S Print kondisi player */

void Gerak(Player *P, char opsi[50]);
/* I.S Posisi Player terdefinisi */
/* F.S Posisi berubah sesuai kemauan : GU keatas, GD kebawah, GL kekiri, GR kekanan */

#endif

