#ifndef recipe_H
#define recipe_H

#include "bintree.h"
#include "player.h"
#include "boolean.h"
#include <string.h>

/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

typedef char [25] Item;
typedef Item [IdxMax+1] TabItem;
typedef char [25] Makanan;

IdxType searchItemId(TabItem items,Item item);
void lihatResep(BinTree resep, TabItem items);

#endif
