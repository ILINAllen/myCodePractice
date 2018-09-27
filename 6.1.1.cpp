#include <stdio.h>
int queue[100];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		queue[i]=i+1;
		
		
		}
		int front=0;
		int rear=n;
		while(front<rear)
		{
			printf("%d ",queue[front++]);
			queue[rear++]=queue[front++];
			
			
			
			
			}
	
	
	}