#include <stdio.h>
int main()
{ char c;
	int q=0;
	freopen("5.1.2.in","r",stdin);
		freopen("5.1.2.out","w",stdout);
	while((c=getchar())!=EOF)
	{
		if(c=='"')
		{
			q=!q;
			if(q)printf("“");
				else printf("”");
			}
			else putchar(c);
		
		
		
		}
	
	return 0;
	}