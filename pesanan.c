#include "pesanan.h"
#include "pelanggan.h"
#include <string.h>

void MakeEmpty (Pesanan * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	Neff(*T) = 0;
}

void TambahPesanan(Pelanggan *P, int NomorMeja, Pesanan * T)
/* I.S. P Terdefinisi; Nama Makanan, Jumlah Pelangga */
/* F.S. Pesanan ditambahkan kedalam array Pesanan */  
{
	Neff(*T)++;
	strcpy(*P.makanan,Makanan(*T, Neff(*T)));
	Meja(*T, Neff(*T)) = NomorMeja;
	Jumlah_Pesan(*T, Neff(*T)) = *P.jumlah;
}
