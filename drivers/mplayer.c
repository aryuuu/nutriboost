#include "player.h"

int main() {
	char Nama[50];
	Player P;

	scanf("%s", Nama);
	InitPlayer(&P, Nama);

	PrintState(P);
	while (int i = 0; i < 3; i++) {
		scanf("%c", &KodeM);
		IsiTangan(&P. KodeM);
	}

	CetakTangan(P);
	return 0;
}