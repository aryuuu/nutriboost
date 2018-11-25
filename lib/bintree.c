#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"

/* Manajemen Memory */
void AlokNode (addrNode *P, char X) {
  *P = (addrNode) malloc(sizeof(Node));
  if(*P != Nihil){
    Akar(*P)=X;
    Left(*P)=Nihil;
    Right(*P)=Nihil;
  }
}

void BacaResep(BinTree *P, char File[]) {
  START(File);
  BuildTree(P);
}

void BuildTree(BinTree *P) {
/* I.S CC berisi '(' */
/* F.S P Terdefinisi */
  ADV();
  if (CC == ')') {
    (*P) = Nihil;
  }
  else {
    AlokNode(P,CC);
    ADV();
    BuildTree(&(Left(*P)));
    BuildTree(&(Right(*P)));
  }
  ADV();
}

void PrintTreeRecc(BinTree P, int l, int h) {
  if (!IsTreeEmpty(P)) {
    int i;
    for (i = 0; i < l*h; i++){
      printf(" ");
    }
    char Makanan[50];
    KodeMakanan(Akar(P), Makanan);
    printf("%s\n", Makanan);
    PrintTreeRecc(Left(P), l+1, h);
    PrintTreeRecc(Right(P), l+1, h);
  }
}
void PrintTree (BinTree P, int h) {
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
  PrintTreeRecc(P, 0, h);
}

boolean IsTreeEmpty(BinTree P) {//UDAH
  return P == Nihil;
}

/* *** Searching *** */
boolean SearchTree (BinTree P, char X){
/* Mengirimkan true jika ada node dari P yang berNihilai X */
  if(IsTreeEmpty(P)){
    return false;
  }
  if(Akar(P)==X){
    return true;
  } else {
    return SearchTree(Left(P),X) || SearchTree(Right(P),X);
  }
}

/* *** Fungsi-Fungsi Lain *** */
boolean IsSkewLeft (BinTree P){
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
  if (IsTreeEmpty(P)) {
    return true;
  } else {
    return Right(P)==Nihil && IsSkewLeft(Left(P));
  }
}
boolean IsSkewRight (BinTree P){
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
  if (IsTreeEmpty(P)) {
    return true;
  } else {
    return Left(P)==Nihil && IsSkewRight(Right(P));
  }
}
int Level (BinTree P, char X){
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
  if(Akar(P)==X){
    return 1;
  } else {
    return 1+(SearchTree(Left(P),X)?Level(Left(P),X):Level(Right(P),X));
  }
}
int Tinggi (BinTree P){
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
  if (IsTreeEmpty(P)){
    return 0;
  } else {
    return 1+(Tinggi(Left(P))>Tinggi(Right(P))?Tinggi(Left(P)):Tinggi(Right(P)));
  }
}

void KodeMakanan(char CC, char Makanan[50]) {
  switch (CC) {
    case 'p' : strcpy(Makanan, "Piring"); break;
    case 'S' : strcpy(Makanan, "Sendok"); break;
    case 'g' : strcpy(Makanan, "Garpu"); break;
    case 'e' : strcpy(Makanan, "Es Krim"); break;
    case 'n' : strcpy(Makanan, "Nasi"); break;
    case 'r' : strcpy(Makanan, "Roti"); break;
    case 's' : strcpy(Makanan, "Spaghetti"); break;
    case 'b' : strcpy(Makanan, "Pisang"); break;
    case 'o' : strcpy(Makanan, "Stroberi"); break;
    case 't' : strcpy(Makanan, "Telur"); break;
    case 'a' : strcpy(Makanan, "Ayam Goreng"); break;
    case 'k' : strcpy(Makanan, "Patty"); break;
    case 'w' : strcpy(Makanan, "Sosis"); break;
    case 'B' : strcpy(Makanan, "Bolognese"); break;
    case 'c' : strcpy(Makanan, "Carbonara"); break;
    case 'l' : strcpy(Makanan, "Banana Split"); break;
    case 'u' : strcpy(Makanan, "Sundae"); break;
    case 'd' : strcpy(Makanan, "Nasi Telor Dadar"); break;
    case 'G' : strcpy(Makanan, "Nasi Ayam Goreng"); break;
    case 'R' : strcpy(Makanan, "Burger"); break;
    case 'H' : strcpy(Makanan, "Hot Dog"); break;
    case 'K' : strcpy(Makanan, "Keju"); break;
    case 'A' : strcpy(Makanan, "Spaghetti Carbonara"); break;
    case 'T' : strcpy(Makanan, "Spaghetti Bolognese"); break;
  }
}