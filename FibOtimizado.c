///////////////////////////////////////////////////
// Fibonacci Otimizado entrada com vetor 1.000////
/////////////////////////////////////////////////

#include <stdio.h>
#include <stdio.h>
#include <time.h>

int fib(int n){                                         
      if (n == 1) return 1;                   
      else                                    
        if (n == 2) return 1;                 
        else return fib(n - 1) + fib(n - 2);  
}                                         
   
int main(void){

     int n;
     FILE *arquivo;
     arquivo = fopen("Entrada_Mil.txt","r");

     clock_t Ticks[2];
     Ticks[0] = clock();

     while (!feof(arquivo)){
        fscanf(arquivo,"%d\n",&n);
        //printf("%d\n", fib(n));
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