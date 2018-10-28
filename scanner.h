#ifndef SCANNER_H
#define SCANNER_H

#include "boolean.h"

#define MARK '.'
#define NEWLINE '\n'
#define NMax 50
#define BLANK ' '

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
	int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;
extern char CL[50];
extern boolean EOP;

void START(char File[50]);
//buka file yang dimaksud terus baca

void ADV();
//maju satu baris

void IgnoreBlank();
//kalo ketemu whitespace, maju

void STARTKATA(char File[50]);
//mulai kata

void ADVKATA();
//akuisisi kata baru

void SalinKata();
//salin kata hasil akuisisi

void SalinInt(int result);
//salin kata dan ubah jadi integer

#endif