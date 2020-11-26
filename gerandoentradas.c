#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
    FILE *entradas;
    int i;
    entradas = fopen("entradas.txt", "w");
    if(entradas == NULL)
  {
  printf("Erro na abertura do arquivo!");
  return 1;
  }
 
    for(i=100 ; i >= 1 ; i--) 
        fprintf(entradas,"%d\n",i, rand());
    fclose(entradas);
 
}