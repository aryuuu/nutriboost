/* 
File : mjam.c
Program MainJam 
*/

#include <stdio.h>
#include "jam.h"
int main()
{
	JAM J1, J2, J3;
	int N;

	J3=MakeJAM(24,0,0);
	/* *** Test untuk BacaJAM, TulisJAM, IsJAMValid, MakeJAM, JAMToDetik, dan DetikToJAM *** */
	printf("Tulis Jam J1: \n");
	BacaJAM(&J1); /* IsJAMValid sudah termasuk didalam BacaJAM */
	TulisJAM(J1); printf("\n"); /* MakeJAM sudah termasuk didalam TulisJAM */
	printf("Jam J1 ke detik : %ld\n\n", JAMToDetik(J1));

	printf("Tulis Jam J2: \n");
	BacaJAM(&J2);
	TulisJAM(J2); printf("\n");
	printf("Jam J1 ke detik : %ld\n\n", JAMToDetik(J2));
	printf("%ld \n", JAMToDetik(J3));
	printf("86400 detik adalah :");
	TulisJAM(DetikToJAM(86400)); printf("\n\n");
	/* *** END Test untuk BacaJAM, TulisJAM, IsJAMValid, dan MakeJAM *** */


	/* *** Test untuk JEQ, JNEQ, JLT, JGT, Durasi *** */
	if (!JNEQ(J1,J2)){ /* JEQ sudah termasuk didalam JNEQ*/
		printf("J1 dan J2 sama\n");
	} else {
		printf("J1 dan J2 berbeda\n");
	}

	printf("Durasi J1 dan J2 : %ld\n\n", Durasi(J1,J2)); /* JLT sudah termasuk didalam Durasi. NB : Asumsi jika JLT berfungsi JGT juga berfungsi, karena struktur kode sama */
	/* *** END Test untuk JEQ, JNEQ, JLT, JGT, Durasi *** */

	/* *** Test untuk NextDetik, NextNDetik, PrevDetik, PrevNDetik *** */
	printf("1 detik setelah J1 : ");
	TulisJAM(NextDetik(J1));printf("\n");
	printf("1 detik sebelum J1 : ");
	TulisJAM(PrevDetik(J1));printf("\n");

	printf("61 detik setelah J1 : ");
	TulisJAM(NextNDetik(J1,61));printf("\n");
	printf("61 detik sebelum J1 : ");
	TulisJAM(PrevNDetik(J1,61));printf("\n");

	/* *** END Test untuk NextDetik, NextNDetik, PrevDetik, PrevNDetik *** */
	return 0;
}