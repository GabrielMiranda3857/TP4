/////////////////////////////////////////
// BubbleSort entrada com vetor 10.000//
///////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void Bubble_sort(int *vetor, int n){
  
  int i, j, aux;
  for( i = 0; i < (n+1); i++){
        for(j = i + 1; j < (n+1); j++){
            if(vetor[i]>vetor[j]){ //verificando se a posição (n+1)<n. 
                aux = vetor[i];  //passando o valor de n+1 para aux.
                vetor[i] = vetor[j]; // a posicao (n+1) = n. 
                vetor[j] = aux; // n = n+1.
            }
        }
   }
}
 
int main(){
 
    int i=0, aux, n = 10000;
    int *vetor;
    int numero;
    FILE *arquivo;
    arquivo = fopen("Entrada_DezMil.txt","r");
    
    vetor = (int *)malloc(n*sizeof(int));
    printf("iniciou...");
    while (!feof(arquivo)){
    
         fscanf(arquivo,"%d\n",&vetor[i]);
         if(i==0){
             printf("%d",vetor[i]);
         }
         i++;
    }
    clock_t Ticks[2];
    Ticks[0] = clock();
    Bubble_sort(vetor, n);
    printf("fim");
    Ticks[1] = clock();

   double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

   printf("ordenação concluida\n");
   printf("Tempo gasto: %g ms.", Tempo);
   getchar();
    free(vetor);
    fclose(arquivo);
    return 0;
 
}