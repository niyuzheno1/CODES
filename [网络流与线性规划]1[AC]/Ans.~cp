#include "mode.h"
#undef INF 
#undef TRA
#define TRA(x,y) for(int x = st[y];x;x=lk[x].n)
#define PRE(x,y) for(int x = pre[y];p;p=pre[v[p^1]])
#define FIND(x,y) for(int x = cur[y];p;p=lk[x].n)
#define INF 0x7f7f7f7f
#define MN 1010
#define ME 110*110*2
typedef long long LL;
struct edge{
 int n,f;
};
int st[MN],v[ME],w[ME],flow[ME];
edge lk[ME];
int d[MN],num[MN],q[MN],cur[MN],pre[MN],match[MN];
int n,m,e=1,node,ans;
void add(int x,int y,int z){
++e;lk[e].n = st[x],st[x] = e,v[e] = y,w[e] = z;
}
void bfs(int t){
 CLEAR(d,0x7f);d[t] = 0;
 ++num[0];
 int r = 1;q[1] = t;
 for(int i = 0;i<r;){
  int u = q[++i];
  TRA(p,u)
   if(d[v[p]] >= INF)
   {
    d[v[p]] = d[u]+1;
    ++num[d[v[p]]];
    q[++r] = v[p];
   }
 }
}
int aug(int t)
{
    LL mf = INF;
    int ret = t;
    PRE(p,t)
     if(mf >= (w[p]-flow[p]))
     {
      mf = (w[p]-flow[p]);
      ret = v[p^1];
     }
    ans += mf;
    PRE(p,t)
     flow[p] += mf,flow[p^1] -= mf;
    return ret;
}

void isap(int s,int t){
 bfs(t);
 for(int i = 1;i<=node;++i) cur[i] = st[i];
 int u = s;
 while(d[s] < node){
  if(u == t)
   u = aug(t);
  bool adv = 0;
  FIND(p,u)
   if(d[u] == d[v[p]]+1 && flow[p] < w[p])
   {
    cur[u] = p,pre[v[p]] = p,u = v[p],adv = 1;
    break;
   }
  if(!adv){
   if(--num[d[u]] == 0) 
    break;
   cur[u] = st[u];
   int md = node;
   TRA(p,u)
    if(flow[p] < w[p])
     md = min(md,d[v[p]]);
   d[u] = md+1;
   ++num[d[u]];
   if(u != s) u = v[pre[u]^1];
  }
 }
}

void show(int s,int t)
{
 for(int i = 2;i<=e;++i)
 {
  int q = v[i];
  if(v[i^1] == s && flow[i] == w[i] && !match[q]){
   match[q] = 1;
   TRA(u,q)
   {
   int vv = v[u];
   if(flow[u] == 0) continue;
   if(match[vv]) continue;
    TRA(y,vv)
     if(v[y] == t && flow[y]==w[y] )
     {
      match[vv] = 1;
      printf("%d %d\n",q-1,vv-1);
     }
    if(match[vv]) break;
   }
  }
 }
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi, m = gi;
    int s = 1,t = m+2;node = m+2;
    int x,y;
    while(scanf("%d%d",&x,&y) && x != -1 && y != -1)
     add(x+1,y+1,INF),add(y+1,x+1,0);
    for(int i = 2;i<=n+1;++i)
     add(1,i,1),add(i,1,0);
    for(int i = n+2;i<=m+1;++i)
     add(i,t,1),add(t,i,0);
    isap(s,t);
    if(ans == 0)
     printf("No solution");
    else{
     printf("%d\n",ans);
     show(s,t);
    }
    closeIO();
    return EXIT_SUCCESS;
}
