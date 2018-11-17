#include "pesanan.h"
#include "pelanggan.h"
#include <string.h>
#include <stdio.h>

void MakeEmpty(Pesanan * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	Neff(*T) = 0;
}

boolean PesananKosong(Pesanan T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return Neff(T) == 0;
}

void TambahPesanan(Pelanggan *P, int NomorMeja, int Ruangan, Pesanan *T)
/* I.S. P Terdefinisi; Nama Makanan, Jumlah Pelangga */
/* F.S. Pesanan ditambahkan kedalam array Pesanan */  
{
	Neff(*T)++;
	strcpy((*P).makanan,Makanan(*T, Neff(*T)));
	Meja(*T, Neff(*T)) = NomorMeja;
	Ruangan(*T, Neff(*T)) = Ruangan;
	Jumlah_Pesan(*T, Neff(*T)) = (*P).jumlah;
}

void PrintPesanan(Pesanan T)
/* I.s T sudah terdefinisi */
/* F.s Semua pesanan akan tercetak */
{
	for (int i = 1; i <= Neff(T); i++) {
		printf("%s, %d : Meja %d di Ruang %d\n", Makanan(T,i), Jumlah_Pesan(T,i), Meja(T,i), Ruangan(T,i));
	}

}

IdxType Search (Pesanan T, char NamaMakanan[50]) {
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    if (PesananKosong(T)) {
        return IdxUndef;
    }
    else { //array tidak kosong
        i = IdxMin;
        while ((strcmp(NamaMakanan, Makanan(T, i)) == 0) && (i < Neff(T))) {
            i++;
        }

        if (strcmp(NamaMakanan, Makanan(T, i)) == 0) {
            return i;
        }
        else {
            return IdxUndef;
        }
    }
}

void HapusPesanan(Pesanan *T, IdxType i) {
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosoPesanan *P, int ing, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
	/* KAMUS LOKAL */
    Pesanan TNew;
    IdxType j;

    for (j = IdxMin; j < i; j++) {
        strcpy(Makanan(*T, j), Makanan(TNew, j));
		Meja(TNew, j) = Meja(*T, j);
		Ruangan(TNew, j) = Ruangan(*T, j);
		Jumlah_Pesan(TNew, j) = Jumlah_Pesan(*T, j);
    }

    for (j = i; j <= Neff(*T); j++) {
        strcpy(Makanan(*T, j), Makanan(TNew, j+1));
		Meja(TNew, j) = Meja(*T, j+1);
		Ruangan(TNew, j) = Ruangan(*T, j+1);
		Jumlah_Pesan(TNew, j) = Jumlah_Pesan(*T, j+1);
    }

    Neff(TNew) = Neff(*T) - 1;

    CopyTab(TNew, T);
}

void CopyTab (Pesanan Tin, Pesanan * Tout) {
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
	/* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    for (i = IdxMin; i <= Neff(Tin); i++) {
        strcpy(Makanan(Tin, i), Makanan(*Tout, i));
		Meja(*Tout, i) = Meja(Tin, i);
		Ruangan(*Tout, i) = Ruangan(Tin, i);
		Jumlah_Pesan(*Tout, i) = Jumlah_Pesan(Tin, i);
    }
    Neff(*Tout) = Neff(Tin);
}