#include "bintree.h"

int main() {
	BinTree T;

	BacaResep(&T,"resep.txt");
	PrintTree(T, 2);

	return 0;
}