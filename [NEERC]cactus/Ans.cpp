#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define ff fprintf
using namespace std;
FILE * d;
const int maxn = 20010,maxm = 2001000;
struct lik{ int n,v,del;};
lik lk[maxm];
int st[maxn],nn,n,m,tot,low[maxn],dfn[maxn],fs[maxn],vis[maxn],ti,ans1,ans2,cnt[maxn];
void add1(int x,int y){lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;tot++;}
void add(int x,int y){add1(x,y);add1(y,x);}
void dfs(int x,int y)
{
 ti++;
 dfn[x] = low[x] = ti;
 for(int i = st[x];i!=-1;i=lk[i].n)
 {
  int v = lk[i].v;
  if(!dfn[v])
  {
   dfs(v,x);
   fs[v] = i^1;
   low[x] = min(low[x],low[v]);
  }
  else if(y != v)
   low[x] = min(low[x],dfn[v]);
 }
}
int dfs3(int x,int y,int z)
{
 int ret = 0;
 cnt[x] = z;
 for(int i = st[x];i!=-1;i=lk[i].n)
 {
  int v = lk[i].v;
  if(lk[i].del)
   continue;
  if(!cnt[v])
  {
   ret = dfs3(v,x,z+1);
   if(ret)
    break;
  }
  else if(y != v)
   return z-cnt[v]+1;
 }
 return ret;
}
int dfs2(int x)
{
 queue<int> q;
 q.push(x);
 int ret = 1;
 vis[x] = nn;
 while(!q.empty())
 {
  int y = q.front();q.pop();
  int u = 0;
  if(y == 2 || y == 3)
   u = 0;
  for(int i = st[y];i != -1;i=lk[i].n)
  {
   int v = lk[i].v;
   if(!vis[v] && !lk[i].del)
   {
   // u++;
    vis[v] = vis[y];
    ret++;
    q.push(v);
   }
  }
 }
 int len = dfs3(x,-1,1);
 if(len != 0 && ret != len)
  ans1 = 1;
 return ret;
}
int main(int argc, char *argv[])
{
    freopen("cactus.in","r",stdin);
    freopen("cactus.out","w",stdout);
    d = fopen("debug.txt","w");
    memset(st,0xff,sizeof(st));
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++)
    {int w = 0;scanf("%d",&w);
     int x,y = -1;
     while(w--)
     {scanf("%d",&x);if(y != -1)add(y,x);y = x;}
    }
    dfs(1,-1);
    for(int i = 2;i<=n;i++)
    {
     int l = fs[i];
     int v = lk[l].v;
     
     if(dfn[v] < low[i]){
      //ff(d,"%d %d\n",i,v);
      lk[l].del = lk[l^1].del = 1;
     }
    }
    ans2 = 1;
    for(int i = 1;i<=n;i++)
     if(!vis[i])
     {
      nn++;
      int x = dfs2(i);
      //ff(d,"%d %d\n",i,x);
      if(x > 1)
       x++;
      ans2 *= (x);
      if(ans1)
       break;
     }
    if(ans1)
     printf("0\n");
    else
     printf("%d\n",ans2);
    fclose(d);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
