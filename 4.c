#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
#include<time.h>
void main(){
double array_t[1000];
	for(int n=10;n<1000;n+=50){	
	/*printf("Enter the numbers to be printed: \n");
	scanf("%d",&n);*/
	int arr[2+n],i;
	double now = omp_get_wtime();
	#pragma omp parallel 
	{
		#pragma omp single
		{
			for(i=0;i<n+2;i++){
				if(i==0 || i==1)
					arr[i]=i;
				else
					arr[i]=arr[i-1]+arr[i-2];
			}
		}
		#pragma omp single
		{
			for(i=0;i<n+2;i++)
				printf("%d\t",arr[i]);
		}
	}
	double end = omp_get_wtime();
	printf("%.8f\n",(end-now));
	array_t[n]=(end-now);}
	for(int n=10;n<1000;n+=50)
		printf("%d\t%.8f\n",n,array_t[n]);
}
