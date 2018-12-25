#include <iostream>  
#include <string>  
using namespace std;  
  
const int MAXN = 10000;int n, S, V[MAXN], d[MAXN], vis[MAXN], W[MAXN];  
const int INF = 100000000;  
void Print_path(int *d,int S)  
{  
    for(int i=0;i<n;i++)  
      if(S>=V[i]&&d[S]==d[S-V[i]]+W[i])  
        {  
          printf("%d ",i);  
          Print_path(d,S-V[i]);  
          break;
      printf("\n");		 
        }  
} 

int dpmax(int S) {  
    if(vis[S]) return d[S];  
    vis[S] = 1;  
    int &ans = d[S];  
    ans = -1 << 30;  
    for(int i = 1; i <= n; ++i) {  
        if(S >= V[i]) ans = max(ans, dpmax(S - V[i]) + W[i]);  
	
    }  
    return ans;  
}  
  
int main() {  
	freopen("9--4.in","r",stdin);
    memset(vis, 0, sizeof(vis));  
    cin >> n >> S;  
	d[0]=0;
	vis[0]=1;
    for(int i = 1; i <= n; ++i) {  
        cin >> V[i] >> W[i];  
    }  
    cout << dpmax(S) << endl;  
	Print_path(d,S);
    return 0;  
}  