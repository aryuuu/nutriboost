#include "player.h"
#include "bintree.h"
#include <string.h>
#include <stdio.h>

void InitPlayer(Player *P, char nama[50]) {
	strcpy(Name(*P), nama);
	Money(*P) = 0;
	Life(*P) = 2; 
	Time(*P) = MakeJAM(0,0,0);
	Posisi(*P) = MakePOINT(1,1);
	Ruangan(*P)  = 1;
}

void PrintState(Player P) {
	printf("Name : %s | Money : %d | Life : %d | Time : ", Name(P), Money(P), Life(P));
	TulisJAM(Time(P));printf("\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void Gerak(Player *P, char opsi[50]) {
/* I.S Posisi Player terdefinisi */
/* F.S Posisi berubah sesuai kemauan : GU keatas, GD kebawah, GL kekiri, GR kekanan */
	if (strcmp(opsi, "GU") == 0) {
		Geser(&Posisi(*P), 0, 1);
	}
	else if (strcmp(opsi, "GD") == 0) {
		Geser(&Posisi(*P), 0, -1);
	}
	else if (strcmp(opsi, "GL") == 0) {
		Geser(&Posisi(*P), -1, 0);
	}
	else if (strcmp(opsi, "GR") == 0) {
		Geser(&Posisi(*P), 1, 0);
	}
}

void IsiTangan(Player *P, char Makanan) {
	if (!TanganPenuh(*P)) {
		TOPTangan(Tangan(*P))++;
		InfoTOPTangan(Tangan(*P)) = Makanan;
	}
}

void KosongTangan(Player *P) {
	TOPTangan(Tangan(*P)) = Nil;
}

void KeluarkanMakanan(Player *P, char *Makanan) {
	if (TOPTangan(Tangan(*P)) != Nil) {
		*Makanan = InfoTOPTangan(Tangan(*P));
		TOPTangan(Tangan(*P))--;
	}
}

boolean TanganPenuh (Player P) {
	return TOPTangan(Tangan(P)) == MaxEl;
}

void CetakTangan(Player P) {
	Player temp;
	KosongTangan(&temp);
	char X;
	char Makanan[50];

	if (TOPTangan(Tangan(P)) != Nil) {
		printf("Tangan : \n");
		while (TOPTangan(Tangan(P)) != Nil) {
			KeluarkanMakanan(&P, &X);
			IsiTangan(&temp, X);
		}
	
		while (TOPTangan(Tangan(temp)) != Nil) {
			KeluarkanMakanan(&temp, &X);
			KodeMakanan(X, Makanan);
			printf("%s\n", Makanan);
		}
		printf("++++++++++++++++++++++++++++++++++++\n");
	}
}

Hand BalikTangan(Player P) {
	Player Ptemp;
	KosongTangan(&Ptemp);
	char X;

	if (TOPTangan(Tangan(P)) != Nil) {
		while (TOPTangan(Tangan(P)) != Nil) {
			KeluarkanMakanan(&P,&X);
			IsiTangan(&Ptemp, X);
		}
	}
	return Tangan(Ptemp);
}

void BuatMakanan(Player *P, BinTree Resep) {
	Hand HAwal = Tangan(*P);
	Hand H = BalikTangan(*P);
	Tangan(*P) = H;

	boolean Bisa = true;
	char MakanHand;

	if (TOPTangan(Tangan(*P)) == Nil) {
		Tangan(*P) = HAwal; 
	}
	else {
		KeluarkanMakanan(P, &MakanHand);
		if (Akar(Resep) == MakanHand) {
			if (TOPTangan(Tangan(*P)) != Nil) {
				KeluarkanMakanan(P, &MakanHand);
				while (Bisa && TOPTangan(Tangan(*P)) != Nil) {
					if (Akar(Left(Resep)) == MakanHand) {
						Resep = Left(Resep);
						KeluarkanMakanan(P, &MakanHand);
					}
					else if (Akar(Right(Resep)) == MakanHand) {
						Resep = Right(Resep);
						KeluarkanMakanan(P, &MakanHand);
					}
					else {
						Bisa = false;
					}
				}
				if (Bisa && IsMakananJadi(Akar(Left(Left(Resep))))) {
					KosongTangan(P);
					IsiTangan(P, Akar(Left(Left(Resep))));
				}
				else {
					Tangan(*P) = HAwal;
				}
			}
			else {
				Tangan(*P) = HAwal;
			}
		}
		else {
			Tangan(*P) = HAwal;
		}
	}
}

boolean IsMakananJadi(char CC) {
	return (CC == 'l'|| CC == 'u'|| CC == 'd' || CC == 'G' || CC == 'R' || CC == 'H'|| CC == 'A' || CC == 'T');
}

