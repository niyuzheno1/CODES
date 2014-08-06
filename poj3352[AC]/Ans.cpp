#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxF = 5010,maxR = 20010*2;
int F,R,tot,st[maxF],ti,fs[maxF],nn;
int low[maxF],dfn[maxF],vis[maxF],adj[maxF][maxF],deg[maxF];
struct lik{int n,v,del;};
lik lk[maxR];
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
   fs[v] = i^1;
   dfs(v,x);
   low[x] = min(low[x],low[v]);
  }
  else if(v != y)
   low[x] = min(low[x],dfn[v]);
 }
}
void dfs2(int x)
{
 vis[x] = nn;
 for(int i = st[x];i!=-1;i=lk[i].n)
 {int v = lk[i].v;
  if(lk[i].del)
   continue;
  if(!vis[v])
   dfs2(v);
 }
}
int main(int argc, char *argv[])
{
    memset(st,0xff,sizeof(st));
    //freopen("rpaths.in","r",stdin);
    //freopen("rpaths.out","w",stdout);
    scanf("%d%d",&F,&R);
    for(int i = 1;i<=R;i++){int x,y;scanf("%d%d",&x,&y);add(x,y);}
    dfs(1,0);
    for(int i = 2;i<=F;i++)
    {
     int  u = fs[i];
     int fa = lk[u].v;
     if(dfn[fa] < low[i])
      lk[u^1].del =lk[u].del = 1;
    }
    for(int i = 1;i<=F;i++)
     if(!vis[i])
     {
      nn++;
      dfs2(i);
     }
    for(int i = 1;i<=F;i++)
     for(int j = st[i];j != -1;j=lk[j].n){
     int v = lk[j].v;
     adj[vis[i]][vis[v]] = adj[vis[v]][vis[i]]= 1;
     }
    for(int i = 1;i<=nn;i++)
     for(int j = 1;j<=nn;j++)
      if(adj[i][j] && i != j)
       deg[i]++;
    int ans = 0;
    for(int i = 1;i<=nn;i++)
     if(deg[i] == 1)
      ans++;
    if(ans != 1)
    printf("%d\n",(ans+1)/2);
    else
    printf("0\n");
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
