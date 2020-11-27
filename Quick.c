#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Quick(int vetor[1000], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   

}
int main(){
   
   int n = 1000, i=0;
   int *vetor;
   FILE *arquivo;
   arquivo = fopen("1Entrada_10mil.txt","r");
   vetor = (int *)malloc(n*sizeof(int));
   
   while (!feof(arquivo)){
         fscanf(arquivo,"%d\n", &vetor[i]);
         if(i==0){
            printf("lendo o arquivo;");
         }
         i++;
   }
   clock_t Ticks[2];
    Ticks[0] = clock();
    
   printf("comecando a ordenação\n");
   Quick(vetor, 0, n);
   
   Ticks[1] = clock();

   double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

   printf("ordenação concluida\n");
   printf("Tempo gasto: %g ms.", Tempo);
   getchar();

   fclose(arquivo);
   
   return 0;
}

