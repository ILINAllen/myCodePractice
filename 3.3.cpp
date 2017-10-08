#include <stdio.h>
int printit(int abc,int de)
{
	printf("    %d\n",abc);
	printf("X   %d\n",de);
	printf("______\n");
	printf("    %d\n",abc*(de%10));
	printf("+  %d\n",abc*(de/10));
	printf("________\n");
	printf("    %d\n",abc*de);
	
	return 0;
	}



int isture(int abc,int de,char *s,int n)
{ 
//	int a[20];
	int i;
	int k;
	int flag=0;
	int abcde=abc*de;
	int abcd=abc*(de/10);
	int abce=abc*(de%10);
	while(abc!=0)
	{
		k=abc%10;
		for(i=0;i<n;i++)
		{
			if(k==(s[i]-'0'))
		     flag=1;		
			}
			
			abc=abc/10;
		   if(flag==0)
			   return 0;
		flag=0;
		}
	     abc=de;
		
			while(abc!=0)
	{
		k=abc%10;
		for(i=0;i<n;i++)
		{
			if(k==(s[i]-'0'))
		     flag=1;		
			}
			
			abc=abc/10;
		   if(flag==0)
			   return 0;
			flag=0;
		}
		abc=abcde;
			while(abc!=0)
	{
		k=abc%10;
		for(i=0;i<n;i++)
		{
			if(k==(s[i]-'0'))
		     flag=1;		
			}
			
			abc=abc/10;
		   if(flag==0)
			   return 0;
			flag=0;
		}
		
		
		abc=abcd;
			while(abc!=0)
	{
		k=abc%10;
		for(i=0;i<n;i++)
		{
			if(k==(s[i]-'0'))
		     flag=1;		
			}
			
			abc=abc/10;
		   if(flag==0)
			   return 0;
			flag=0;
		}
		abc=abce;
			while(abc!=0)
	{
		k=abc%10;
		for(i=0;i<n;i++)
		{
			if(k==(s[i]-'0'))
		     flag=1;		
			}
			
			abc=abc/10;
		   if(flag==0)
			   return 0;
			flag=0;
		}
		
	
	return 1;
	}



int main()
{
	char s[20];
	int abc,de;
	int count=0;
	scanf("%s",s);
	int n=sizeof(s)-1;
	for(abc=111;abc<=999;abc++)
	{	for(de=11;de<=99;de++)
	{if(isture(abc,de,s,n)!=0)
	
		{
			count++;	
			printf("<%d>\n",count);
			printit(abc,de);
		
		
		}		}	
	}

	
	return 0;
	
	
	
	
	}
	
	