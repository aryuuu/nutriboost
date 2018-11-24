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

void TambahPesanan(Pelanggan P, int NomorMeja, int Ruang, Pesanan *T)
/* I.S. P Terdefinisi; Nama Food, Jumlah Pelangga */
/* F.S. Pesanan ditambahkan kedalam array Pesanan */  
{
	Neff(*T)++;
	strcpy(Food(*T, Neff(*T)), Makanan(P));
	Table(*T, Neff(*T)) = NomorMeja;
	Ruang(*T, Neff(*T)) = Ruang;
	Jumlah_Pesan(*T, Neff(*T)) = (P).jumlah;
}

void PrintPesanan(Pesanan T)
/* I.s T sudah terdefinisi */
/* F.s Semua pesanan akan tercetak */
{
    if (T.Neff > 0) {
        printf("+++++++++++++++++++++++++++++++++++++++++\n");
	   for (int i = 1; i <= Neff(T); i++) {
            printf("%s : Meja %d di Ruang %d\n", Food(T,i), Jumlah_Pesan(T,i), Table(T,i), Ruang(T,i));
	   }
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
        while ((strcmp(NamaMakanan, Food(T, i)) == 0) && (i < Neff(T))) {
            i++;
        }

        if (strcmp(NamaMakanan, Food(T, i)) == 0) {
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
        strcpy(Food(*T, j), Food(TNew, j));
		Table(TNew, j) = Table(*T, j);
		Ruang(TNew, j) = Ruang(*T, j);
		Jumlah_Pesan(TNew, j) = Jumlah_Pesan(*T, j);
    }

    for (j = i; j <= Neff(*T); j++) {
        strcpy(Food(*T, j), Food(TNew, j+1));
		Table(TNew, j) = Table(*T, j+1);
		Ruang(TNew, j) = Ruang(*T, j+1);
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
        strcpy(Food(Tin, i), Food(*Tout, i));
		Table(*Tout, i) = Table(Tin, i);
		Ruang(*Tout, i) = Ruang(Tin, i);
		Jumlah_Pesan(*Tout, i) = Jumlah_Pesan(Tin, i);
    }
    Neff(*Tout) = Neff(Tin);
}