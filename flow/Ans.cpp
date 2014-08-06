#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <iomanip>
#define X first
#define Y second
#define pb push_back
#define zero(x) memset(x,0,sizeof(x));
using namespace std;
typedef pair<int,int> p;
typedef vector<int> v;
map<int,v> o;
vector<p> d,h; 
int n,m;
bool t[510][510];
bool f[510][510];
int a[510][510];
int c[510][510];
queue<p> q;
char inf[101],ouf[101];
p operator + (p x,p y)
{
 return p(x.X+y.X,x.Y+y.Y);
}
void bfs(p x)
{
     t[x.X][x.Y] = 1;
     int l = 0x7f7f7f7f,r = 0;
     while(!q.empty())
      q.pop();
     memset(f,0,sizeof(f));
     q.push(x);
     while(!q.empty())
     {
     p y = q.front();q.pop();
     if(y.X  == n)
      l = min(l,y.Y),r = max(r,y.Y);
      for(int i = 0;i<4;i++)
      {
      x = y+d[i];
      if(!f[x.X][x.Y] && a[y.X][y.Y] > a[x.X][x.Y]){
       f[x.X][x.Y] = 1;
       t[x.X][x.Y] = 1;
       q.push(x);
       }
      }
     }
     h.pb(p(l,r));
}

int dfs(int x,int y)
{
    if(y == m)
     return 0;
    if(c[x][y])
     return c[x][y];
    int ans = 0x7f7f7f7f;
    
    for(int j = x;j<=y;j++)
     for(int i = 0;i<o[j+1].size();i++)
     ans =min(dfs(j+1,o[j+1][i])+1,ans);
    return c[x][y]=ans;
}

int main(int argc, char *argv[])
{
for(int cani = 3;cani<=3;cani++){
    
    zero(inf);
    zero(ouf);
    sprintf(inf,"flow%d.in",cani);
    sprintf(ouf,"flow%d.out",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
o.clear();
d.clear();
h.clear();
zero(t);
zero(f);
zero(a);
zero(c);   
    memset(c,0,sizeof(c));
    memset(a,0x7f,sizeof(a));
    scanf("%d %d",&n,&m);
    d.clear();
    d.pb(p(1,0));
    d.pb(p(-1,0));
    d.pb(p(0,1));
    d.pb(p(0,-1));
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      scanf("%d",&a[i][j]);
    for(int j = 1;j<=m;j++)
     bfs(p(1,j));
   
    int ans = 0;
    for(int j = 1;j<=m;j++)
     if(t[n][j] == 0)
      ans++;
    if(ans)
    {
     printf("0\n%d\n",ans);
    }
    else{
    for(int j = 0;j<h.size();j++){
     o[h[j].X].push_back(h[j].Y);
  
    }
    printf("1\n%d\n",dfs(0,0));
    }
    fclose(stdin);fclose(stdout);
    exit(0);
}
  
    return EXIT_SUCCESS;
}
