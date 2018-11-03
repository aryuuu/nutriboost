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
	if(CC == MARK){
		EndKata = true;
	} else {
		SalinKata();
	}

	IgnoreBlank();
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

	SalinKata();
	

	for(i = 1; i <= CKata.Length; i++){
		a = a*10 + (int)(CKata.TabKata[i]-48);
	}

	*result = a;

	IgnoreBlank();
	

}
//salin kata dan ubah jadi integer
