#include <string.h>
#include <stdio.h>
int a[100][100];

int main()
{
	int tot=1;
	int n,y,x;

	memset(a,0,sizeof(a));
	scanf("%d",&n);
	a[x=0][y=0]=tot;
	while(tot<n*n)
	{
		while(y+1<n&&!a[x][y+1]){a[x][++y]=++tot;}
		while(x+1<n&&!a[x+1][y]){a[++x][y]=++tot;}
		while(y-1>=0&&!a[x][y-1]){a[x][--y]=++tot;}
		while(x-1>=0&&!a[x-1][y]){a[--x][y]=++tot;}
		
		
		
		
		
		}
		for(x=0;x<n;x++)
		{for(y=0;y<n;y++)
				
	       printf("%d  ",a[x][y]);
	
					printf("\n");
		}
	}