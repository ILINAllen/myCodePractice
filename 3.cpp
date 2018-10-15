#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//求公共子串（连续），注意跟求公共子序列有区别
int lcstr( const char* s1,const char* s2)
{
	//clen保存公共子串的最大长度，s1_Mindex保存 s1公共子串的最后一个元素的位置
	int len1,len2,i,k,cLen=1,s1_Mindex=0;
	int **c;
	if(s1==NULL || s2==NULL) return -1;
	len1=strlen(s1);
	len2=strlen(s2);
	if(len1< 1 || len2 < 1) return -1;
	c=malloc(sizeof(int*)*len1);
	for(i=0;i<len1;i++)
	{
		c[i]=(int *)malloc(len2*sizeof(int));
		memset(c[i],0,len2*sizeof(int));
	}
	/**********init end!*************/
	for(i=0;i<len1;i++)
	{
		for(k=0;k<len2;k++)
		{
			if(i==0 || k==0)
			{
				if(s1[i]==s2[k]) c[i][k]=1;
				else c[i][k]=0;
			}
			else
			{
				if (s1[i] == s2[k])
				{
					c[i][k] = c[i - 1][k - 1] + 1;
					if (cLen < c[i][k])
					{
						cLen = c[i][k];
						s1_Mindex = i;
					}
				}
			}
		}
	}
	//*************//
	// printf the one of lcs 只是其中一条，如果存在多条。
	for(i=0;i<cLen;i++)
	{
		printf("%c",*(s1+s1_Mindex-cLen+1+i));
	}
	/*****free array*************/
	for(i=0;i<len1;i++)
		free(c[i]);
	free(c);
	return cLen;

}
int main(void) {
	char a[]="abcgooglecba";
	char b[]="cbagoogleABVC";
	printf("\nlcstr = %d\n",lcstr(a,b));
	return 0;
}
