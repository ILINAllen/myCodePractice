#include<stdio.h>
#include <queue>
using namespace std;
int main()
{
	queue<int> q;
	
	int i,n;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		q.push(i+1);
		
		}
	while(!q.empty())
	{
		printf("%d ",q.front());
		q.pop();
		q.push(q.front());
		q.pop();
		
		
		}
	
	
	
	return 0;
	}