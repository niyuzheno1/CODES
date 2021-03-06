#include "mode.h"
#include "iodata.h"
#define TRA(x,y) for(int x = st[y];~x;x = lk[x].n) if(!lk[x].d)
using namespace std;
// for tree 
const int MN = 11,ML = 25,MM = 11,MI = 1010;
int fa[MN+1],f[MN+1][ML],st[MN+1],tot,len,a[MN*2+2],s[MN+1],dep[MN+1];
struct ed{ int d,v,n;};
ed lk[MN*2+2];
int gf(int x){return fa[x] == x ? fa[x] : fa[x] = gf(fa[x]);}
void merge(int x,int y)
{
     fa[gf(x)] = fa[gf(y)];
}
void add(int x,int y){ lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;++tot;}

void dfs(int x)
{
 int tmp = 1,k = 0;
 while(len-tmp > 0)
 {f[x][k] = a[len-tmp];++k;tmp*=2;}
 s[x] = 1;
 TRA(u,x)
 {++len;a[len] = lk[u].v;lk[u^1].d = 1;dep[lk[u].v] = dep[x]+1;dfs(lk[u].v);s[x] += s[lk[u].v];--len;}
}
int lca(int x,int y)
{
  if(dep[x] > dep[y]) swap(x,y);
  for(int i = ML;i>=0;--i)
   if(dep[x] <= dep[f[y][i]])
    y = f[y][i];
  while(dep[x] < dep[f[y][0]])
    y = f[y][0];
  if(x == y)
   return x;
  for(int i = ML;i>=0;--i)
   if(f[x][i] != f[y][i])
    x = f[x][i],y = f[y][i];
  while(f[x][0] != f[y][0])
   x = f[x][0],y = f[y][0];
  return f[x][0];
}
int main(int argc, char *argv[])
{
    init("sample.in");
    CLEAR(st,0xff);
    int n = rand()%(MN-1)+2,m = rand()%MM+1;
    pin_(n);pli(m);
    for(int i = 1;i<=n;pin_(rand()%MI),fa[i] = i,++i);nl();
    for(int i = 1;i<n;++i)
    {
     int x =rand()%n+1 , y = rand()%n+1;
     if(gf(x) != gf(y))
     {
      pin_(x);pli(y);merge(x,y);
      add(x,y);add(y,x);
     }
     else --i;
    }
    ++len;a[len] = 1;dep[1] = 1;
    dfs(1);
    for(int i = 1;i<=m;++i)
    {
     int x =rand()%n+1 , y = rand()%n+1;
     if(x == y)
      --i;
     else
     {
      pin_(x);pin_(y);
      int u = lca(x,y);
      int s = dep[x]+dep[y]-2*dep[u]+1;
      pli(rand()%s+1);
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
