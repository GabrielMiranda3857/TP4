#include <stdlib.h>
#include <stdio.h>
 
void imprime_vetor(int *v, int n){
    for (int i = 0; i < n; i++)
    {
        printf("[%d]",v[i]);
    }
    
}
 
void Bubble_sort(int *vetor, int n){
  
  int i, j, aux;
  for( i = 0; i < (n+1); i++){
        for(j = i + 1; j < (n+1); j++){
            imprime_vetor(vetor, n);
            printf("\n");
            if(vetor[i]>vetor[j]){ //verificando se a posição (n+1)<n. 
                                   
                aux = vetor[i];  //passando o valor de n+1 para aux.
                vetor[i] = vetor[j]; // a posicao (n+1) = n. 
                vetor[j] = aux; // n = n+1.
            }
        }
   }
}
 
int main(){
 
    int i, j, aux, n = 7;
    int vetor[] = {7, 4, 6, 5, 3, 1, 2};
    Bubble_sort(vetor, n);
 
}
