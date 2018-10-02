#include <stdio.h>

int main()
{
	int a,b,c,ans,i;
	
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a&&!b) return 0;
			c=0;
			ans=0;
			//while(a!=0||b!=0)             //creat by linzhaolun
			for(i=9;i>=0;i--)
			{
				c=(a%10+b%10+c)>9?1:0;
				ans+=c;
				a/=10;
				b/=10;
				
				
				
				}
		
		
		printf("%d",ans);
		
		}
	
	
	
	return 0;
	
	}