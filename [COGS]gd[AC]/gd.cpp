#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110,maxe = 400;
struct lin
{
 int n,v;
};
int dfn[maxn],ti,n,st[maxn],tot,low[maxn],fa[maxn],ans[maxn];
lin lk[maxe];
void add1(int x,int y){tot++;lk[tot].n = st[x];lk[tot].v = y;st[x] = tot;}
void add(int x,int y){add1(x,y);add1(y,x);}
void dfs(int x,int y)
{
 ti++;
 dfn[x] = low[x] = ti;
 fa[x] = y;
 for(int i = st[x];i != 0;i=lk[i].n)
 {
  int v = lk[i].v;
  if(!dfn[v])
  {dfs(v,x);
   int z = low[v];
   low[x] = min(low[x],z);}
  else if(v != y)
   low[x] = min(dfn[v],low[x]);
 }
 return;
}
int main(int argc, char *argv[])
{
    freopen("gd.in","r",stdin);
    freopen("gd.out","w",stdout);
    scanf("%d",&n);
    int x,y;
    while(scanf("%d%d",&x,&y) != EOF)
     add(x,y);
    dfs(1,0);
    int rc = 0;
    for(int i = 2;i<=n;i++)
     {
      int u = fa[i];
      if(u == 1)
       rc++;
      else if(low[i] >= dfn[u])
       ans[u] = 1;
     }
    if(rc > 1)
     ans[1] = 1;
    int cnt = 0;
    for(int i = 1;i<=n;i++)
     if(ans[i])
      cnt++;
    printf("%d\n",cnt);
    for(int i = 1;i<=n;i++)
     if(ans[i])
      printf("%d\n",i);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
