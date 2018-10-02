#include <stdio.h>
#include <string.h>
int a[3000];
int main()
{
	int s,n,i,j,c;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	a[0]=1;
	for(i=2;i<=n;i++)
	{
		c=0;
		for(j=0;j<3000;j++)
		{
			s=a[j]*i+c;
			a[j]=s%10;
			c=s/10;
			
			
			}				
		}
		
		for(i=3000-1;i>=0;i--)
			if(a[i])break;
		for(j=i;j>=0;j--)
		{printf("%d",a[j]);}
	printf("\n");
	
	
	return 0;
	
	}