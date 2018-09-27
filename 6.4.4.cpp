#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
const int max_l = 28;
//char word[maxn][max_l];
char ret[maxn][max_l];
struct edge{
    int to;
    int next;
    char str[max_l];
};
edge node[maxn];
int adj[max_l];
int in[max_l];
int out[max_l];
bool used[maxn];
bool exist[max_l]; 
int p[max_l]; /* 并查集 */
int num_e = 0;
int ret_e = 0;
//从大到小排序
bool cmp(edge p1, edge p2)
{
    return strcmp(p1.str, p2.str) > 0;
}
void init()
{
    for(int i = 0; i < max_l; ++i)
    {
        in[i] = 0;
        out[i] = 0;
        p[i] = -1;
        exist[i] = 0;
        adj[i] = -1;
    }
    for(int j = 0; j < maxn; ++j)
        used[j] = 0;
    num_e = 0;
    ret_e = 0;
}
int find_set(int u)
{
    if(0 <= p[u])
    {
        p[u] = find_set(p[u]);
        return p[u];
    }
    return u;
}
void union_set(int u, int v)
{
    int r1 = find_set(u);
    int r2 = find_set(v);
    if(r1 == r2)
        return;
    int n1 = p[r1];
    int n2 = p[r2];
    if(n1 < n2)
    {
        p[r2] = r1;
        p[r1] += n2;
    }
    else
    {
        p[r1] = r2;
        p[r2] += n1;
    }
}
void Eular(int vertix, int idx)
{
    for(int i = adj[vertix]; i != -1; i = node[i].next)
    {
        if(!used[i])
        {
    //        strcpy(ret[ret_e++], node[i].str);
            used[i] = 1;
            Eular(node[i].to, i);
        }
    }
    /*idx就是node数组的下标，标识一条边*/
    if(0 <= idx)
        strcpy(ret[ret_e++], node[idx].str);
}
int main()
{
    int t = 0;
    int n = 0;
    int i = 0;
    int u = 0;
    int v = 0;
    int start = 0; //从哪个顶点开始遍历
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(!n)
            continue;
        for(i = 0; i < n; ++i)
            scanf("%s", node[i].str);
        init();
        start = max_l;
        sort(node, node + n, cmp);
        //建图
        for(i = 0; i < n; ++i)
        {
            u = node[i].str[0] - 'a';
            v = node[i].str[strlen(node[i].str) - 1] - 'a';
            in[v]++;
            out[u]++;
            exist[u] = 1;
            exist[v] = 1;
            union_set(u, v);
            node[num_e].to = v;
            node[num_e].next = adj[u];
            adj[u] = num_e++;
        }
        //判断是否连通
        int scc = 0;
        for(i = 0; i < max_l; ++i)
        {
            if(exist[i] && 0 > p[i])
                ++scc;
            if(1 < scc)
                break;
        }
        if(1 < scc) //不连通
        {
            printf("***\n");
            continue;
        }
        //是通路or回路
        int a = 0;
        int b = 0;
        start = -1;
        for(i = 0; i < max_l; ++i)
        {
            if(exist[i] && in[i] != out[i])
            {
                if(1 == in[i] - out[i])
                    ++a;    
                else if(1 == out[i] - in[i])
                {
                    ++b;
                    start = i;
                }
                else
                    break;
            }
        }
        if(i < max_l)
        {
            printf("***\n");
            continue;
        }
        else
        {
            if(!((0 == a + b) || (1 == a && 1 == b)))
            {
                printf("***\n");
                continue;
            }
            if(-1 == start)
            {//回路 找到第一个存在的字母
                int k = 0;
                for(k = 0; k < max_l; ++k)
                {
                    if(out[k])
                        break;
                }
                start = k;
            }
            //从顶点start开始dfs
            Eular(start, -1);
            printf("%s", ret[ret_e - 1]);
            for(i = ret_e - 2; i >= 0; --i)
                printf(".%s", ret[i]);
            printf("\n");
        }
    }
    return 0;
}