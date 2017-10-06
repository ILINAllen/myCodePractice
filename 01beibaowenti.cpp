#include <iostream>
#include <stdio.h>

using namespace std;
int d[100][100]={0};
int w[100]={0};
int v[100]={0};
int x[100]={0};
void traceback(int c,int value,int n,int begin)
{
	if(value==0&&c>=0)
	{
		for(int i=1;i<=n;i++)
			if(x[i])cout<<i<<" ";
			cout<<endl;
		return ;
	}
	for(int i=begin;i<=n;i++)
	{
		if(c-w[i]>=0&&value-v[i]>=0)
		{
			x[i]=1;
			traceback(c-w[i],value-v[i],n,i+1);
			x[i]=0;
		}
	}
}

int main()
{
	freopen("01beibaowenti.in", "r", stdin);
	int c;
	while(cin>>c)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b;
			cin>>a>>b;
			w[i]=a;
			v[i]=b;
		}
		for(int j=1;j<=c;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(w[i]<=j)
				{				
					int temp=d[i-1][j-w[i]]+v[i];
					if(d[i-1][j]<temp) //是拿表格里上一行的值与当前计算值比较，而不是d[i][j]<temp，当前值为0，如论怎么样都会被通过
					 {d[i][j]=temp;
					}
					else 
						d[i][j]= d[i-1][j];			
				}
				else
				{
					d[i][j]=d[i-1][j];
				}
			}
		}
		//memset(d,0,sizeof(d));
		for(int i=0;i<=n;i++)
		{
			for(int j=1;j<=c;j++)
			{
				cout<<d[i][j]<<" ";
			}
			cout<<endl;
		}
		traceback(c, d[n][c], n, 0);
	}
	return 0;
}