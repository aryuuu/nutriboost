#ifndef pelanggan_H
#define pelanggan_H

#include "boolean.h"
#include "player.h"

#define MaxEl 10
#define Nil 0

typedef struct {
	int ruangan;
	int meja;
	int jumlah;
	int sabar;
  char makanan[50];
  boolean layan;
} Pelanggan;

typedef struct { Pelanggan T[MaxEl+1];   /* tabel penyimpan elemen */
                 int HEAD;  /* alamat penghapusan */
                 int TAIL;  /* alamat penambahan */
               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika P adalah Pelanggan, maka akses elemen : */
#define Ruangan(P) (P).ruangan
#define Meja(P) (P).meja
#define Jumlah(P) (P).jumlah
#define Sabar(P) (P).sabar
#define Makanan(P) (P).makanan
#define Layan(P) (P).layan
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define InfoQ(Q,i) (Q).T[i]

/* ********* Salin Pelanggan ********* */
void SalinPelanggan(Pelanggan *P1,Pelanggan P2);
/*Menyalin P2 ke P1*/

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

/* *** Kreator *** */
void InitPelanggan (Pelanggan *P);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */

void InitAntrian (Queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */

/* *** Primitif Add/Delete *** */
void Datang (Queue * Q, Pelanggan X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Pergi (Queue * Q, Pelanggan * X,int jumlah);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

void KurangiKesabaranPelanggan (Pelanggan *P);
/* Proses: Mengurangi kesabaran pelanggan */
/* I.S. P terdefinisi */
/* F.S. Kesabaran Pelanggan (P).sabar berkurang satu satuan */

void KurangiKesabaranAntrian (Queue *Q, Player *player);
/* Proses: Mengurangi kesabaran pelanggan dalam antrian */
/* I.S. Q terdefinisi */
/* F.S. Setiap pelanggan (Q).sabar berkurang satu satuan */

void GeneratePelanggan(Queue *Q);
/*Prosedur menambahkan pelanggan ke dalam secara acak antrian dengan kemungkinan kemunculan pelanggan sebesar 5% */

void PrintPelanggan(Queue Q);

#endif
