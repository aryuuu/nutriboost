#ifndef RUANGAN_H
#define RUANGAN_H


#include "boolean.h"
#include <string.h>
#include "point.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int indeks; /* indeks baris, kolom */

typedef struct 
{
	char Nama;//nama benda
	int Kapasitas;//bisa diisi berapa pelanggan
	boolean Fill;//udah terisi apa belum

} Objek;

typedef struct {
	char Nama[50];//nama ruangannya
	Objek Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Ruangan;




/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */



/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]
#define NamaR(M) (M).Nama
#define Nama(O) (O).Nama
#define Kapasitas(O) (O).Kapasitas
#define Fill(O) (O).Fill

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (Ruangan R);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (Ruangan R);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (Ruangan R);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (Ruangan R);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (Ruangan R, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */



void CreateRuangan(Ruangan *R, char N[50], int NB, int NK);
//bikin ruangan baru yang isinya cuma lantai doang, namanya N, ukurannya NBxNK

void SetObjek(Ruangan *R, Objek O, indeks i, indeks j);
//penempatan objek di ruangan di indeks i,j

Objek CreateObjek(char N, int K, boolean F);
//mengembalikan sebuah objek dengan nilai-nilai parameter di atas

void CetakRuangan(Ruangan R);
//cetak ruangan






















#endif