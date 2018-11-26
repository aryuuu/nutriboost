#include "pesanan.h"

int main() {
	Pesanan T;
	Pelanggan P;

	MakeEmpty(&T);
	while (int i = 1; i < 3; i++) {
		InitPelanggan(&P);
		TambahPesanan(P, i, i+1, &T);
	}
	PrintPesanan(T);

	HapusPesanan(&T, 1);
	PrintPesanan(T);

	return 0;
}