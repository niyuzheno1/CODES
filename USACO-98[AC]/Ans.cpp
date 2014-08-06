#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 500*500+10,maxk = 10010,inf = 0x7f7f7f7f;
struct link
{
 int v,u,f,n;
};
int n,k;
int st[maxn*4];
link lk[maxk*4];
int s,t,tot;
bool e[maxn*4];
int d[maxn*4];
void add1(int x,int y,int z,int f)
{
 lk[tot].v = y;
 lk[tot].n = st[x];
 lk[tot].f = f;
 lk[tot].u = z;
 st[x] = tot;
 tot++;
}
void add(int x,int y,int z,int f)
{
     add1(x,y,z,f);
     add1(y,x,-z,0);
}
bool bfs()
{
     memset(d,0x7f,sizeof(d));
     queue<int> q;
     q.push(s);d[s] = 0;
     while(!q.empty())
     {
      int x = q.front();q.pop();
      for(int i = st[x];i!=-1;i=lk[i].n)
      {
       int u = lk[i].v;
       if(d[u] > d[x]+1 && lk[i].f>0)
       {
       d[u] = d[x]+1 ;
       q.push(u);
       }
      }
     }
     return d[t]!=inf;
}
int dfs(int x,int y)
{
    if(x == t)
     return y;
    int f= 0;
    for(int i = st[x];i!=-1;i=lk[i].n)
    {
     int z = lk[i].v;
     int tmp = 0;
     if(d[z]==d[x]+1 && ((tmp=dfs(z,min(y,lk[i].f))>0)))
     {
     lk[i].f-=tmp;
     lk[i^1].f+=tmp;
     f+=tmp;
     y-=tmp;
     if(y == 0)
      break;
     }
    }
    return f;
}
int main(int argc, char *argv[])
{
    memset(st,0xff,sizeof(st));
    freopen("asteroid.in","r",stdin);
    freopen("asteroid.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=k;i++){
     int x,y;
     scanf("%d%d",&x,&y);
     y+=n;
     e[x] = e[y] =1;
     add(x,y,0,1);
    }
    s = 0,t=2*n+1;
    for(int i=1;i<=n;i++)
     if(e[i] == 1)
      add(s,i,0,1);
    for(int i=1;i<=n;i++)
     if(e[i+n] == 1)
      add(i+n,t,0,1);
    int flow = 0;
    while(bfs())
    {
     flow+=dfs(s,inf);
    }
    printf("%d\n",flow);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
