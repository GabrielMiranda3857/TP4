#include <stdlib.h>
#include <stdio.h>

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
 
    int i=0, aux, n = 1000;
    int *vetor;
    int numero;
    FILE *arquivo;
    arquivo = fopen("1Entrada_mil.txt","w");
    
    vetor = (int *)malloc(1000*sizeof(int));
    printf("iniciou...");
    while (!feof(arquivo)){
    
         fscanf(arquivo,"%d\n",&vetor[i]);
         if(i==0){
             printf("%d",vetor[i]);
         }
         i++;
    }
    Bubble_sort(vetor, n);
    printf("fim");

    free(vetor);
    fclose(arquivo);
    return 0;
 
}
