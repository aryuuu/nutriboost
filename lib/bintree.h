/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type int, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

#ifndef _BINTREE_H_
#define _BINTREE_H_

/* Modul lain yang digunakan : */
#include "listrek.h"
#include "boolean.h"
#include "scanner.h"

/* #define Nil NULL */ /* konstanta Nil sesuai pada modul listrek */

/* *** Definisi Type Pohon Biner *** */
/* typedef int int; */ /* type infotype sesuai pada modul listrek */
typedef struct tNode *addrNode;
typedef struct tNode { 
	char info;
	addrNode left;
	addrNode right;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;
 
/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

void AlokNode(BinTree *P, char X);

void BuildTree(BinTree *P);

void BacaResep(BinTree *P, char File[]);

void KodeMakanan(char CC, char Makanan[50]);

void PrintTree(BinTree P, int h);

boolean IsTreeEmpty(BinTree P);

boolean IsTreeOneElmt(BinTree P);

boolean SearchTree (BinTree P, char X);

#endif