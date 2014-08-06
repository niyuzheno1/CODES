#include "mode.h"
typedef long long ll;
#undef INF
#define MN  100000+10
#define MM  500000*2+10
#define INF 1000000000
struct edge{
       int u,v,w,ne,f;
       bool fl;
}e[MM];
int hd[MN],tot;
void addedge(int u,int v,int w){
 e[++tot].u = u,e[tot].v = v;e[tot].w = w;e[tot].ne = hd[u];hd[u]=tot;
 e[++tot].u = v,e[tot].v = u;e[tot].w = w;e[tot].ne = hd[v];hd[v]=tot;
}
int ds[MN],dt[MN],ss[MN],st[MN];
typedef priority_queue<pii,vector<pii>,greater<pii> > pq;
pq qs,qt;
struct data{
       int v,ne,f;
}e2[MN];
int tot2,hd2[MN];
void addedge2(int u,int v){
 e2[++tot2].v = v;e2[tot2].ne = hd2[u];hd2[u] = tot2;
}
int fa[MN],prt[MN],n;
void dj(int p,int * d,int * s,pq q){
  for(int i = 1;i<=n;++i) d[i] = INF;
  d[p] = 0;q.push(MP(0,p));
  for(int z = 1;z<=n;++z){
   if(q.empty()) break;
   pii tmp = q.top();q.pop();
   while(!q.empty() && s[tmp.Y]) tmp = q.top(),q.pop();
   int x = tmp.Y;
   if(s[x]) break;
   s[x] = 1;
   for(int i = hd[x];i;i=e[i].ne){
    int y = e[i].v;
    if(!s[y] && d[y] > d[x]+e[i].w)d[y] = d[x]+e[i].w,q.push(MP(d[y],y));
   }
  }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;int m=gi;
    for(int i = 1,u,v,w;i<=m;++i)u=gi,v=gi,w=gi,addedge(u,v,w);
    dj(1,ds,ss,qs);
    dj(n,dt,st,qt);
    for(int i = 1;i<n;++i)
     for(int j = hd[i];j;j=e[j].ne){
     int k = e[j].v;
      if(dt[k]+e[j].w == dt[i]){
       fa[i] = k,e[j].fl = true;
       addedge2(k,i);break;
      }
     }
    static int qu[MN],bot;
    qu[bot=1]=n;
    for(int i = 1;i<=bot;++i){
     int x = qu[i];
     for(int j = hd2[x];j;j=e2[j].ne) qu[++bot]=e2[j].v;
    }
    for(int i = 1;i<=bot;++i){
     int x = qu[i];
     if(ds[x]+dt[x] == ds[n]) prt[x] = x;
     else prt[x] = prt[fa[x]];
    }
    int ans = INF;
    for(int i = 1;i<=tot;++i){
     if(e[i].fl || ds[e[i].u]+e[i].w+dt[e[i].v]==ds[n])continue;
     int u = prt[e[i].u],v = prt[e[i].v];
     if(!u || !v || u==v || ds[u] > ds[v]) continue;
     int tmp = ds[e[i].u]+e[i].w+dt[e[i].v];
     ans = min(ans,tmp);
    }
    if(ans == INF )puts("-1");
    else printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
