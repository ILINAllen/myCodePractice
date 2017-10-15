#include<stdio.h>
#include<ctype.h>
#include<string.h>
char s[1000];
int p[1000];
char buf[1000];
int main()
{
	int max=0;
	int x,y;
	int m=0;
	int i,j;
	freopen("3.4.in","r",stdin);
	freopen("3.4.out","w",stdout);
	
	fgets(buf,sizeof(buf),stdin);
	int n=strlen(buf);
	for(i=0;i<n;i++)
	{
		if(isalpha(buf[i]))
		{
			p[m]=i;
			s[m++]=toupper(buf[i]);
			
			
			}
		
		
		}
		
		for(i=0;i<m;i++)
		{
			
			for(j=0;i-j>=0&&i+j<m;j++)
			{
				if(s[i-j]!=s[i+j])break;
				if(2*j+1>max){max=2*j+1; x=i-j;y=i+j;}
								}
			for(j=0;i-j>=0&&i+j+1<m;j++)
			{
				if(s[i-j]!=s[i+j+1])break;
					if(2*j+2>max){max=2*j+2;x=i-j;y=i+j+1;}
					
				
				
				}
				
				
			
			
			
			
			
			
			
			
			
			}
			for(i=p[x];i<=p[y];i++)
				{
					printf("%c",buf[i]);
					
					
					}
	
					printf("\n");
	
	
	
	
	return 0;
	}