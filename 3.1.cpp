#include<stdio.h>
#include <string.h>
int a[101];
int main()
{  int i,j,k,n;
	memset(a,0,101);
	
	scanf("%d%d",&k,&n);
	for(i=1;i<=n;i++)
	{
		
		for(j=1;j<=k;j++)
			
		if(j%i==0)
			a[j]=!a[j];
		
		
		}
	
	
	
	for(i=1;i<=k;i++)
		if(a[i]==1)
		printf("%d ",i);
	
	
	printf("\n");
	
	return 0;
	}