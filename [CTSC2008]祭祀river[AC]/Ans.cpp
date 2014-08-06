#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#define A(x) (x*2)
#define B(x) (x*2+1)
#define gi getint()
#define rep(o,x) for(int o = 1;o<=x;o++)
#define tra(o,x) for(int o = st[x];o!=-1;o=lk[o].n)
using namespace std;
const int MAXN = 110,INF = 0x7f7f7f7f,MAXM = (110*110+110*2)*2;
int getint()
{
 char c = 0;int ret = 0;
 while(!isdigit(c))c = getchar();
 while(isdigit(c)){ret *= 10;ret += (c-'0');c = getchar();}
 return ret;
}
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);
 #endif
}
struct edge
{
 int n,v,w;
};
edge lk[MAXM];
int n,m,a[MAXN][MAXN],tot,st[MAXN*3],dis[MAXN*3],t,s=1;
void add1(int x,int y,int z)
{
 lk[tot].v = y;
 lk[tot].w = z;
 lk[tot].n = st[x];
 st[x] = tot;
 tot++;
}
void add(int x,int y,int z)
{
 add1(x,y,z);
 add1(y,x,0);
}
int bfs()
{
     queue<int> q;
     q.push(s);
     memset(dis,0x7f,sizeof(dis));
     dis[s] = 0;
     while(!q.empty())
     {
      int x = q.front();q.pop();
      tra(e,x)
      if(lk[e].w > 0 && dis[lk[e].v] > dis[x]+1)
      {
       dis[lk[e].v] = dis[x]+1;
       q.push(lk[e].v);
      }
     }
     if(dis[t] < INF)
      return 1;
     else
      return 0;
}
int dfs(int x,int y)
{
    if(x == t || y == 0)
     return y;
    int tmp = 0;
    tra(e,x)
    {
     int v = lk[e].v;
     if(dis[x]+1 != dis[v])
      continue;
     int p = dfs(v,min(y,lk[e].w));
     if(p <= 0)
      continue;
     lk[e].w -= p;
     lk[e^1].w += p;
     tmp+=p;
     y-=p;
     if(y == 0)
      break;
    }
    return tmp;
}
int main(int argc, char *argv[])
{
    memset(st,0xff,sizeof(st));
    setIO("river");
    memset(a,0x7f,sizeof(a));
    n = gi;m = gi;
    for(int i = 1;i<=m;i++)
    {
     int x=gi,y=gi;
     a[x][y] = 1;
    }
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      for(int k = 1;k<=n;k++)
       if(a[j][i]<INF && a[i][k]<INF)
        a[j][k] = min(a[j][k],a[j][i]+a[i][k]);
    for(int i = 1;i<=n;i++){
     for(int j = 1;j<=n;j++)
      if(a[i][j] < INF)
       add(A(i),B(j),1);
    }
    t = B(n)+1;
    for(int i = 1;i<=n;i++)
     add(1,A(i),1);
    for(int i = 1;i<=n;i++)
     add(B(i),t,1);
    int flow = 0;
    while(bfs())
     flow+=dfs(1,INF);
    printf("%d\n",n-flow);
    closeIO();
    return EXIT_SUCCESS;
}
