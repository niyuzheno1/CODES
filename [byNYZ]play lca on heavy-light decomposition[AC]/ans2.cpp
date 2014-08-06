#include "mode.h"
#define TRA(x,y) for(int x = st[y],v;~x;x=lk[x].n) if(!lk[x].f)
using namespace std;
const int MN  = 1010,ML = 17;
int st[MN],n , m , q[MN],r,f[MN][ML+1],tot,dep[MN];
struct edge{ int f,v,n;};
edge lk[MN*2];
void addedge(int x,int y){lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;++tot;}

int lca(int x,int y)
{
 if(dep[x] > dep[y] ) swap(x,y);
 for(int i = ML;i>=0;--i)
  if(dep[x] <= dep[f[y][i]]) y = f[y][i];
 while(dep[x] < dep[f[y][0]]) y = f[y][0];
 if(x == y) return x;
 for(int i = ML;i>=0;--i)
  if(f[x][i] != f[y][i])
   x = f[x][i],y = f[y][i];
 while(f[x][0] != f[y][0])
  x = f[x][0], y = f[y][0];
 return f[x][0];
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;m = gi;CLEAR(st,0xff);
    for(int i = 1,x,y;i<n;++i)
    {
     x =gi,y =gi;
     addedge(x,y);addedge(y,x);
    }
    dep[1] = 1;r = 1;q[r] =1;
    for(int i = 1,u;i<=r;++i)
     TRA(j,(u = q[i]))
      {v = lk[j].v,++r,q[r] = v,f[v][0] = u,lk[j^1].f = 1;dep[v] = dep[u]+1; }
    for(int i = 1,u;i<=r;++i){
     u = q[i];
     for(int j = 1;j<=ML;++j)f[u][j] = f[f[u][j-1]][j-1];
    }
    for(int i =1;i<=m;++i)
    {
     int x=gi,y=gi;
     printf("%d\n",lca(x,y));
    }
    closeIO();
    return EXIT_SUCCESS;
}
