#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int i;
	char p[10];
//	scanf("%d",&n);
	//printf("\n");
	//for(i=0;i<n;i++)
	//{
	//	scanf("%c",&p[i]);
		
//	}
	gets(p);
n=strlen(p);
	sort(p,p+n);
	while(next_permutation(p,p+n)){
		
		for(i=0;i<n;i++)
		{
			printf("%c",p[i]);
			
			
			
		}printf("\n");
		//puts(p);
		
	}
	
	return 0;
	
	
}