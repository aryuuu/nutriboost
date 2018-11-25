#include "recipe.h"
#include <stdio.h>

IdxType searchItemId(TabItem items, Item item){
	IdxType i;
	i = 0;
	while(i < IdxMax){
		if(strcmp(item, TabItem[i])){
			break;
		}
		i++;
	}
	return i;
}

void lihatResep(BinTree resep, TabItem items, Item makanan){
	BinTree temp;
	int i;
	
	if(!SearchTree(resep, searchItemId(items, makanan)){
		printf("Resep tidak tersedia\n");
	} else {
		i = 1;
		printf("Resep untuk %s\n", makanan);
		printf("%d. %s\n", i, items[Akar(resep)]);
		temp = resep;
		while(!strcmp(items[Akar(temp)], makanan){
			if(SearchTree(Left(temp), searchItemId(items, makanan)){
				temp = Left(temp);
				printf("%d. %s\n", i, items[Akar(temp)]);
			} else {
				temp = Right(temp);
				printf("%d. %s\n", i, items[Akar(temp)]);
			}
			i++;
		}
	}
}