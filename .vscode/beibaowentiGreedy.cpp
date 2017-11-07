#include <iostream>

using namespace std;

struct item
{
    int w;
    int v;
    double c;
}items[10];

int comp(const item & a, const item & b)
{
    if(a.c > b.c)
        return true;
    else 
        return false;
}

int main()
{

    freopen("beibaowentiGreedy.in", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> items[i].w >> items[i].v;
        items[i].c = items[i].v/items[i].w * 1.0; 
    }

    sort(items + 1, items + n + 1, comp);

    for(int i = 1; i <= n; i++)
    {
        cout << items[i].w << items[i].v << items[i].c << endl;
    }

    double value = 0;
    int i = 1;
    double cleft = 50;
    while(i <= n && cleft >= items[i].w)
    {
        value += items[i].v;
        cleft -= items[i].w;
        i++;
    }

    if(i <= n) value += (cleft / items[i].w * 1.0) * items[i].v;


    cout << value << endl;
   

    return 0;
}

