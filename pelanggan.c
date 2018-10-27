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
/* Mengirim true jika Q kosong*/
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
void InitPelanggan (Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
  Head(*Q)=0;
  Tail(*Q)=0;

}

/* *** Primitif Add/Delete *** */
void Datang (Queue * Q, Pelanggan X)
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

void Pergi (Queue * Q, Pelanggan * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
  if(IsEmpty(*Q)) {
    printf("Antrian kosong\n");
  }
  else if(!IsFull(*Q)) {
    SalinPelanggan(X,InfoTail(*Q));
    Head(*Q)++;
    if(Head(*Q)>MaxEl)  {
      Head(*Q)= 1;
    }
  }

}

void KurangiKesabaran (Queue *Q)
/* Proses: Mengurangi kesabaran pelanggan dalam antrian */
/* I.S. Q terdefinisi */
/* F.S. Setiap pelanggan (Q).sabar berkurang satu satuan */
{
  int i;
  if(!IsEmpty(*Q))  {
    i=Head(*Q);
    while(i != Tail(*Q))  {
      (*Q).T[i].sabar--;
      if(i=MaxEl) {
        i=1;
      }
      else
        i++;
    }
  }
}
