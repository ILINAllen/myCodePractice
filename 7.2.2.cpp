#include<stdio.h>
int P[3]={9,5,1};
int A[10];
void permutation(int n,int *P,int *A,int cur)
{
	int i,c1,c2,j;
	if (cur==n)
	{for(i=0;i<n;i++)
		printf("%d",A[i]);
		printf("\n");
		
	}
	else
		for(i=0;i<n;i++)
			if(!i||P[i]!=P[i-1])
		{
			c1=c2=0;
			for(j=0;j<cur;j++)
			{
				if(A[j]==P[i])c1++;
				
			}
			for(j=0;j<n;j++)
			{
				if(P[j]==P[i])c2++;
				
			}
			if(c1<c2)
			{
				A[cur]=P[i];
				permutation(n,P,A,cur+1);
				
				
			}
			
		}
	
	
	
	
	
}





int main()
{int n;
	scanf("%d",&n);
	
	
	
	permutation(n,P,A,0);
	
	
	
	
	
}