#ifndef _PESANAN_H
#define _PESANAN_H

#include "boolean.h"
#include "pelanggan.h"

#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

typedef int IdxType;
typedef struct {
	char makanan[50]; /* Nama pesanan */
	int meja; /* nomor meja yang memesan */
	int ruangan;
	int jumlah; /* jumlah pesanan */
} ElType; 

typedef struct {
	ElType TabPesan[IdxMax+1];
	int Neff;
} Pesanan;

#define Food(P, i) (P).TabPesan[i].makanan
#define Table(P, i) (P).TabPesan[i].meja
#define Ruang(P, i) (P).TabPesan[i].ruangan
#define Jumlah_Pesan(P, i) (P).TabPesan[i].jumlah
#define Neff(P) (P).Neff

void MakeEmpty(Pesanan * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

boolean PesananKosong(Pesanan T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

void TambahPesanan(Pelanggan P, int NomorMeja, int Ruangan, Pesanan * T);
/* I.S. P Terdefinisi; Nama Makanan, Jumlah Pelangga */
/* F.S. Pesanan ditambahkan kedalam array Pesanan */   

void PrintPesanan(Pesanan T);
/* I.s T sudah terdefinisi */
/* F.s Semua pesanan akan tercetak */

IdxType Search (Pesanan T, char NamaMakanan[50]);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */

void HapusPesanan (Pesanan *T, IdxType i);
/* Menghapus pesanan pada indeks ke-i */

void CopyTab (Pesanan Tin, Pesanan * Tout);
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */

void CetakPesanan(Pesanan O);
/* mencetak isi pesanan */


#endif