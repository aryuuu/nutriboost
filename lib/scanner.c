#include "scanner.h"
#include <stdio.h>

char CC;
boolean EOP;
boolean EndKata;
Kata CKata;

static FILE * sauce;
static int retval;

void START(char File[]){
	sauce = fopen(File,"r");
	ADV();
}
//buka file yang dimaksud terus baca

void ADV(){
	retval = fscanf(sauce, "%c", &CC);//baca satu baris file
	EOP = (CC == MARK);
	if(EOP){
		fclose(sauce);
	}
}
//maju 

void IgnoreBlank(){
	while(((CC == BLANK) || (CC == NEWLINE)) && (CC != MARK)){
		ADV();
	}
}
//kalo ketemu whitespace, maju, neewline juga

void STARTKATA(char File[]){
	START(File);
	IgnoreBlank();
	if(CC == MARK){
		EndKata = true;
	} else {
		EndKata = false;
		SalinKata();
	}
}
//mulai kata

void ADVKATA(){
	IgnoreBlank();

	if(CC == MARK){
		EndKata = true;
	} else {
		SalinKata();
	}

	
}
//akuisisi kata baru

void SalinKata(){
	int i;
	int pjg = 0;
	for(i = 1; i <= NMax; i ++){
		if(CC == MARK || CC == BLANK){
			break;
		} else {
			CKata.TabKata[i] = CC;
			pjg++;
			ADV();
		}
	}
	CKata.Length = pjg;
}
//salin kata hasil akuisisi

void SalinInt(int *result){
	int i;
	int a = 0;

	ADVKATA();
	

	for(i = 1; i <= CKata.Length; i++){
		a = a*10 + (int)(CKata.TabKata[i]-48);
	}

	*result = a;

	IgnoreBlank();
	

}
//salin kata dan ubah jadi integer

int PanjangKata(Kata K){
	return K.Length;
}
//mengembalikan panjang Kata K
//strlen

boolean eqkata(Kata K1, Kata K2){

	if(PanjangKata(K1) != PanjangKata(K2)){
		return false;
	} else {
		boolean same = true;
		int i = 1;

		while(i <= PanjangKata(K1) && same){
			if(K1.TabKata[i] != K2.TabKata[i]){
				same = false;
			} else{
				i++;
			}

		}
		return same;
	}
}
//mengembalikan true jika K1 dan K2 merupakan kata yang sama
//dan false jika tidak
//strcmp

void CopyKata(Kata sauce, Kata *dest){
	Panjang(*dest) = PanjangKata(sauce);

	for(int i = 1; i <= PanjangKata(sauce); i++){
		Karakter(*dest,i) = sauce.TabKata[i];
	}
}
//menyalin K1 ke K2
//strcpy