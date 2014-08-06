#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#define X first
#define Y second
using namespace std;
int n;
typedef pair<int,int> q;
struct p
{
 int n,b;
 bool operator < (p x) const
 {
  return b < x.b;
 }
};
p a[61];
int u,v;
int state;
/*map<int,q> p[2];*/
vector<q> f[21];
vector<int> g[21];
void dfs1(int x,int y)
{
     if(x >= 2*n+1)
     {
      /*if(p[0][y].X > u || !p[1].count(y))
       p[0][y] = q(u,v);
      if(p[1][y].Y > v || !p[1].count(y))
       p[1][y] = q(u,v);*/
      f[y].push_back(q(u,v));
      g[y].push_back(state);
      return;
     }
     u += a[x].b-(1000-a[x].b);
     state = state<<1;
     state |= 1;
     dfs1(x+1,y+1);
     state = state>>1;
     u -= a[x].b-(1000-a[x].b);
     v += a[x].b-(1000-a[x].b);
     state = state<<1;
     dfs1(x+1,y);
     state = state>>1;
     v -= a[x].b-(1000-a[x].b);
}
bool ans = 0;
void print(int x,int y)
{
     vector<int> c,b;
     c.clear();b.clear();
     for(int i = 2*n+1;i<=3*n;i++)
      if(x & (1<<(3*n-i)))
       c.push_back(a[i].n);
      else
       b.push_back(a[i].n);
     for(int i = n+1;i<=2*n;i++)
      if(x & (1<<(2*n-i)))
       c.push_back(a[i].n);
      else
       b.push_back(a[i].n);
     for(int i = 0;i<c.size();i++)
      printf("%d\n",c[i]);
     for(int i = 0;i<b.size();i++)
      printf("%d\n",b[i]);
}
void dfs2(int x,int y)
{
     if(x >= 3*n+1)
     {
      int o = n-y;
      for(int i = 0;i < f[o].size();i++)
       if(f[o][i].X + u > 0 && f[o][i].Y + v > 0){
        ans=1,print(state,g[o][i]);
        break;
       }
      return;
     }
     u += a[x].b-(1000-a[x].b);
     state = state<<1;
     state |= 1;
     dfs2(x+1,y+1);
     if(ans)
      return;
     state = state>>1;
     u -= a[x].b-(1000-a[x].b);
     v += a[x].b-(1000-a[x].b);
     state = state<<1;
     dfs2(x+1,y);
     if(ans)
      return;
     state = state>>1;
     v -= a[x].b-(1000-a[x].b);
}
int main(int argc, char *argv[])
{
    scanf("%d",&n);
    for(int i  = 1;i<=3*n;i++)
     scanf("%d",&a[i].b),a[i].n = i;
    sort(a+1,a+1+3*n);
    for(int i = 1;i<=n;i++)
     printf("%d\n",a[i].n);
    dfs1(n+1,0);
    dfs2(2*n+1,0);
    system("PAUSE");
    return EXIT_SUCCESS;
}
