#ifndef _PESANAN_H
#define _PESANAN_H

#include "boolean.h"

#define Makanan(P, i) Pesanan.TabPesan[i].makanan
#define Meja(P, i) Pesanan.TabPesan[i].meja
#define Jumlah_Pesan(P, i) Pesanan.TabPesan[i].jumlah

typedef struct {
	char makanan[50]; /* Nama pesanan */
	int meja; /* nomor meja yang memesan */
	int jumlah; /* jumlah pesanan */
} ElType; 

typedef struct {
	ElType TabPesan[IdxMax+1];
	int Neff;
} Pesanan;

void CreateEmpty()

void TambahPesanan();

void KurangPesanan();

#endif