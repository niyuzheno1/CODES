#include "mode.h"

#define TRA(x,y) for(int x = st[y],v;~x;x=lk[x].n) if(!lk[x].f)
const int MN = 2010;
struct edge{ int f,v,n;};
edge lk[MN*2];int st[MN],size[MN],tot,n,m,q[MN],r,son[MN],fa[MN],pfa[MN],q2[MN],r2,dep[MN];
void addedge(int x,int y){lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;++tot;}

int lca(int x,int y)
{
    while(x != y)
    {
     if(pfa[x] == pfa[y] && pfa[x] != 0)
      return dep[x]>dep[y]?y:x;
     else{
      if(dep[pfa[x]?pfa[x]:fa[x]] < dep[pfa[y]?pfa[y]:fa[y]]) swap(x,y);
      x = pfa[x]?pfa[x]:fa[x];
     }
    }
    return dep[x]>dep[y]?y:x;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    CLEAR(st,0xff);
    n = gi;m = gi;
    for(int i = 1,x,y;i<n;++i){x =gi;y=gi;addedge(x,y);addedge(y,x);}
    q[r = 1] = 1;
    dep[1] = 1;
    for(int i = 1,u;i<=r;++i)
     TRA(j,(u = q[i])){v = lk[j].v,++r,q[r] = v,lk[j^1].f = 1;dep[v] = dep[u]+1;}
    for(int i = r,u;i>=1;--i){
     size[ u = q[i]] = 1;
     TRA(j,q[i]){v = lk[j].v,size[u] += size[v];fa[v] = u;
     if(size[v] > size[son[u]]) pfa[son[u]] = 0,son[u] = v,pfa[v] = u;}
    }
    for(int i = r,u;i>=1;--i)
     if(son[u = q[i]] == 0)
     {
      int p ,k;
      for(p = u;pfa[p];p = fa[p]);
      for(k = son[p];k;k=son[k]) pfa[k] = p;
     }
    for(int i = 1,x,y;i<=m;++i)
     x=gi,y=gi,printf("%d\n",lca(x,y));
    closeIO();
    return EXIT_SUCCESS;
}
