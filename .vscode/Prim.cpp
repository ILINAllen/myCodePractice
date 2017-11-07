#include <iostream>
#define maxint 1000000
using namespace std;


int a[100][100];


int main()
{
    int n;
    int v1, v2, w, m;
    freopen("Prim.in", "r", stdin);
    while(cin >> n >> m)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                a[i][j] = maxint;
        for(int i = 1; i <= m; i++)
        {
            cin >> v1 >> v2 >> w;
            a[v1][v2] = w;
            a[v2][v1] = w;
        }

		for(int i = 1; i <= n; i++)
		{  
            for(int j = 1; j <= n; j++)
                cout << a[i][j] << " ";
			cout << endl;
		}
        int lowcost[100] = {0};
        int closest[100] = {0};
        int s[100] = {0};
        
        for(int i = 1; i <= n; i++)
        {
            lowcost[i] = a[1][i];
            closest[i] = 1;
            s[i] = 0;
        }
        s[1] = 1;
        for(int i = 1; i < n; i++)
        {
            int min =  maxint;
            int j = 1;
            for(int k = 2; k <= n; k++)
            {
                if((lowcost[k] < min) && (!s[k]))
                {
                    min = lowcost[k]; 
                    j = k;
                }
            }
            cout << "joint node: " << closest[j] << ";" << j << endl;
            s[j] = 1;
            for(int k = 2; k <= n; k++)
            {
                if((a[j][k] < lowcost[k]) && (!s[k]))
                {
                    lowcost[k] = a[j][k];
                    closest[k] = j; 
                }
            }
            
        }
        cout << lowcost[n-1] << endl;
    }
    return 0;
}