#include <cstdlib>
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define rep(i,n) for(int64 i = 1;i<=n;i++)
#define ree(i,x) for(int64 i = st[x];i != 0;i=lk[i].ne)
using namespace std;
typedef long long int64;
const int64 maxn = 500010,maxm = 500010;
int64 n,u,v,w;
int64 m,tot;
int64 land[maxn];
int64 ar[maxm],st[maxn],nar[maxm];
int64 f[maxn],vis[maxn];
int64 bfsn[maxn],uf[maxn],len,up[maxn];
int64 dis[maxn];
struct
{
 int64 to,ne,w;
}lk[maxn*4];
void li(int64 x,int64 y,int64 z)
{
 tot++;
 lk[tot].to = y;
 lk[tot].ne = st[x];
 lk[tot].w = z;
 st[x] = tot;

}
bool cmp(int64 x,int64 y)
{
     return dis[x]<dis[y];
}
bool cmp2(int64 x,int64 y)
{
     return dis[x]<dis[y];
}
int64 b[maxm],o[maxm],totb;
int64 a[maxm],tota;
bool ok(int64 x)
{
 tota = totb = 0;
 memcpy(nar,ar,sizeof(nar));
 memset(vis,0,sizeof(vis));
 memset(o,0xff,sizeof(o));
 sort(nar+1,nar+m+1,cmp);
 for(int64 j = m;j>=1;j--)
  if(dis[nar[j]] > x)
   vis[nar[j]]++;
  else
   a[++tota] = nar[j];
 totb = 0;
 
 for(int64 i = len;i>=1;i--)
 {
  if(vis[bfsn[i]] == true)
   o[bfsn[i]] = x;
  if(o[bfsn[i]] >= 0 && land[bfsn[i]])
   o[uf[bfsn[i]]] = 0;
  o[f[bfsn[i]]] = max(o[f[bfsn[i]]],max((long long)(-1),o[bfsn[i]]-up[bfsn[i]]));
  if(o[f[bfsn[i]]] >= 0 && land[f[bfsn[i]]])
   o[f[bfsn[i]]] = 0;
 }
 ree(i,1)
 if(o[lk[i].to] == -1)
   b[++totb] = lk[i].to;
 sort(b+1,b+1+totb,cmp2); 
 int64 j = 1;
 for(int64 i = 1;i<=tota;i++)
 {
  if(o[uf[a[i]]] == -1)
   o[uf[a[i]]] = 0;
  else{
  while(o[b[j]] != -1)
   j++;
  int64 tm = dis[a[i]]+up[b[j]];
  if(tm <= x)
   o[b[j]] = 0;
  }
  if(j > totb)
   return true;
 }
 while(o[b[j]] != -1)
   j++;
 if(j > totb)
  return true;
 else
  return false;
}
void bfs()
{
     queue<int64> q;
     q.push(1);
     while(!q.empty())
     {
      int64 x = q.front();q.pop();
      if(vis[x])
       continue;
      vis[x] = true;
      len++;
      bfsn[len] = x;
      
      ree(i,x)
      if(!vis[lk[i].to]){
       f[lk[i].to] = x;
       if(x != 1)
        uf[lk[i].to] = uf[x];
       else
        uf[lk[i].to] = lk[i].to;
       up[lk[i].to] = lk[i].w;
       dis[lk[i].to] = dis[x]+lk[i].w;
       q.push(lk[i].to);
      }
     }
}
void dfs(int x,int y)
{
 int cnt = 0;
 ree(i,x)
 if(lk[i].to != y)
   cnt++;
 land[x] = 1;
 if(cnt > 1)
  return;
 ree(i,x)
  if(lk[i].to != y)
   dfs(lk[i].to,x);
}
int main(int argc, char *argv[])
{
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    int64 l = 0,r = 0;
    memset(st,0,sizeof(st));
    scanf("%I64d",&n);
    rep(i,n-1)
    {
     scanf("%I64d%I64d%I64d",&u,&v,&w);
     li(u,v,w);li(v,u,w);
    }
    bfs();
    ree(i,1)
     dfs(lk[i].to,1);
    scanf("%d",&m);
    rep(i,n)
     r = max(r,dis[i]);
    r = r*2;
    rep(i,m)
     scanf("%I64d",&ar[i]);
    while(l < r)
    {
     int64 mid = (l+r)/2;
     if(ok(mid))
      r = mid;
     else
      l = mid+1;
    }
    printf("%I64d",(l+r)/2);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
