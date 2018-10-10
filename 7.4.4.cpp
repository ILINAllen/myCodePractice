#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> neigh[26];
int n;
int node[8];

int resd = 26;
vector<int> vmin;

void choose(int m, int a[], bool used[], int pos[], int curd)
{
    if (m == n) {
        if (curd < resd) {
            resd = curd;
            vmin.clear();
            for (int i = 0; i < n; i++)
                vmin.push_back(a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        int k = node[i];
        if (!used[k]) {
            int maxd = curd;
            for (int j = 0; j < neigh[k].size(); j++) {
                int r = neigh[k][j];
                if (used[r])
                    maxd = max(maxd, abs(m - pos[r]));
            }
            if (maxd < resd) {
                a[m] = k;
                used[k] = 1;
                pos[k] = m;
                choose(m+1, a, used, pos, maxd);
                used[k] = 0;
            }
        }
    }
}

int main(void)
{
    char ch;
    while ((ch = getchar()) != '#') {
        for (int i = 0; i < 26; i++)
            neigh[i].clear();
        bool used[26];
        memset(used, 0, sizeof(used));
        do {
            int i = ch-'A';
            used[i] = 1;
            getchar();
            while ((ch = getchar()) != ';' && ch != '\n') {
                int j = ch-'A';
                neigh[i].push_back(j);
                neigh[j].push_back(i);
                used[j] = 1;
            }
            if (ch == '\n') break;
        } while (ch = getchar());
        n = 0;
        for (int i = 0; i < 26; i++) {
            if (used[i]) node[n++] = i;
        }

        int a[8], pos[26];
        memset(used, 0, sizeof(used));
        resd = 26;
        choose(0, a, used, pos, 0);

        for (int i = 0; i < n; i++)
            printf("%c ", vmin[i]+'A');
        printf("-> %d\n", resd);
    }

    return 0;
}