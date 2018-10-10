#include<stdio.h>
#define N 100
int s[N],n;
void search(int cur)
{
    int i,j,k,flag,ok;
    if(cur==n)//已经填了n个，符合要求了已经
    {
        for(i=0;i<n;i++)
            printf("%d",s[i]);
        printf("\n");
        return ;
    }
    for(i=7;i<=9;i++)
    {
        s[cur]=i;
        flag=1;//假设这种安排是可以的 
        for(j=1;j*2<=cur+1;j++)//判断长度为j的后缀 
        {
            ok=1;//先假设这个后缀不会产生相同的子串 
            for(k=0;k<j;k++)
            {
                if(s[cur-k]!=s[cur-j-k])
                {
                    ok=0;
                    break;
                }
            }
            if(ok==1)//产生相同的子串了，这种假设不行 
            {
                flag=0;
                break;
            } 
        }
        if(flag==1)
            search(cur+1);
    }
}          
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        search(0);
    }
    system("pause");
    return 0;
}