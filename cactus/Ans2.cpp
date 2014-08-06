#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 50010*2,maxm = 10000*1000*2;
int n,m,tot,cnt,ti,tot2;
struct link{int n,v,d;int del;};
link lk[maxm];
int st[maxn],ver[maxn];
int num[maxn];
int sta[maxn],end[maxn];
vector<int> ma[maxn];
int g[maxn],f[maxn],fa[maxn],p[maxn];
void add(int x,int y)
{
     lk[tot].n = st[x];lk[tot].v = y;lk[tot].d=1;st[x] = tot;
     tot++;
}
void circle(int x,int y)
{
     cnt++;
     tot2++;
     num[tot2] = x;int u = lk[y].v;
     lk[y].del = lk[y^1].del = 1;
     sta[cnt] = tot2;
     while(x != u)
     {
      y = fa[x];y = y^1;
      lk[y].del = lk[y^1].del = 1;
      x = lk[y].v;
      tot2++;
      num[tot2] = x;
     }
     end[cnt] = tot2;
     ma[x].push_back(cnt);
}
int ans = 0;
void check(int x,int y)
{
     int st = sta[y];int ed = end[y];
     int len = ed-st+1;
     for(int i = st;i<=ed;i++)
      for(int j = i+1;j<=ed;j++)
       if(i != j)
        ans = max(ans,g[num[i]]+g[num[j]]+min(len-abs(j-i),abs(j-i)));
     for(int i = st;i<=ed;i++)
      g[x] = max(g[x],g[num[i]]+min(ed-i,i-st+1)); 
}
void dfs(int x)
{
     ver[x] = ++ti;
     for(int i = st[x];i!=-1;i=lk[i].n)
      if(i != (fa[x]^1))
      {
       int u = lk[i].v;
       if(!ver[u])
        fa[u] = i,dfs(u);
       else if(ver[u] < ver[x])
        circle(x,i);
      }
     for(int i = st[x];i!=-1;i=lk[i].n)
      if(lk[i].del == 0 && i != (fa[x]^1)){
       ans = max(ans,g[lk[i].v]+1+g[x]);
       g[x] = max(g[lk[i].v]+1,g[x]);
      }
     for(int i = 0;i<ma[x].size();i++)
      check(x,ma[x][i]);
}
int main(int argc, char *argv[])
{
    memset(st,0xff,sizeof(st));
    freopen("cactus.in","r",stdin);
    freopen("cactus.ans1","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++)
    {
     int j;scanf("%d",&j);
     int last = 0;
     for(int k = 1;k<=j;k++)
     {
     int x;scanf("%d",&x);
     if(last != 0){
      add(last,x);add(x,last);
      }
     last = x;
     }
    }
    dfs(1);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
