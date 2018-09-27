#include <stdio.h>
#include <string.h>
#define MAXN 20
int s[1<<MAXN];                    //将1左移20位，即得最大结点个数为2eMAXN-1
int main(void)
{
    int D, I;
    while(scanf("%d%d", &D, &I) == 2)
    {
        memset(s, 0, sizeof(s));    //开关（默认0为关闭状态），memset函数包含头文件string.h
        int k, n = (1<<D)-1;        //n是最大结点编号
        for(int i = 0; i < I; i++)  //连续让n个小球下落
        {
            k = 1;
            for(; ;)
            {
                s[k] = !s[k];
                k = s[k] ? k*2 : k*2+1; //根据开关状态选择下落方向
                if(k > n) break;    //已经落“出界”了，下落次数为D
            }
        }
        printf("%d\n", k/2);        //“出界”之前的叶子编号
    }
    return 0;
}