#include <stdio.h>
#include <string.h>
char s[100];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	int i,j,ok;
	for(i=1;i<=len;i++)
	{ ok=1;
		for(j=i;j<len;j++)
			if(s[j]!=s[j%i]){ok=0;break;}
		if(ok){printf("%d",i);break;}
		
		}	
	
	
	
	}