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

void PrintPesanan(Pesanan P){
	for (int i = 1; i <= Neff(P); i++) {
		printf("%s, %d : Meja %d di Ruang %d\n", Makanan(P,i), Jumlah_Pesan(P,i), Meja(P,i), Ruangan(P,i));
	}

}