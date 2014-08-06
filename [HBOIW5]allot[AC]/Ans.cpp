#include "mode.h"
#undef INF
#define INF 0x7f7f7f7f
#define MN 410
#define ME 20010
typedef int64 LL;
struct edge
{
       int n,f;
};
int st[MN],v[ME],w[ME],flow[ME];edge lk[ME];
int d[MN],num[MN],q[MN],cur[MN],pre[ME];
int n,m,k,e=1,node,ans;
void add(int x,int y,int z){
 ++e;lk[e].n = st[x],st[x] = e,v[e] = y,w[e] = z;
}
void bfs(int t){
CLEAR(d,0x7f);d[t] = 0;
++num[0];
int r = 1;q[1] = t;
 for(int i=0;i<r;)
 {
  int u = q[++i];
  for(int p=st[u];p;p=lk[p].n)
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
     for(int p = pre[t];p;p=pre[v[p^1]])
      if(mf >= (w[p]-flow[p]))
      {
       mf = (w[p]-flow[p]);
       ret = v[p^1];
      }
     ans += mf;
     for(int p = pre[t];p;p=pre[v[p^1]]) 
      flow[p] += mf,flow[p^1] -= mf; 
     return ret;
}

void isap(int s,int t)
{
     bfs(t);
     for(int i = 1;i<=node;++i) cur[i] = st[i];
     int u = s;
     while(d[s] < node)
     {
      if(u == t)
       u = aug(t);
      
      bool adv = 0;
      for(int p = cur[u];p;p=lk[p].n)
       if(d[u] == d[v[p]]+1 && flow[p] < w[p])
        {
           cur[u] = p;
           pre[v[p]] = p;
           u = v[p];
           adv = 1;
           break;
        }
      if(!adv){
       if(--num[d[u]] == 0) break;
       cur[u] = st[u];
       int md = node;
       for(int p = st[u];p;p=lk[p].n)
        if(flow[p] < w[p])
         md = min(md,d[v[p]]);
       d[u] = md+1;
       ++num[d[u]];
       if(u != s) u = v[pre[u]^1];
      }
     }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int x,y,l,r,mid;
    n = gi,m= gi,k =gi;
    node = n+3;
    for(int i = 1;i<=m;++i)
    {
     x = gi,y = gi,l = gi,mid = gi,r = gi;
     add(x,y,r-mid);
     add(y,x,mid-l);
    }
    add(node,n+1,INF);
    add(n+1,node,0);
    add(node,n+2,INF);
    add(n+2,node,0);
    for(int i = 1;i<=n;++i)
    {
     ans = 0;
     CLEAR(flow,0);
     isap(node,i);
     puts(ans>=k ? "1": "0");
    }
    closeIO();
    return EXIT_SUCCESS;
}
