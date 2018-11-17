#include "point.h"
#include <stdio.h>
#include <math.h>


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y){
	POINT p;
	Absis(p) = X;
	Ordinat(p) = Y;
	return p;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
	int x,y;
	scanf("%d %d",&x,&y);
	*P = MakePOINT(x,y);
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P){
	printf("(%d,%d)",Absis(P),Ordinat(P) );
}
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2){
	return !EQ(P1,P2);
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */


/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){

	return(MakePOINT((Absis(P)+1),(Ordinat(P))));
}
/* Mengirim salinan P dengan absis ditambah satu */              
POINT NextY (POINT P){

	return(MakePOINT((Absis(P)),(Ordinat(P)+1)));
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, int deltaX, int deltaY){

	return(MakePOINT((Absis(P)+deltaX),(Ordinat(P)+deltaY)));
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */

/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */



/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
void Geser (POINT *P, int deltaX, int deltaY){

	*P = MakePOINT((Absis(*P)+deltaX),(Ordinat(*P)+deltaY));
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */



