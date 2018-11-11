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
extern boolean EOP;
extern char CC;

#define Panjang(K) (K).Length
#define Karakter(K,i) (K).TabKata[(i)]

void START(char File[]);
//buka file yang dimaksud terus baca

void ADV();
//maju satu baris

void IgnoreBlank();
//kalo ketemu whitespace, maju

void STARTKATA(char File[]);
//mulai kata

void ADVKATA();
//akuisisi kata baru

void SalinKata();
//salin kata hasil akuisisi

void SalinInt(int *result);
//salin kata dan ubah jadi integer

int PanjangKata(Kata K);
//mengembalikan panjang Kata K
//strlen
boolean eqkata(Kata K1, Kata K2);
//mengembalikan true jika K1 dan K2 merupakan kata yang sama
//dan false jika tidak
//strcmp
void CopyKata(Kata sauce, Kata *dest);
//menyalin K1 ke K2
//strcpy
#endif
