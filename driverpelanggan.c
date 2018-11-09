#include "pelanggan.c"
#include "pelanggan.h"
#include <stdio.h>
#include <stdlib.h>

int main()  {
  int input,X,i,j;
  Queue Q;
  Pelanggan P;
  InitAntrian(&Q);
  do {
    printf("Input 0: Keluar.\n");
    printf("Input 1: Datang.\n");
    printf("Input 2: Pergi.\n");
    printf("Input 3: Jumlah.\n");
    printf("Input 4: KurangiKesabaran.\n");
    printf("Masukkan input:\n");
    scanf("%d",&input);


    if(input==1)  {
      InitPelanggan(&P);
      Datang(&Q,P);
      printf("Makanan : %s\n",Makanan(P));
    }
    else if (input==2) {
      Pergi(&Q,&P);
      printf("%s\n",Makanan(P));
    }
    else if(input==3) {
      printf("Head : %d\n",Head(Q));
      printf("Tail : %d\n",Tail(Q));
      printf("Jumlah elemen : %d\n",NBElmt(Q));
      if(!IsEmpty(Q))  {
        i=Head(Q);
        j=1;
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        while(i != Tail(Q))  {
          printf("Jumlah %d: %d\n",j,Jumlah(Q.T[i]));
          printf("Makanan %d: %s\n",j,Makanan(Q.T[i]));
          printf("Kesabaran %d: %d\n\n",j,Sabar(Q.T[i]));
          j++;
          if(i==MaxEl) {
            i=1;
          }
          else
            i++;
        }
        printf("Jumlah %d: %d\n",j,Jumlah(Q.T[i]));
        printf("Makanan %d: %s\n",j,Makanan(Q.T[i]));
        printf("Kesabaran %d: %d\n\n",j,Sabar(Q.T[i]));
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
      }
    }
    else if (input==4) {
      KurangiKesabaranAntrian(&Q);
    }

  } while(input !=0);

  return 0;
}
