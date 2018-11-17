#include "player.h"
#include <stdio.h>
#include <string.h>

int main() {
	Player P;
	char X[50];

	KosongTangan(&P);
	scanf("%s", &X);
	while (strcmp(X, "Exit") != 0) {
		IsiTangan(&P, X);
		scanf("%s", &X);
	}

	CetakTangan(P);
}