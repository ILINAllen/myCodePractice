#include <stdio.h>
#include<stdlib.h>
#include <string.h>
char word[100][10];
char sorted[100][10];

int char_cmp(const void *_a,const void *_b)
{
	char *a=(char *)_a;
	char *b=(char *)_b;
	return *a-*b;
	
	
	}

int string_cmp(const void *_a,const void *_b)
{
	char *a=(char *)_a;
	char *b=(char *)_b;
	return strcmp(a,b);
	
	
	}
int i;
char s[10];
int main()
{ 
   freopen("5.3.2.in","r",stdin);
	freopen("5.3.2.out","w",stdout);

	int n=0;
	for(;;)
	{
		scanf("%s",word[n]);
		if(word[n][0]=='*')break;
		
		n++;
		
		
		}
		
		qsort(word,n,sizeof(word[0]),string_cmp);
		
		
		for(i=0;i<n;i++)
		{
			strcpy(sorted[i],word[i]);
			qsort(sorted[i],strlen(sorted[i]),sizeof(char),char_cmp);
			
			}
			int found;
			while(scanf("%s",s)==1)
			{
				found=0;
				qsort(s,strlen(s),sizeof(char),char_cmp);
				for(i=0;i<n;i++)
				{
					if(strcmp(sorted[i],s)==0)
					{
						found=1;
						printf("%s ",word[i]);
					
						}
						
						
						
					
					
					}
					
				if(found==0)
							printf("wu");
				printf("\n");
				
				
				
				}
		
		
		
	return 0;
	
	
	}