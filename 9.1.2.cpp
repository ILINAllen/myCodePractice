#include <stdio.h>
#include<string.h>
int a[100][100];
int dist[100][100];

int d(int i,int j)
{
	
	if(dist[i][j]>=0)return dist[i][j];
	
	return dist[i][j]=a[i][j]+d(i+1,j)>?d(i+1,j+1);
	
	
	
	
	
	
}


int main()
{
	int j;
	memset(dist,-1,sizeof(dist));
	for(j=0;j<8;j++)
		scanf("%d",&a[3][j]);
	
	
	
	
	int max=d(0,0);
	printf("%d",max);
	
	
	
	return 0;
}