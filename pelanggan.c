#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelanggan.h"


void SalinPelanggan(Pelanggan *P1,Pelanggan P2)
{
  (*P1).jumlah = P2.jumlah;
  (*P1).sabar = P2.sabar;
  strcmp((*P1).makanan,(P2).makanan);
  (*P1).layan = P2.layan;
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
  if(Head(Q)<Tail(Q)) {
    return(Tail(Q)-Head(Q)+1 );
  }
  else if(Head(Q)==Nil && Tail(Q)==Nil) {
    return 0;
  }
  else  {
    return(Tail(Q)+MaxEl-Head(Q)+1);
  }
}

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
  return((Head(Q) == Nil)&&(Tail(Q)==Nil));
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return(NBElmt(Q) == MaxEl);
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
  Head(*Q)=0;
  Tail(*Q)=0;

}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, Pelanggan X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
  if(IsEmpty(*Q)) {
    Head(*Q)=1;
    Tail(*Q)=1;
    SalinPelanggan(&InfoTail(*Q),X);
  }
  else if(!IsFull(*Q)) {
    Tail(*Q)++;
    if(Tail(*Q)>MaxEl)  {
      Tail(*Q)= 1;
    }
    SalinPelanggan(&InfoTail(*Q),X);
}
}

void Del (Queue * Q, Pelanggan * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
  if(!IsFull(*Q)) {
    SalinPelanggan(X,InfoTail(*Q));
    Head(*Q)++;
    if(Head(*Q)>MaxEl)  {
      Head(*Q)= 1;
    }
  }
}
