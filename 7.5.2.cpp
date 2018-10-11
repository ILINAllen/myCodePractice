#include <stdio.h>
#include <string.h>
struct CUP{
    int maxv;
}cup[3];
struct STATE{
    int d[3];
}state[10000],state2[10000];
int ans;
int vall;
char v[1003][1003];//分别为中杯和小杯

__inline int min(int a,int b){
    return a<b?a:b;
}
int bfs(int d,int pre){
    int len = 0,i,j,k,t1,t;
    char a[3],as;
    for(i = 0; i < pre; i++){
        for(j = 0; j < 3;j++)
            for(k = 0; k < 3; k++){
                if(j == k)
                    continue;
                if(state[i].d[j] != 0 && state[i].d[k] != cup[k].maxv){//判断可以移动的状态
                    t1 = min(state[i].d[j],cup[k].maxv - state[i].d[k]);
                    state2[len].d[j] = state[i].d[j] - t1;
                    state2[len].d[k] = state[i].d[k] + t1;
                    a[0] = a[1] = a[2] =1;
                    a[j] = a[k] = 0;
                    for(t = 0 ; t < 3; t++)//找到未替换的
                        if(a[t]){
                            as = t;
                            break;
                        }
                    state2[len].d[as] = state[i].d[as];
                    if(state2[len].d[0] == 4 || state2[len].d[1] == 4 || state2[len].d[2] == 4){
                        puts("find at ");
                        printf("%d\n",d);
                        return true;
                    }
                    if(v[state2[len].d[1]][state2[len].d[2]])
                        continue;
                    else {
                        v[state2[len].d[1]][state2[len].d[2]] = 1;
                        len ++;
                    }

                }
            }
    }
    memcpy(state,state2,sizeof(state2[0])*len);
    if(len != 0)
        return bfs(d+1,len);
    else return false;
}
int main(){
    cup[0].maxv = 6;
    cup[1].maxv = 3;
    cup[2].maxv = 1;
    ans = 4;
    memset(v,0,sizeof(v));
    state[0].d[0] = 6;
    state[0].d[1] = state[0].d[2] = 0;
    vall = 6;
    bfs(1,1);
    return 0;
	
	
	
}