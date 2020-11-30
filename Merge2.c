/////////////////////////////////////////
// MergeSort entrada com vetor 10.000///
///////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int main() {
	int n = 10000;
	int *vetor;
	FILE *arquivo;
    int i=0;
    arquivo = fopen("Entrada_DezMil.txt","r");
	vetor = (int *)malloc(n*sizeof(int));
    while (!feof(arquivo)) {
      fscanf(arquivo,"%d\n", &vetor[i]);
      i++;
   }
   clock_t Ticks[2];
    Ticks[0] = clock();
	mergeSort(vetor, 0, n - 1);
  	Ticks[1] = clock();

   double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

   printf("ordenação concluida\n");
   printf("Tempo gasto: %g ms.", Tempo);
   getchar();

	fclose(arquivo);
	return(0);
}