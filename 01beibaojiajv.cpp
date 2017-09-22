#include<stdio.h>
int v[70];
int p[70];
int q[70];
int d[50000];
int max(int a,int b)
{   return a > b ? a : b;   }
int main()
{freopen("jiajvbeibao.in","r",stdin);
int n,m;
int i,j,k;
int t1,t2;
int k1,k2;
int l=0;
scanf("%d%d",&n,&m);
for(i = 1; i <= m; i++)
{
	scanf("%d%d%d",&v[i],&p[i],&q[i]);
}
for(i = 1; i <= m; i++)
{
	k1=0;
	k2=0;
	t1=0;
	t2=0;
	if(q[i]==0)  //要是主物件
	{
		for(k = i+1;k <= m; k++)
			if(q[k]==i)                       //找到附属物品1
			{
				t1=k;
				k1=1;
				break;
			}
			for(k = t1+1;k <= m; k++)
				if(q[k]==i)                       //找到附属物品2
				{
					t2=k;
					k2=1;
					break;
				} 
				for(j = n; j >= v[i]; j--)
				{		
					//f[j]=max(f[j-v[i]]+v[i]*p[i],f[j]);

					d[j]=max(d[j-v[i]]+v[i]*p[i],d[j]);   //只要主件或者都不要
					if((j-v[i]-v[t1])>=0&&k1==1)                         //要附件1

						d[j]=max(d[j-v[i]-v[t1]]+v[i]*p[i]+v[t1]*p[t1],d[j]);
					if((j-v[i]-v[t2])>=0&&k2==1)                                           //要附件2

						d[j]=max(d[j-v[i]-v[t2]]+v[i]*p[i]+v[t2]*p[t2],d[j]);
					if((j-v[i]-v[t1]-v[t2])>=0&&k1==1&&k2==1)                                           
						d[j]=max(d[j-v[i]-v[t1]-v[t2]]+v[i]*p[i]+v[t1]*p[t1]+v[t2]*p[t2],d[j]);			
				}
	}
}
printf("%d\n",d[n]);


return 0;
}


