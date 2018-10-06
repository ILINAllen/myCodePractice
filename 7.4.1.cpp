#include<cstdio.h>
#include<algorithm>
int issushu(int n)
{
	int i;
	int ok=1;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==1){
			ok=0;
			break;
		}
	}
	if(ok)return 1;
	else return 0;
	
	
	
}



int issushuhuan(int*P,int n)
{int i;
int ok=1;
	for(i=0;i<n;i++)
	{
		if(issushu(P[i%(n-1)]+P[(i+1)%(n-1)])!=1)
		{ok=0;break;}
		
		
	}
	if(ok)
		return 1;
	else return 0;
	
	
	
}



int main()
{
	int n;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
{
	P[i]=i+1;
}
	
while(next_permutation(P,P+n))
{
	
	if(ifsushuhuan(P,n))
		for(i=0;i<n;i++)
			printf("%d",P[i]);
		printf("\n");
		
	
	
	
	
	
	
}
	
	




return 0;	
	
	
	
}

