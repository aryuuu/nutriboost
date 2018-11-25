#ifndef pelanggan_H
#define pelanggan_H

#include "boolean.h"
#include "player.h"
#include "ruangan.h"

#define MaxAntrian 10
#define Nil 0
#define MaxMeja 12

typedef struct {
	int ruangan;
	int meja;
	int jumlah;
	int sabar;
    char makanan[50];
  boolean layan;
} Pelanggan;

/* Representasi Queue dengan lokasi Head tetap di-1 */
typedef struct { Pelanggan T[MaxAntrian+1];   /* tabel penyimpan elemen */
                 int HEAD;  /* alamat penghapusan */
                 int TAIL;  /* alamat penambahan */
               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* Array untuk menyimpan pelanggan yang telah duduk di meja dalam suatu ruangan*/
typedef struct {
	Pelanggan Mp[MaxMeja+1];
	boolean Fill[MaxMeja+1];
} ArrayMejaPelanggan;

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

/* Jika M adalah ArrayMejaPelanggan */
/* r adalah no ruangan , i adalah no meja*/
#define ArrayMeja(M,r,i) (M).Mp[(r-1)*4+i]
#define FillArrayMeja(M,r,i) (M).Fill[(r-1)*4+i]

/* ********* Salin Pelanggan ********* */
void SalinPelanggan(Pelanggan *P1,Pelanggan P2);
/*Menyalin P2 ke P1*/

/* ********* Prototype ********* */
boolean IsEmptyPAntrian (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullAntrian (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxAntrian */

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
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
void Pergi (Queue * Q, Pelanggan * X,int jumlah);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD tetap dan elemen di belakangnya maju ;
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
/* Prosedur print pelanggan di antrian */

/* -------------------- Pelanggan di Meja --------------------- */
void InitArrayMejaPelanggan(ArrayMejaPelanggan *M);
/* Inisialisasi array untuk menyimpan pelanggan yang telah duduk */

void IsiArrayMejaPelanggan(ArrayMejaPelanggan *M,int noMeja,int noRuangan,Pelanggan P);
/* Mengisi array indeks ke-noMeja dengan Pelanggan P, set jadi fill*/

void PrintArrayMejaPelanggan(ArrayMejaPelanggan M);
/* Print array pelanggan yang duduk di meja */

void KurangiKesabaranArrayMejaPelanggan(ArrayMejaPelanggan *M, Player *player,Ruangan *R1,Ruangan *R2,Ruangan *R3);
/* Proses: Mengurangi kesabaran pelanggan dalam array pelanggan di meja */

char MejaInttoChar(int i);

#endif
