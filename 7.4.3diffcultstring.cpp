#include<stdio.h>
#define N 100
int s[N],n;
void search(int cur)
{
    int i,j,k,flag,ok;
    if(cur==n)//�Ѿ�����n��������Ҫ�����Ѿ�
    {
        for(i=0;i<n;i++)
            printf("%d",s[i]);
        printf("\n");
        return ;
    }
    for(i=7;i<=9;i++)
    {
        s[cur]=i;
        flag=1;//�������ְ����ǿ��Ե� 
        for(j=1;j*2<=cur+1;j++)//�жϳ���Ϊj�ĺ�׺ 
        {
            ok=1;//�ȼ��������׺���������ͬ���Ӵ� 
            for(k=0;k<j;k++)
            {
                if(s[cur-k]!=s[cur-j-k])
                {
                    ok=0;
                    break;
                }
            }
            if(ok==1)//������ͬ���Ӵ��ˣ����ּ��費�� 
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