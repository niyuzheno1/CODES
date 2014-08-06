#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxm = 100000,maxn = 1100,inf = 0x7f7f7f7f;
struct link
{
 int n;
 int u;
 int v;
 int f;
};
link lk[maxm];
int st[maxn];
int dis[maxn];
int n,f,d,tot;
void add1(int x,int y,int z,int f)
{
 lk[tot].n = st[x];
 lk[tot].u = z;
 lk[tot].v = y;
 lk[tot].f = f;
 st[x] = tot;
 tot++;
}
void add(int x,int y,int z,int f)
{
   add1(x,y,z,f);
   add1(y,x,-z,0);
}
int s = 0,t = 0;
bool bfs()
{
     memset(dis,0x7f,sizeof(dis));
     dis[0] = 0;
     queue<int> q;
     q.push(0);
     while(!q.empty())
     {
      int u = q.front();q.pop();
      for(int i = st[u];i!=-1;i=lk[i].n)
       if(dis[lk[i].v] > dis[u]+1 && lk[i].f > 0)
        dis[lk[i].v] = dis[u]+1,q.push(lk[i].v);
     }
     return dis[t]!=inf;
}
int dfs(int x,int y)
{
   if(x == t)
    return y;
   int f = 0,tmp;
   for(int i = st[x];i!=-1;i=lk[i].n)
    if(dis[lk[i].v] == dis[x]+1 && (tmp=dfs(lk[i].v,min(y,lk[i].f))) > 0 ){
    lk[i].f -= tmp;
    lk[i^1].f += tmp;
    y-=tmp;
    f+= tmp;
    if(y == 0)
     break;
   }
   return f;
}
int main(int argc, char *argv[])
{
    memset(st,0xff,sizeof(st));
    freopen("dining.in","r",stdin);
    freopen("dining.out","w",stdout);
    scanf("%d%d%d",&n,&f,&d);
    t = f+n+n+d+1;
    for(int i = 1;i<=n;i++)
    {
     int F,D;
     scanf("%d%d",&F,&D);
     for(int j = 1;j<=F;j++)
     {
      int x;
      scanf("%d",&x);
      add(x,f+i,0,1);
     }
     for(int j = 1;j<=D;j++){
      int x;
      scanf("%d",&x);
      add(f+n+d+i,f+n+x,0,1);
     }
    }
    
    for(int i = 1;i<=f;i++)
     add(s,i,0,1);
    for(int i = 1;i<=d;i++)
     add(f+n+i,t,0,1);
    for(int i = 1;i<=n;i++)
     add(f+i,f+n+d+i,0,1);
    int flow = 0;
    while(bfs())
    {
     f = dfs(0,inf);
     if(f == 0)
      break;
     flow += f;
    }
    printf("%d\n",flow);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
