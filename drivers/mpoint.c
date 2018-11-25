/* 
File : mpoint.c
Program MainPoint 
*/

/* gcc point.c mpoint.c -lm -o mpoint */

#include <stdio.h>
#include "point.h"

int main(){
	POINT P1, P2;

	/* *** Test untuk BacaPOINT, TulisPOINT, dan MakePOINT *** */
	printf("Tulis P1 : \n");
	BacaPOINT(&P1); /* MakePOINT sudah termasuk didalam BacaPOINT */
	TulisPOINT(P1);printf("\n");
	printf("Tulis P2 : \n");
	BacaPOINT(&P2);
	TulisPOINT(P2);printf("\n \n");
	/* *** END Test untuk BacaPOINT, TulisPOINT, dan MakePOINT *** */

	/* *** Test untuk Panjang, Jarak0 EQ, dan NEQ *** */
	if (!NEQ(P1,P2)) { /* EQ sudah termasuk didalam NEQ */
		printf("2 titik sama\n");
		printf("Jarak P1 : %f\n\n", Jarak0(P1));
	} else {
		printf("Panjang antara 2 titik : %f\n", Panjang(P1,P2));
		printf("Jarak P1 : %f\n\n", Jarak0(P1));
	}
	/* *** END Test untuk Panjang, EQ, dan NEQ *** */

	/* *** Test untuk IsOrigin, IsOnSbX, IsOnSbY, dan Kuadran *** */
	if (IsOrigin(P1) || IsOnSbX(P1) || IsOnSbY(P1)) {
		printf("Menyentuh garis atau origin\n");
	} else {
		printf("Titik berada di kuadran : %d", Kuadran(P1));printf("\n");
	}
	/* *** END Test untuk IsOrigin, InOnSbX, InOnSbY, dan Kuadran *** */

	/* *** Test untuk NextX, NextY, MirrorOf, Mirror, Geser, Putar, PlusDelta, GeserKeSbX, dan GeserKeSbY *** */
	printf("P1 digeser 1 satuan di X : ");TulisPOINT(NextX(P1));printf("\n");
	printf("P1 digeser 1 satuan di Y : ");TulisPOINT(NextY(P1));printf("\n");
	printf("P1 mirror di X : ");Mirror(&P1,true);TulisPOINT(P1);printf("\n");/* MirrorOf sudah berada didalam Mirror */
	/*printf("P1 digeser 10 satuan di X 30 satuan di Y : ");Geser(&P1,10,30);TulisPOINT(P1);printf("\n"); /* PlusDelta sudah berada didalam Geser */
	printf("P1 diputar 90 derajat : ");Putar(&P1,360);TulisPOINT(P1);printf("\n");
	printf("P1 digeser ke X : ");GeserKeSbX(&P1);TulisPOINT(P1);printf("\n");
	printf("P1 digeser ke Y : ");GeserKeSbY(&P1);TulisPOINT(P1);printf("\n");
	/* *** END Test untuk NextX, NextY, MirrorOf, Mirror, Geser, Putar, PlusDelta, GeserKeSbX, dan GeserKeSbY *** */

	return 0;
}