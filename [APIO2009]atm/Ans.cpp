#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#define ff fprintf
#define X first
#define Y second
using namespace std;
typedef long long int64;
const int64 maxn = 500010*3,maxe=500010*3,finf = 0xfefefefe;
struct lik{int64 f,n,v;};
typedef pair<int,int> pii;
int64 par;
struct graph{
 lik lk[maxe];
 int64 st[maxn];
 int64 deg[maxn];
 int64 bar[maxn];
 int64 tot;
 void add(int64 x,int64 y)
 {tot++;lk[tot].f = x;lk[tot].n=st[x];lk[tot].v = y;st[x]=tot;}
};
graph g,g2;
FILE * d;
stack<int> p;
int64 dfn[maxn],low[maxn],scc[maxn],n,m,ti,nn,vis[maxn],cc,dir[maxn],f[maxn],w[maxn],S,P,dd[maxn];
void dfs(int64 x)
{
 ti++;
 low[x] = dfn[x] = ti;
 p.push(x);
 for(int64 i = g.st[x];i != 0;i=g.lk[i].n)
 {
  int64 v = g.lk[i].v;
  if(!dfn[v])
   dfs(v),low[x]=min(low[x],low[v]);
  else if(!scc[v])
   low[x] = min(low[x],dfn[v]);
 }
 if(low[x] == dfn[x])
 {
  nn++;
  for(;;)
  {
   int64 u = p.top();p.pop();
   scc[u] = nn;
   w[nn] += dd[u];
   if(u == x)
    break;
  }
 }
}
priority_queue<pii , vector<pii> , greater<pii> > q;
int main(int argc, char *argv[])
{
    memset(f,0,sizeof(f));
    freopen("atm.in","r",stdin);
    freopen("atm.out","w",stdout);
    d = fopen("debug.txt","w");
    scanf("%I64d%I64d",&n,&m);
    int64 x,y;
    for(int64 i = 1;i<=m;i++)
     scanf("%I64d%I64d",&x,&y),g.add(x,y);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d",&dd[i]);
    
    scanf("%I64d%I64d",&S,&P);
    dfs(S);
    /*for(int64 i = 1;i<=n;i++)
     ff(d,"%d\n",scc[i]);*/
    for(int64 i = 1;i<=g.tot;i++)
    {
     int64 u = scc[g.lk[i].f];int64 v = scc[g.lk[i].v];
     if(u != v)
     {g2.add(u,v);g2.deg[v]++;}
    }
    for(int64 i = 1;i<=P;i++)
    {
     int64 x;scanf("%d",&x);
     g2.bar[scc[x]] = 1;
    }
    int64 ans = 0;
    for(int64 i = 1;i<=nn;i++)
     q.push(pii(g2.deg[i],i));
    bool flag = 0;
    f[scc[S]] = 0;ans = w[scc[S]];
    while(!q.empty())
    {
     pii tp = q.top();q.pop();
     if(vis[tp.Y])
      continue;
     vis[tp.Y] = 1;cc++;dir[cc] = tp.Y;
     for(int64 i = g2.st[tp.Y];i != 0;i=g2.lk[i].n)
     {
      int64 v = g2.lk[i].v;
      g2.deg[v]--;
      q.push(pii(g2.deg[v],v));
      if(f[tp.Y] != finf){
       f[v] = max(f[v],f[tp.Y]+w[tp.Y]);
       if(g2.bar[v])
        ans = max(ans,f[v]+w[v]);
      }
     }
     
    }
    printf("%I64d\n",ans);
    fclose(d);fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
