#include <stdio.h>
int filter[100][100],arr[100][100],ans[100][100];
int convolve(int,int,int);
void printResult(int,int,int);
void main()
{
	int m,n,s,x,y,maxi,maxj,max;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&arr[i][j]);
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	scanf("%d",&s);
	for(int i = 0; i < s; i++)
		for(int j = 0; j < s; j++)
			filter[i][j] = 1;
	for(int i = 0; i < s; i++)
	{	
		filter[0][i] = 1;
		filter[1][i] = 1;
	}
	for(int i = 0; i < s; i++)
	{
		filter[i][0] = 1;
		filter[i][1] = 1;
	}
	x = m-s+1;
	y = n-s+1;
	max = -1;
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
		{
			ans[i][j] = convolve(i,j,s);
			if(ans[i][j] > max)
			{
				max = ans[i][j];
				maxi = i;
				maxj = j;
			}
		}
	printResult(maxi,maxj,s);	
} 
int convolve(int m, int n, int s)
{
	int i,j,sum = 0;
	for(i = 0; i < s; i++)
		for(j = 0; j < s; j++)
			sum = sum + filter[i][j]*arr[m+i][n+j];
	return sum;
}
void printResult(int maxi, int maxj, int s)
{
	int i,j;
	for(i = 0; i < s; i++)
	{
		for(j = 0; j < s; j++)
				printf("%d ", arr[maxi + i][maxj + j]);
		printf("\n");
	}
}