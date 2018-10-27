#ifndef _PESANAN_H
#define _PESANAN_H

#include "boolean.h"

#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */

typedef struct {
	char makanan[50]; /* Nama pesanan */
	int meja; /* nomor meja yang memesan */
	int jumlah; /* jumlah pesanan */
} ElType; 

typedef struct {
	ElType TabPesan[IdxMax+1];
	int Neff;
} Pesanan;

#define Makanan(P, i) Pesanan.TabPesan[i].makanan
#define Meja(P, i) Pesanan.TabPesan[i].meja
#define Jumlah_Pesan(P, i) Pesanan.TabPesan[i].jumlah
#define Neff(P) Pesanan.Neff

void MakeEmpty(Pesanan * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

void TambahPesanan(Pelanggan *P, int NomorMeja, Pesanan * T);
/* I.S. P Terdefinisi; Nama Makanan, Jumlah Pelangga */
/* F.S. Pesanan ditambahkan kedalam array Pesanan */   

void KurangPesanan();

#endif