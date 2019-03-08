
/*
给定一个树，选择若干点，使得选择的结点中任一
结点不会和它的子结点同时选择，求能选结点最大数量。
同时判断方案数是否为一。

思路：树的最大独立集，用树形dp，dfs一遍找每个结点
的父亲，是为了从下向上刷每个结点儿子的最大独立集
和and每个结点孙子的最大独立集和的表

判断方案数是否唯一同样在树形dp的同时递推判断即可

算法复杂度可以是线性


*/






#include<cstdio>
#include<iostream>
#include<cstring>
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int n;
bool flag;
const int N = 220;
map<string,int >name;
struct Edge
{
    int v;
    Edge(int _v=0) :v(_v){};
};
vector<Edge> es[N];
int dp[N]; 
int fa[N]; //每个节点的父亲
int dep[N]; //每个结点的深度
int sum_s[N]; //每个结点儿子的最大独立集和
bool viss[N],visgs[N],visdp[N]; //分别标记对应结点的dp值，孙子的最大独立集和，儿子的最大独立集和 他们是否名单唯一
int sum_gs[N]; //每个结点孙子的最大独立集和
int mdep;
void dfs(int u,int pa)
{
    if(pa==-1) dep[u]=0;
    else dep[u] = dep[pa]+1;
    mdep=max(mdep,dep[u]);
    int sz=es[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=es[u][i].v;
        if(v!=pa) dfs(v,fa[v]=u);
    }
}
void ini()
{
    flag=0;
    mdep=-1;
    name.clear();
    for(int i=0;i<n;i++) es[i].clear();
    memset(sum_gs,0,sizeof(sum_gs));
    memset(sum_s,0,sizeof(sum_s));
    memset(viss,0,sizeof(viss));
    memset(visgs,0,sizeof(visgs));
    memset(visdp,0,sizeof(visdp));
}
int main()
{
    while(scanf("%d",&n),n)
    {
        ini();
        int sz=0;
        string empl,boos;
        cin>>boos;
        if(!name.count(boos))
            name[boos]=sz++;
        for(int i=0;i<n-1;i++)
        {
            cin>>empl>>boos;
            if(!name.count(empl))
                name[empl]=sz++;
            if(!name.count(boos))
                name[boos]=sz++;
            int u=name[empl],v=name[boos];
            es[u].push_back(Edge(v));
            es[v].push_back(Edge(u));
        }
        dfs(0,-1);
        for(int l=mdep;l>=0;l--)
            for(int i=n-1;i>=0;i--)
            {
                if(dep[i]==l)
                {
                    if(sum_s[i]>1+sum_gs[i])
                    {
                        dp[i]=sum_s[i];
                        visdp[i]=viss[i];
                    }
                    else if(sum_s[i]<1+sum_gs[i])
                    {
                        dp[i]=1+sum_gs[i];
                        visdp[i]=visgs[i];
                    }
                    else
                    {
                        dp[i]=sum_s[i];
                        visdp[i]=true;
                    }
                    if(l>=1)
                    {
                        sum_s[fa[i]] +=dp[i];
                        viss[fa[i]] |= visdp[i];
                    }
                    if(l>=2)
                    {
                        sum_gs[ fa[fa[i]] ] += dp[i];
                        visgs[fa[fa[i]]] |= visdp[i];
                    }
                }
            }
        printf("%d ",dp[0]);
        if(visdp[0]) puts("No");
        else puts("Yes");
    }
    return 0;
}