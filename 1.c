// consider a scenario a person visits a supermart for shopping, he purchases various items such as
// clothing,gaming,stationary. WAP to process his bill parellely in each sec. display the bill ie sum of 
// elements parallely.
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>


int main()
{
	//long int unsigned y[n][n], x[n][n], z[n][n];
	int n = 100;
	while (n <= 1000) {
		int **x, **y, **z;
		x = (int**)malloc(n * sizeof(int));
		y = (int**)malloc(n * sizeof(int));
		z = (int**)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++) {
			x[i] = (int*)malloc(n * sizeof(int));
			y[i] = (int*)malloc(n * sizeof(int));
			z[i] = (int*)malloc(n * sizeof(int));
		}
		clock_t st, en;
		for (long int i = 0; i < n; i++)
			for (long int j = 0; j < n; j++) {
				x[i][j] = (rand() % 100);
				y[i][j] = (rand() % 100);
			}
		omp_set_num_threads(2);
		st = clock();
		#pragma omp parallel for
		{
			for (long int i = 0; i < n; i++)
				for (long int j = 0; j < n; j++) {
					z[i][j] = 0;
					for (long int k = 0; k < n; k++)
						z[i][j] += (x[i][k] * y[k][j]);
				}
		}
		en = clock();
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d\t", z[i][j]);
			}
			printf("\n");
		}*/
		free(x);
		free(y);
		free(z);
		double total = (double)(en - st) / CLOCKS_PER_SEC;
		printf("\n%d-->%f\n",n, total);
		n+=200;
	}
}
