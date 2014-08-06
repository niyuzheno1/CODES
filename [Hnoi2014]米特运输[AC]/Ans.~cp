#include "mode.h"
#define MN 500010
int n;
const int64 mod[] = {0,1000000007,1306213,23333};
int tot,ans,st[MN],q[MN],fa[MN];
typedef pair<pll,int64> plll;
plll f[MN],g[MN];
int64 w[MN],son[MN];
struct edge{
 int n,f,v;
};
edge lk[MN<<1];
inline void ae(int x,int y){
 lk[tot].v = y,lk[tot].n = st[x],st[x] = tot,lk[tot].f = 0,++tot;
}
inline void addedge(int x,int y){
 ae(x,y);ae(y,x);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;CLEAR(st,0xff);
    for(int i = 1;i<=n;++i) w[i] = gi;
    for(int i = 1,x,y;i<n;++i){
     x = gi,y = gi;
     addedge(x,y);
    }
    int r = 1;
    q[r] = 1;
    for(int i = 1;i<=r;++i)
     TRA(u,q[i])
     {
      ++r;q[r] = lk[u].v;
      lk[u^1].f = 1;
      fa[lk[u].v] = q[i];
      ++son[q[i]];
     }
    g[0] = MP(MP(int64(1),int64(1)),int64(1));
    for(int i = 1;i<=r;++i){
     int u = q[i],v = fa[q[i]];
     f[u] = MP(MP((g[v].X.X*w[u])%mod[1],(g[v].X.Y*w[u])%mod[2]),(g[v].Y*w[u])%mod[3]);
     g[u] = MP(MP((g[v].X.X*son[u])%mod[1],(g[v].X.Y*son[u])%mod[2]),(g[v].Y*son[u])%mod[3]);
    }
    sort(f+1,f+n+1);
    int ans = 0;r = 0;
    for(int i = 1;i<=n;++i)
     if(f[i] == f[i-1] && i != 1) ++r;
     else ans = max(ans,r),r = 1;
    ans = max(ans,r);
    printf("%d\n",n-ans);
    closeIO();
    return EXIT_SUCCESS;
}
