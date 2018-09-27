#include <stdio.h>
 #include<stdlib.h>
 #include<time.h>
 int n=100,m=10000;
 
 double random()
 {
	 
	 return (double)rand()/RAND_MAX;
	 
	 }
	 int random(int m)
	 {
		 return (int )(random()*(m-1)+0.5);
		 
		 }
int main()
{
	srand(time(NULL));
	printf("%d %d\n",n,m); 
	int x,y,i;
	for(i=0;i<m;i++)
	{
		if(rand()%2==0)printf("A");
			else printf("B");
	
	for( ; ; )
	{
		x=random(n)+1;
		y=random(n)+1;
		
		if(x!=y)break;
		
		
		
		}
		printf("%d %d\n",x,y);
	
	}
	return 0;
	
	}
	