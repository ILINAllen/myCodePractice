#include <cstdio>
int A[5]={1,2,3,4,5};
void printf_subset(int n,int s)
{ int i;
	for(i=0;i<n;i++)
		if(s&(1<<i))printf("%d",A[i]);
	printf("\n");
	
	
	
}


int main()
{
	int i;
	int n=5;
	for(i=0;i<(1<<n);i++)
	{
		//if(i&(1<<2))printf("%d",i);
		printf_subset(n,i);
	}
	return 0;
	
	
	
	
}