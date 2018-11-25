#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelanggan.h"
#include "player.h"


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
  else  {
    return(Tail(Q));
  }
}

/* ********* Prototype ********* */
boolean IsEmptyAntrian (Queue Q)
/* Mengirim true jika Q kosong*/
{
  return((Head(Q) == Nil)&&(Tail(Q)==Nil));
}

boolean IsFullAntrian (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxAntrian */
{
    return(NBElmt(Q) == MaxAntrian);
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
  if(random<=2)  {
    Jumlah(*P) = 2;
  }
  else  {
    Jumlah(*P) = 4;
  }

  Sabar(*P) = 30;
  random = rand() % 8;

  if(random==0)  {
    strcpy(Makanan(*P),"Banana Split");
  }
  else if(random==1) {
    strcpy(Makanan(*P),"Sundae");
  }
  else if(random==2) {
    strcpy(Makanan(*P),"Nasi Telur Dadar");
  }
  else if (random==3) {
    strcpy(Makanan(*P),"Nasi Ayam Goreng");
  }
  else if (random==4) {
    strcpy(Makanan(*P),"Burger");
  }
  else if (random==5) {
    strcpy(Makanan(*P),"Hot Dog");
  }
  else if (random==6) {
    strcpy(Makanan(*P),"Spaghetti Bolognese");
  }
  else if (random==7) {
    strcpy(Makanan(*P),"Spaghetti Carbonara");
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
  if(IsEmptyAntrian(*Q)) {
    Head(*Q)=1;
    Tail(*Q)=1;
    SalinPelanggan(&InfoTail(*Q),X);
  }
  else if(!IsFullAntrian(*Q)) {
    Tail(*Q)++;
    SalinPelanggan(&InfoTail(*Q),X);
  }
}

void Pergi (Queue * Q, Pelanggan * X,int jumlah)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
  boolean Found;
  int i;
  if(IsEmptyAntrian(*Q)) {
    printf("Antrian kosong\n");
  }
  else {
    Found = false;
    i = Head(*Q);
    while(!Found && i <= Tail(*Q)) {
      if(Jumlah(InfoQ(*Q,i))<=jumlah) {
        Found = true;
      }
      else{
        i=i+1;
      }
    }
    if(Found) {
      SalinPelanggan(X,InfoQ(*Q,i));
      if(Head(*Q)==Tail(*Q))  {
        Head(*Q)=Nil;
        Tail(*Q)=Nil;
      }
      else{
        while(i < Tail(*Q))  {
          SalinPelanggan(&InfoQ(*Q,i),InfoQ(*Q,i+1));
          i=i+1;
        }
        Tail(*Q)=Tail(*Q)-1;
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

void KurangiKesabaranAntrian (Queue *Q, Player *player)
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
      i=i+1;
    }
    KurangiKesabaranPelanggan(&InfoTail(*Q));

    pergi=true;
    while(!IsEmptyAntrian(*Q) && pergi)  {
      if(Sabar(InfoHead(*Q))==0)  {
        SalinPelanggan(&P,InfoHead(*Q));
        if(Head(*Q)==Tail(*Q))  {
          Head(*Q)=Nil;
          Tail(*Q)=Nil;
        }
        else{
          while(i != Tail(*Q))  {
            SalinPelanggan(&InfoQ(*Q,i),InfoQ(*Q,i+1));
          }
          Tail(*Q)=Tail(*Q)=-1;
        }
        Life(*player)--;
      }
      else  {
        pergi=false;
      }
    }
}

void GeneratePelanggan(Queue *Q)
/*Prosedur menambahkan pelanggan ke dalam secara acak antrian dengan kemungkinan kemunculan pelanggan sebesar 5% */
{
  Pelanggan P;
  int random = rand() % 5;
  if (random == 3)  {
    InitPelanggan(&P);
    Datang(Q,P);
  }
}

void PrintPelanggan(Queue Q) {
  printf("Jumlah pelanggan : %d\n",NBElmt(Q));
  if(!IsEmptyAntrian(Q))  {
    int i=Head(Q);
    int j=1;
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    while(i != Tail(Q))  {
      printf("Jumlah %d: %d\n",j,Jumlah(Q.T[i]));
      printf("Kesabaran : %d\n\n",Sabar(Q.T[i]));
      j++;
      if(i==MaxAntrian) {
        i=1;
      }
      else
        i++;
    }
    printf("Pelanggan %d: %d\n",j,Jumlah(Q.T[i]));
    printf("Kesabaran : %d\n\n",Sabar(Q.T[i]));
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  }
}

/* -------------------- Pelanggan di Meja --------------------- */
void InitArrayMejaPelanggan(ArrayMejaPelanggan *M)
/* Inisialisasi array untuk menyimpan pelanggan yang telah duduk */
{
  int r=1;
  int i=1;
  while(r<=3){
    while(i<=4) {
      FillArrayMeja(*M,r,i) = false;
      i=i+1;
    }
    r=r+1;
  }
}

void IsiArrayMejaPelanggan(ArrayMejaPelanggan *M,int noMeja,int noRuangan,Pelanggan P)
/* Mengisi array indeks ke-noMeja dengan Pelanggan P*/
{
  int indeks;
  SalinPelanggan(&ArrayMeja(*M,noRuangan,noMeja),P);
  FillArrayMeja(*M,noRuangan,noMeja)=true;
  Sabar(ArrayMeja(*M,noRuangan,noMeja))=3;
}

void PrintArrayMejaPelanggan(ArrayMejaPelanggan M)
/* Print array pelanggan yang duduk di meja */
{
  int r=1;
  while(r<=3){
    int i=1;
    while(i<=4) {
      if(FillArrayMeja(M,r,i))  {
        printf("Pelanggan Ruangan-%d Meja-%d : \n",r,i);
        printf("  >Jumlah =%d\n",Jumlah(ArrayMeja(M,r,i)));
        printf("  >Kesabaran =%d\n",Sabar(ArrayMeja(M,r,i)));
      }
      else  {
        printf("Pelanggan Ruangan-%d Meja-%d : kosong\n",r,i);
      }
      i=i+1;
    }
    r=r+1;
  }

}

void KurangiKesabaranArrayMejaPelanggan (ArrayMejaPelanggan *M, Player *player,Ruangan *R1,Ruangan *R2,Ruangan *R3)
/* Proses: Mengurangi kesabaran pelanggan dalam array pelanggan di meja */
{
	int i,r;
  r=1;
  while(r<=3){
    i=1;
    while(i<=4) {
      if(FillArrayMeja(*M,r,i))  {
        KurangiKesabaranPelanggan(&ArrayMeja(*M,r,i));
        if(Sabar(ArrayMeja(*M,r,i))==0)  {

          Life(*player)--;
          FillArrayMeja(*M,r,i)=false;
          if(r==1)  {
            UsirPelanggan(R1,MejaInttoChar(i));
          }
          else if(r==2)  {
            UsirPelanggan(R2,MejaInttoChar(i));
          }
          else if(r==3)  {
            UsirPelanggan(R3,MejaInttoChar(i));
          }

        }

      }
      i=i+1;
    }
    r=r+1;
  }
}

char MejaInttoChar(int i) {
  if(i==1)  {
    return '1';
  }
  else if(i==2)  {
    return '2';
  }
  else if(i==3)  {
    return '3';
  }
  else if(i==4)  {
    return '4';
  }
}
