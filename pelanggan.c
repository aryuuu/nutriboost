#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelanggan.h"


void SalinPelanggan(Pelanggan *P1,Pelanggan P2)
{
  Ruangan(*P1) = Ruangan(P2);
  Meja(*P1)=Meja(P2);
  Jumlah(*P1) =   Jumlah(P2);
  Sabar(*P1) = Sabar(P2);
  strcpy(Makanan(*P1),Makanan(P2));
  Layan(*P1) = Layan(P2);
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
  if(Head(Q)==Nil && Tail(Q)==Nil) {
    return 0;
  }
  else if(Head(Q)<=Tail(Q)) {
    return(Tail(Q)-Head(Q)+1 );
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
void InitPelanggan (Pelanggan *P)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
  int random;

  Ruangan(*P)=0;
  Meja(*P)=0;

  random = rand() % 5;
  if(random<2)  {
    Jumlah(*P) = 2;
  }
  else  {
    Jumlah(*P) = 4;
  }

  Sabar(*P) = 30;
  if(random==1)  {
    strcpy(Makanan(*P),"Sadikin");
  }
  else if(random==2) {
    strcpy(Makanan(*P),"Crisbar");
  }
  else if(random==3) {
    strcpy(Makanan(*P),"Salman");
  }
  else {
    strcpy(Makanan(*P),"Ganyang");
  }

  Layan(*P) = false;
}

void InitAntrian(Queue * Q)
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
  else {
    SalinPelanggan(X,InfoHead(*Q));
    if(Head(*Q)==Tail(*Q))  {
      Head(*Q)=Nil;
      Tail(*Q)=Nil;
    }
    else  {
      Head(*Q)++;
      if(Head(*Q)>MaxEl)  {
        Head(*Q)= 1;
      }
    }
  }
}

void KurangiKesabaranPelanggan (Pelanggan *P)
/* Proses: Mengurangi kesabaran pelanggan */
/* I.S. P terdefinisi */
/* F.S. Kesabaran Pelanggan (P).sabar berkurang satu satuan */
{
  Sabar(*P)--;
}

void KurangiKesabaranAntrian (Queue *Q)
/* Proses: Mengurangi kesabaran pelanggan dalam antrian */
/* I.S. Q terdefinisi */
/* F.S. Setiap pelanggan (Q).sabar berkurang satu satuan */
{
  int i;
  Pelanggan P;
  boolean pergi; /*Mengecek dalam antrian apakah head pergi atau tidak sampai ditemukan head yang tidak pergi*/

    i=Head(*Q);
    while(i != Tail(*Q))  {
      KurangiKesabaranPelanggan (&(*Q).T[i]);
      printf("%d",i);
        if(i==MaxEl) {
          i=1;
        }
        else  {
          i++;
        }
      }
    KurangiKesabaranPelanggan(&InfoTail(*Q));

    pergi=true;
    while(!IsEmpty(*Q) && pergi)  {
      if(Sabar(InfoHead(*Q))==0)  {
        Pergi(Q,&P);
      }
      else  {
        pergi=false;
      }
    }
}
