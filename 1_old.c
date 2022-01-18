#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define n 275

int main()
{
	long int unsigned y[n][n], x[n][n], z[n][n];
	clock_t st, en;
	for (long int i = 0; i < n; i++)
		for (long int j = 0; j < n; j++){
			x[i][j] = (rand() % 100);
			y[i][j] = (rand() % 100);
		}
	st = clock();
	for (long int i = 0; i < n; i++)
		for (long int j = 0; j < n; j++) {
			z[i][j] = 0;
			for (long int k = 0; k < n; k++)
				z[i][j] += (x[i][k] * y[k][j]);
		}
	en = clock();
	double total=(double)(en - st)/CLOCKS_PER_SEC;
	printf("\n%f\n", total);
}
