#include <cstdio>
int A[5]={1,2,3,4,5};
int B[10];
using namespace std;
void permutation(int n,int *A,int * B,int cur)
{
	int i;
	if(n==cur)
	{
		for(i=0;i<n;i++)
		{
			if(B[i])printf("%d",A[i]);
			
		}
		printf("\n");
		return ;
	}
	
	B[cur]=1;
    permutation(n,A,B,cur+1);
	B[cur]=0;
	permutation(n,A,B,cur+1);
	
	
	
	
	
}



int main()
{
	
	
	
	permutation(5,A,B,0);
	
	
	
	return 0;
	
}