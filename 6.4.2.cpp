#include <iostream>  
#include <queue>

using namespace std ;

const int MAXN = 105 ; 
int dx[] = {-1,1,0,0} ; 
int dy[] = {0,0,-1,1} ; 
char name[] = "UDLR" ;

int n , m , nx , ny ; 
int maze[MAXN][MAXN] , vis[MAXN][MAXN] , fa[MAXN][MAXN] , dist[MAXN][MAXN] , last_dir[MAXN][MAXN] ;

queue<int> q ; 
void Bfs(int x , int y) { 
 int u ; 
 u = m*x+y ; 
 vis[x][y] = 1 ; 
 dist[x][y] = 0 ; 
 fa[x][y] = u ; 
 q.push(u) ; 
 while (!q.empty()) 
{ 
  u = q.front() ; 
  q.pop() ; 
  x = u/m ; y = u%m ; 
  for (int i = 0 ; i < 4 ; ++ i) 
 { 
   nx = x+dx[i] ; ny = y+dy[i] ; 
   if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] && !vis[nx][ny]) 
   { 
    int v = nx * m + ny ; 
    vis[nx][ny] = 1 ; 
    fa[nx][ny] = u ; 
    dist[nx][ny] = dist[x][y] + 1 ; 
    q.push(v) ; 
    last_dir[nx][ny] = i ; 
   } 
  } 
 }  
}

void Print_path(int x , int y) { 
 int fx = fa[x][y]/m ; 
 int fy = fa[x][y]%m ; 
 
 if (fx != x || fy != y) { 
  Print_path(fx,fy) ; 
  cout << name[last_dir[x][y]] ; 
 } 
}

int dir[MAXN*MAXN] ; 
void Print_path2(int x , int y) { 
 int c = 0 ;

 while (true) { 
  int fx = fa[x][y]/m ; 
  int fy = fa[x][y]%m ; 
  if (fx == x && fy == y) { 
   break ; 
  } 
  dir[c++] = last_dir[x][y] ; 
  x = fx ; 
  y = fy ; 
 } 
 while (c--) { 
  cout << name[dir[c]] ; 
 } 
}

int main() {
 int i , j ; 
 int xs,ys,xt,yt ; 
 
 cin >> n >> m >> xs >> ys >> xt >> yt ;

 for (i = 0 ; i < n ; ++ i) { 
  for (j = 0 ; j < m ; ++ j) { 
   cin >> maze[i][j] ; 
  } 
 }

 memset(vis,0,sizeof(vis)) ; 
 Bfs(xs,ys) ; 
 Print_path(xt,yt) ; 
 cout << endl ;

 return 0 ; 
}