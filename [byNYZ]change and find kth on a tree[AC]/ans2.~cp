#include "mode.h"
#define MN 1010
struct edge{int f,v,n;};
edge lk[MN];int st[MN];
int q[MN],a[MN],fa[MN],dep[MN];
void add(int x,int y)
{
 lk[SIZE(st)].v = y;lk[SIZE(st)].n = st[x];st[x] = SIZE(st);++SIZE(st); 
}
int n,m;
void dfs(int x)
{
 TRA(u,x)
 {
  int v = lk[u].v;
  lk[u^1].f = 1;
  fa[v] = x;
  dep[v] = dep[x]+1;
  dfs(v);
 }
}
void find(int x,int y)
{
     SIZE(q) = 0;
     while(x != y)
     {
      if(dep[x] < dep[y]) swap(x,y);
      q[++SIZE(q)] = a[x];
      x = fa[x];
     }
     q[++SIZE(q)] = a[x];
}
int main(int argc, char *argv[])
{
    setIO("sample");
    CLEAR(st,0xff);st[0] = 0;
    n = gi,m = gi;
    for(int i = 1;i<=n;++i) a[i] = gi;
    for(int i = 1,x,y;i<n;++i) x = gi,y = gi,add(x,y),add(y,x);
    dep[1] = 1;
    dfs(1);
    for(int i = 1,opt,x,y,z;i<=m;++i)
    {
     opt = gi;
     switch(opt){
      case 1:
           x = gi, y = gi,z = gi;
           find(x,y);
           sort(q+1,q+1+SIZE(q));
           printf("%d\n",q[z]);
           break;
      case 2:
           x = gi, y = gi;
           a[x]=y;
           break;
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
