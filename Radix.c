/////////////////////////////////////////
// RadixSort entrada com vetor 1.000////
///////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void radixsort(int *vet, int n) {
	int i, exp = 1, m = 0, bucket[n], temp[n];

	for(i = 0; i < n; i++) {
		if(vet[i] > m) {
			m = vet[i];
		}
	}

	while((m/exp) > 0) {
		for (i = 0; i < n; i++) {
			bucket[i] = 0;
		}
		for(i = 0; i < n; i++) {
			bucket[(vet[i] / exp) % 10]++;
		}
		for(i = 1; i < n; i++) {
			bucket[i] += bucket[i-1];
		}
		for(i = (n - 1); i >= 0; i--) {
			temp[--bucket[(vet[i] / exp) % 10]] = vet[i];
		}
		for(i = 0; i < n; i++) {
			vet[i] = temp[i];
		}
		exp *= 10;
	}
}

int main() {
	int n = 1000;
	int *vetor;
	FILE *arquivo;
    int i=0;
    arquivo = fopen("Entrada_Mil.txt","r");
	vetor = (int *)malloc(n*sizeof(int));
    while (!feof(arquivo)) {
      fscanf(arquivo,"%d\n", &vetor[i]);
      i++;
   }
   clock_t Ticks[2];
    Ticks[0] = clock();
	radixsort(vetor,n);
	Ticks[1] = clock();

   double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

   printf("ordenação concluida\n");
   printf("Tempo gasto: %g ms.", Tempo);
   getchar();

	fclose(arquivo);
	return(0);
}