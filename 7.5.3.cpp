#include <stdio.h>
#include <string.h>
typedef int status[9];
status st[1000],goal;

int ans;
int dist[1000];
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int vis[36288],fact[9];

void lookup_table()
{
	fact[0]=1;
	for(int i=0;i<9;i++)
		fact[i]=fact[i-1]*i;
}

int  try_insert(int s)
{
	
	int code=0;
	int i;
	for(i=0;i<9;i++)
	{
		int cnt=0;
		for(int j=i+1;j<9;j++)
			if(st[s][j]<st[s][i])cnt++;
		code+=fact[8-i]*cnt;	
	}
	if(vis[code])return 0;
	return vis[code]=1;
}

int bfs()
{
	lookup_table();
	int front=1,rear=2;
	while(front<rear)
	{
	status&	s=st[front];
		if(memcmp(s,goal,sizeof(goal))==0)return ans;
		int z;
		for(z=0;z<9;z++)
			if(!s[z])break;
		int x=z/3;
		int y=z%3;	
		for(int i=0;i<4;i++)
		{
			
		int newx=x+dx[i];
		int newy=y+dy[i];
		int newz=newx*3+newy;
		if(newx<3&&newx>=0&&newy<3&&newy>=0)
		{
			status& t=st[rear];
			memcpy(&t,&s,sizeof(s));
			t[newz]=s[z];
			t[z]=s[newz];
			
			dist[rear]=dist[front]+1;
			if(try_insert(rear))rear++;			
		}
		}
		front++;	
	}
	return 0;
}

int main()
{  int i;
	for( i=0;i<9;i++)
	scanf("%d",&st[1][i]);

for(i=0;i<9;i++)
	scanf("%d",&goal[i]);
   int ans=bfs();
  if(ans>0)printf("%d\n",dist[ans]);
  else printf("-1\n");
	
}