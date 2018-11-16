#ifndef RUANGAN_H
#define RUANGAN_H


#include "boolean.h"
#include <string.h>
#include "point.h"
#include "scanner.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int indeks; /* indeks baris, kolom */

typedef struct 
{
	char Nama;//nama benda
	int Kapasitas;//bisa diisi berapa pelanggan
	boolean Fill;//udah terisi apa belum

} Objek;

typedef struct {
	char Nama[50];//nama ruangannya
	Objek Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Ruangan;




/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */



/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]
#define NamaR(M) (M).Nama
#define Nama(O) (O).Nama
#define Kapasitas(O) (O).Kapasitas
#define Fill(O) (O).Fill

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (Ruangan R);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (Ruangan R);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (Ruangan R);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (Ruangan R);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (Ruangan R, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */



void CreateRuangan(Ruangan *R, char N[50], int NB, int NK);
//bikin ruangan baru yang isinya cuma lantai doang, namanya N, ukurannya NBxNK

void SetObjek(Ruangan *R, Objek O, indeks i, indeks j);
//penempatan objek di ruangan di indeks i,j

Objek CreateObjek(char N, int K, boolean F);
//mengembalikan sebuah objek dengan nilai-nilai parameter di atas

void CetakRuangan(Ruangan R);
//cetak ruangan

void BacaRuangan(Ruangan *R, char File[50]);
//membentuk ruangan baru dengan masukan dari file eksternal
//format dari file eksternal ini adalah
//[NamaRuangan] [PanjangRuangan] [LebarRuangan] [NamaObjek,Kapasitas,Fill] ... diakhiri titik
POINT FindObjek(Ruangan R, char Nama);
//mengembalikan POINT tempat objek bernama Nama berada di Ruangan R
//jika ternyata objek tersebut tidak ada mengembalikan POINT dengan 
//absis dan ordinat -999

boolean BisaGerak(Ruangan R, char P, int Arah);
//mengembalikan nilai true atau false 
//arah merupakan angka 1, 2, 3, atau 4 yang 
//secara berurut merupakan arah atas, kanan, bawah, dan kiri
//jika Objek bernama P pada Ruangan R bisa bergerak ke arah Arah
//BisaGerak mengembalikan nilai true dan false jika tidak


void GerakO(Ruangan *R, char P, int Arah);
//menggerakkan Objek bernama P di Ruangan R ke arah Arah
//dimana Arah merupakan bilangan 1, 2, 3, atau 4
//yang secara berurutan merupakan arah atas, kanan, bawah, dan kiri
//I.S gerak ke arah Arah sudah divalidasi sebelumnya
//jadi tinggal gerakin aja


void UsirPelanggan(Ruangan *R, char Meja);
//mengosongkan kursi pelanggan yang sudah selesai makan
//pada Ruangan R di meja bernama Meja
//meja yang ingin dikosongkan pasti terisi sebelum pelanggan diusir

void IsiMeja(Ruangan *R, char Meja, int Pelanggan);
//mengisi kursi kursi di meja bernama Meja pada Ruangan R
//jumlah kursi yang terisi adalah sejumlah Pelanggan
//meja yang ingin diisi pasti kosong, dan Pelanggan tidak
//melebihi kapasitas meja
//nilai Pelanggan pasti 2 atau 4

char MejaTerdekat(Ruangan R);
//mengembalikan nama meja terdekat dengan Player
//player pasti sedang berada di dekat meja yang terisi 
//player tidak sedang berada di dekat dinding



#endif