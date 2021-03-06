#include "mode.h"
#include "iomgr.h"
#define MK 1010
#define MN 100010
int n,m,sz,tot,k,a[MN],st[MN];
struct bk{
 int a[MK];
};
struct po{
 bk * p[MK];
};
po b[MN];
struct _edge{
 int n,f,v;
};
_edge lk[MN*2];
void ad(int x,int y){
 lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;
 ++tot;
}
void add(int x,int y){
 ad(x,y);
 ad(y,x);
}
void dfs(int x,int fa){
  if(x == 5)
   x = 5;
  if(fa != -1)
   memcpy(&b[x],&b[fa],sizeof(po));
  int f = a[x]/sz,g = a[x]%sz;
  b[x].p[f] = new bk;
  if(fa != -1 && b[fa].p[f] != (bk*)NULL)
   memcpy(b[x].p[f],b[fa].p[f],sizeof(bk));
  else
   memset(b[x].p[f],0,sizeof(bk));
  b[x].p[f]->a[g] = x;
  TRA(u,x)
  {
   lk[u].f = 1;lk[u^1].f=1;
   dfs(lk[u].v,x);
  }
}
int lastans = 0;
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi, k = gi;
    sz = int(sqrt(m))+1;CLEAR(st,0xff);
    for(int i = 1;i<=n;++i) a[i] = gi;
    for(int i = 1;i<=n-1;++i)
    {
     int x=gi,y=gi;
     add(x,y);
    }
    dfs(1,-1);
    for(int i = 1;i<=k;++i){
     int opx = gi,cnt = gi;
     opx ^= lastans,cnt ^= lastans;
     int f = cnt/sz,g = cnt % sz;
     printf("%d\n",lastans = b[opx].p[f]->a[g]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
