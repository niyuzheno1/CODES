#include "mode.h"
#define MN 2000010
int a[MN],n,b[MN],lm[MN],rm[MN],stk[MN],top,st[MN],fa[MN],tot,ans[MN];
struct _edge
{int n,v,f,w;};
_edge lk[MN];
int gf(int x){
 if(fa[x] == x) return x; return (fa[x] = gf(fa[x]));
}
int unions(int x,int y){
 fa[gf(y)] = fa[gf(x)]  ;
}
inline void ad(int x,int y,int z,int w){
++tot;lk[tot].v = x;lk[tot].n = st[y];st[y] = tot;lk[tot].w = w;
}
inline void add(int x,int y,int z,int w){
ad(x,y,z,w);
}
int main(int argc, char *argv[])
{
    setIO("sample");CLEAR(st,0xff);
    n = gi;
    for(int i = 1;i<=n;fa[i]=i,++i) a[i] = gi,b[i] = a[i];
    sort(b+1,b+1+n);
    int l = unique(b+1,b+1+n)-b-1;
    for(int i = 1;i<=n;++i) a[i] = lower_bound(b+1,b+l+1,a[i])-b;
    a[0] = -INF,a[n+1] = -INF;
    for(int i = 0;i<=n+1;++i)
    {
     while(top && a[stk[top]]>a[i]) rm[stk[top]]=i,--top;
     ++top;stk[top] = i;
    }
    top = 0;
    for(int i = n+1;i>=0;--i)
    {
     while(top && a[stk[top]]>a[i]) lm[stk[top]]=i, --top;

     ++top;stk[top] = i;
    }
    top = 0;
    for(int i = 1;i<=n;++i)
     add(lm[i]+1,rm[i]-1,0,i);
    for(int i = 1;i<=n;++i){
     while(top && a[stk[top]] <= a[i]) unions(i,stk[top]),--top;
     ++top; stk[top] = i;
     TRA(x,i) 
     ans[lk[x].w] = a[gf(lk[x].v)];
    }
    for(int i = 1;i<=n;++i)
     printf(i==1?"%d":" %d",b[ans[i]]-b[a[i]]);
    puts(" ");
    closeIO();
    return EXIT_SUCCESS;
}
