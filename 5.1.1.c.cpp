#include <stdio.h>
int main()
{
	char *s="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	char c;
	int i;
	while((c=getchar())!=EOF)
	{
	/*	
		for(i=1;s[i]!='\0';i++)
		if(s[i]==c)
			printf("%c",s[i-1]);
			if(c==' ')
				printf("%c",c);   */
		
	
			    for(i = 1; s[i]&&s[i]!=c; i++);  
     if(s[i]) putchar(s[i-1]);  
     else putchar(c);  
    
			
			
	
		
		
		
		}
	
	
	
	
	
	
	
	
	return 0;
	}