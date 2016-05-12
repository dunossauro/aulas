#include <stdio.h>
#include <stdlib.h>

// --------------- Função inicializadora de recursão
int quicksort(int*a, int len){
    quicksort_r(a, 0, len-1);
    return 0;
}

// --------------- SwapSort Recursivo
int quicksort_r(int* a,int start,int end){
   // --------------- Validação da entrada
    if (start>=end) {
        return 0;
    }
    int pivot=a[end];
    int swp;
    int pointer=start;
    int i;

    // --------------- Trocas de posições
    for (i=start; i<end; i++) {
        if (a[i]<pivot) {
            if (pointer!=i) {
                swp=a[i];
                a[i]=a[pointer];
                a[pointer]=swp;
            }
            pointer++;
        }
    }
    // --------------- Reordenação dos valores de troca
    swp=a[end];
    a[end]=a[pointer];
    a[pointer]=swp;
    // --------------- Recurção
    quicksort_r(a,start,pointer-1);
    quicksort_r(a,pointer+1,end);
    return 0;
}

int main(){
    int x;
    int i;
    char opt;
    printf("%s\n", "Digite o tamanho do vetor");
    scanf("%d", &x);

    int a[x];
    int len=x;

    for (size_t i = 0; i < len; i++) {
      printf("%s %d\n", "Digite a posição", i);
      scanf("%d", &a[i]);
    }


   do {
      printf("%s", "Deseja executar busca binária? [S|N]");
      scanf("%c", &opt);

      if (opt == 'N') {
         /* Bin s. */
      } else {
         /* Sort s. */
      }

   } while( !(opt == 'S') || !(opt == 'N'));

    system("clear");
    // --------------- Saida do Vetor
    printf("Vetor inicial = [");
    for (i=0; i<len; i++) {
      if (i < len-1) {
         printf("%d, ",a[i]);
      }else {
         printf("%d",a[i]);
      }
    }
    printf("]\n");

    quicksort(a,len);

    // --------------- Saida do Sort
    printf("Saida ordenada = [");

    for (i=0; i<len; i++) {
      if (i < len-1) {
         printf("%d, ",a[i]);
      }else {
         printf("%d",a[i]);
      }
    }

    printf("]\n");

    return 0;
}
