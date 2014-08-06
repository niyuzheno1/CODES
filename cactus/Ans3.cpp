#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 50010,maxm = 10000*1000*2;
int n,m,tot,cnt,ti,tot2;
struct link{int n,v,d;int del;};
link lk[maxm];
int st[maxn],ans,dis[maxn];
void add(int x,int y)
{
     lk[tot].n = st[x];lk[tot].v = y;lk[tot].d=1;st[x] = tot;
     tot++;
}
void bfs(int x)
{
 memset(dis,0x7f,sizeof(dis));
 queue<int> q;
 q.push(x);
 dis[x] = 0;
 while(!q.empty()){
   int x = q.front();q.pop();
   for(int i = st[x];i!=-1;i=lk[i].n)
   {
   int u = lk[i].v;
    if(dis[u] > dis[x] + 1)
    {
    dis[u] = dis[x] + 1;
    q.push(u);
    }
   }
  }
}
int main(int argc, char *argv[])
{
    memset(st,0xff,sizeof(st));
    freopen("cactus.in","r",stdin);
    freopen("cactus.ans2","w",stdout);
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
    for(int i = 1;i<=n;i++){
     bfs(i);
     for(int j = 1;j<=n;j++)
      ans = max(ans,dis[j]);
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
