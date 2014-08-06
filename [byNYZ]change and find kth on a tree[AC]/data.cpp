#include "mode.h"
#include "iodata.h"

using namespace std;
const int MN = 10,MM = 50,ML = 100;
struct edge{int v,f,n;};
edge lk[(MN+1)*2];
int f[MN+1],st[MN+1],dep[MN+1];
inline void add(int x,int y){lk[SIZE(st)].v = y;lk[SIZE(st)].n = st[x];st[x] = SIZE(st);++SIZE(st);}
int gf(int x)
{
return (f[x] = (x ==f[x] ? x: gf(f[x])) );
}
inline void merge(int x,int y)
{
    f[gf(x)] = f[gf(y)];
}
void dfs(int x)
{
     TRA(u,x)
     {
      int v = lk[u].v;
      lk[u^1].f = 1;
      dep[v] = dep[x]+1;
      f[v] = x;
      dfs(v);
     }
}
int lca(int x,int y)
{
    int ret = 0;
    while(x != y)
    {
     if(dep[x] < dep[y]) swap(x,y);
     x = f[x];
    }
    ++ret;
    return ret;
}
int main(int argc, char *argv[])
{
    init("sample.in");
    CLEAR(st,0xff);st[0] = 0;
    int n = gin%MN+1,m = gin%MM+1;
    pin_(n);pli(m);
    for(int i = 1;i<=n;f[i]=i,++i) pin_(gin%ML);
    nl();
    for(int i = 1,x,y;i<n;++i) 
    {
      x = gin%n+1,y = gin%n+1;
      if(gf(x) != gf(y))
       merge(x,y),pin_(x),pli(y),add(x,y),add(y,x);
      else
       --i;
    }
    f[1] = 0;dep[1] = 1; 
    dfs(1);
    for(int i = 1;i<=m;++i)
    {
     int opt = gin%2+1;
     int u , v , k;
     pin_(opt);
     switch(opt)
     {
      case 1:
            u = gin%n+1,v = gin%n+1, k =(gin%lca(u,v))+1;
           pin_(u);pin_(v);pli(k);
           break;
      case 2:
            u = gin%n+1,v = gin%ML+1;
           pin_(u);pli(v);
           break;
           
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
