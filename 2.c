#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define m 100
#define n 200

void main()
{
    int arr2[m], sum = 0;
    printf("The number of section: %d\n", m);
    printf("The number of items: %d\n", n);
    int arr[m][n], i, j;
    for (i = 0; i < m; i++)
    {
        for(j=0;j<n;j++)
        {
            arr[i][j] = rand() % 100 + 9;
        }
    }
    printf("printing the elements\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Entered a[%d][%d]: %d\t",i,j,arr[i][j]);
        }
        printf("\n");
    }
    double startp = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i < m; i++)
    {
        arr2[i] = 0;
        for (int j = 0; j < n; j++)
        {
            arr2[i] += arr[i][j];
        }
    }
#pragma omp single
    {
        for (int i = 0; i < m; i++)
        {
            sum += arr2[i];
        }
    }
    double endp = omp_get_wtime();
    sum = 0;
    double start = clock();
    for (int i = 0; i < m; i++)
    {
        arr2[i] = 0;
        for (int j = 0; j < n; j++)
        {
            arr2[i] += arr[i][j];
        }
    }
    {
        for (int i = 0; i < m; i++)
        {
            sum += arr2[i];
        }
    }
    double end = clock();
    double elapsed = end - start;
    double elapsedp = endp - startp;
    printf("Time taken: %f\n", elapsed/CLOCKS_PER_SEC*100000);
    printf("Time taken: %f\n", elapsedp*1000);
    for(i=0;i<m;i++)
    {
        printf("Sum of arr2[%d]: %d\n",i,arr2[i]);
    }
    printf("Total sum: %d\n",sum);
}
