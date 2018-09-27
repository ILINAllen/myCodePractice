#include <stdio.h>
#include <string.h>
int vis[100][100];
int mat[100][100];
char s[100];
void dfs(int i,int j)
{
	if(mat[i][j]==0||vis[i][j]==1)return ;
		vis[i][j]=1;
	dfs(i-1,j-1);dfs(i-1,j);dfs(i-1,j+1);
	dfs(i,j-1);                  dfs(i,j+1);
	dfs(i+1,j-1);dfs(i+1,j);dfs(i+1,j+1);
	
	}




int main()
{  int count=0,i,j,n;
	freopen("6.4.1.in","r",stdin);
	memset(vis,0,sizeof(vis));
	memset(mat,0,sizeof(mat));
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{ scanf("%s",s);
	for(j=0;j<n;j++)
	{				
		mat[i+1][j+1]=s[j]-'0';					
		}
	
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)    
		{
			
		 	
			if(mat[i][j]==1&&vis[i][j]==0)
			{
				count++;
				dfs(i,j);
				}
			
			
			
			}
		
		
		
		
		
		}
		printf("%d",count);
		
		
		
		
		
		
		
	
	
	
	
	}