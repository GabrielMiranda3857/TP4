#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int fib(int n){

  int i, fib1 = 1, fib2 = 1, soma;         
  for (i = 3; i <= n; i = i + 1){

    soma = fib1 + fib2;                    
    fib1 = fib2;                           
    fib2 = soma;  

  }                                        
     return fib2;                             
}                                          
   
   
 int main(void){
     int n;
     FILE *arquivo;
     arquivo = fopen("1Entrada_10mil.txt","r");

     clock_t Ticks[2];
     Ticks[0] = clock();

     while (!feof(arquivo))
     {
        fscanf(arquivo,"%d\n",&n);
        printf("%d\n", fib(n));
     }

    printf("fim");
    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    printf("ordenação concluida\n");
    printf("Tempo gasto: %g ms.", Tempo);
    getchar();

    fclose(arquivo);
    return 0; 

}